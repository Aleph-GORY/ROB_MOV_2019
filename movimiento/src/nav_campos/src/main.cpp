#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/OccupancyGrid.h>
#include <nav_msgs/Odometry.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

#include "obstaculos.h"
#include "sensores.h"

#define MAPH 32
#define MAPW 45
#define MAPR 0.20
#define N_SONARES 16
#define PI 3.14159265
#define FCONST 2
#define FMAX 2
#define FMIN 1.2

using namespace std;

//Var globales
char mapa[MAPH*MAPW];
geometry_msgs::Pose pose, pose_mapa;
Pos meta;
bool hay_mapa = false;

void mapaCb(const nav_msgs::OccupancyGrid::ConstPtr& msg)
{
  for(int i = 0; i< MAPH*MAPW; i++){
    mapa[i] = msg->data[i];
  }
  hay_mapa = true;
  return;
}

void posCb(const nav_msgs::Odometry::ConstPtr& msg)
{
  pose = msg->pose.pose;
  pose.position.x += 4.45;
  pose.position.y += 3.2;
  if(pose.orientation.z * pose.orientation.w > 0){
    pose.orientation.z = PI*(1.0-sqrt(1.0-abs(pose.orientation.z)));
  }
  else {
    pose.orientation.z = 2.0*PI - PI*(1.0-sqrt(1.0-abs(pose.orientation.z)));
  }

  return;
}

void metaCb(const geometry_msgs::PoseStamped::ConstPtr& msg)
{
  meta.x = msg->pose.position.x;
  meta.y = msg->pose.position.y;

  return;
}

int main( int argc, char** argv )
{
  // Crear nodo
  ros::init(argc, argv, "campos_potenciales");
  ros::NodeHandle n;
  //Suscriptor a Mapa, Posicion
  ros::Subscriber map_sub = n.subscribe("/salon_mapa", 1, mapaCb);
  ros::Subscriber pos_sub = n.subscribe("/odom", 1000, posCb);
  ros::Subscriber meta_sub = n.subscribe("/move_base_simple/goal", 1000, metaCb);
  //Publicador a Velocidad
  ros::Publisher vel_pub = n.advertise<geometry_msgs::Twist>("/mobile_base/commands/velocity", 1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("salon_marker", 1);

  //Ubicacion
  meta.x = 0.0;
  meta.y = 0.0;

  //Crear sonares e inicializarlos
  Sonar sonar[N_SONARES];
  for(int i = 0; i < N_SONARES; i++){
    sonar[i].theta = float(i)*2*PI/float(N_SONARES);
  }

  //Variables
  Pos F, cercania, vista;
  float norma;
  geometry_msgs::Twist vel;

  //inicializacion de vel y pose_mapa
  vel.linear.x = 0.0; vel.linear.y = 0.0; vel.linear.z = 0.0;
  vel.angular.x = 0.0; vel.angular.y = 0.0; vel.angular.z = 0.0;
  pose_mapa.position.x = pose_mapa.position.x = pose_mapa.position.x =
  pose_mapa.orientation.x = pose_mapa.orientation.y =
  pose_mapa.orientation.z = pose_mapa.orientation.w = 0.0;

  while (!hay_mapa) {
    ros::spinOnce();
  }
  map_sub.shutdown();

  //Campos potenciales
  while (ros::ok())
  {
    //Crear LINE_LIST
    visualization_msgs::Marker line_list, force_list;
    line_list.header.frame_id = force_list.header.frame_id = "/odom";
    line_list.header.stamp = force_list.header.stamp = ros::Time::now();
    line_list.ns = force_list.ns = "fuerzas";
    line_list.action = force_list.action = visualization_msgs::Marker::ADD;
    line_list.pose.orientation.w = force_list.pose.orientation.w = 1.0;
    line_list.id = 0; force_list.id = 1;
    line_list.type = force_list.type = visualization_msgs::Marker::LINE_LIST;
    line_list.scale.x = force_list.scale.x = 0.05;

    line_list.color.r = 1.0;
    line_list.color.a = 1.0;
    force_list.color.g = 1.0;
    force_list.color.a = 1.0;

    geometry_msgs::Point p, p0;

    //Obten pose y meta
    ros::spinOnce();
    p0.x = pose.position.x - 4.45;
    p0.y = pose.position.y - 3.2;
    p0.z = p.z = 0;
    //Calcula la pose respecto a mapa
    pose_mapa.orientation = pose.orientation;
    pose_mapa.position.x = floor((pose.position.x)/MAPR);
    pose_mapa.position.y = floor((pose.position.y)/MAPR);

    //Calcula distancia a la meta
    cercania.x = meta.x - p0.x;
    cercania.y = meta.y - p0.y;
    norma = cercania.norma();
    printf("%lf\n", norma );

    //Si aun no llegas
    if(norma > 0.07) {
      //Calcular F respecto a Meta
      F.x = F.y = 0;
      //Calcula la distancia y fuerzas repulsora
      for(int i = 0; i < N_SONARES; i++){
        line_list.points.push_back(p0);
        sonar[i].medir(mapa, pose_mapa);
        p.x = sonar[i].col.x*MAPR - 4.45;
        p.y = sonar[i].col.y*MAPR - 3.2;
        line_list.points.push_back(p);
        F.x += sonar[i].fuerza.x*MAPR;
        F.y += sonar[i].fuerza.y*MAPR;

        /*/Componentes
        p.x = sonar[i].fuerza.x*MAPR + p0.x;
        p.y = p0.y;
        line_list.points.push_back(p0);
        line_list.points.push_back(p);
        p.x = p0.x;
        p.y = sonar[i].fuerza.y*MAPR + p0.y;
        line_list.points.push_back(p0);
        line_list.points.push_back(p);
        //*/
      }

      force_list.points.push_back(p0);
      p.x = cercania.x + p0.x;  p.y = cercania.y + p0.y;
      force_list.points.push_back(p);


      if(norma > FMAX){
        cercania.x = FMAX*cercania.x/norma;
        cercania.y = FMAX*cercania.y/norma;
      }
      if(norma < FMIN){
        cercania.x = FMIN*cercania.x/norma;
        cercania.y = FMIN*cercania.y/norma;
      }

      F.x += cercania.x*FCONST;
      F.y += cercania.y*FCONST;

      force_list.points.push_back(p0);
      p.x = F.x + p0.x;  p.y = F.y + p0.y;
      force_list.points.push_back(p);


      marker_pub.publish(line_list);
      marker_pub.publish(force_list);

      //Calcular y Publicar la velocidad
      vista.x = cos(pose.orientation.z);
      vista.y = sin(pose.orientation.z);
      vel.linear.x = (vista.x*F.x + vista.y*F.y)*(0.2);
      vel.angular.z = (vista.x*F.y - vista.y*F.x)*(0.2);
      vel_pub.publish(vel);
    }
    else{
      vel.linear.x = vel.angular.z = 0.0;
      vel_pub.publish(vel);
      marker_pub.publish(line_list);
      marker_pub.publish(force_list);
    }

  }
  return 0;
}
