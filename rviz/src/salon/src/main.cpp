#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/OccupancyGrid.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

#include "obstaculos.h"

#define MAPH 32
#define MAPW 45
#define MAPR 0.20

using namespace std;

int main( int argc, char** argv )
{
  // Crear nodo
  ros::init(argc, argv, "salon");
  ros::NodeHandle n;
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("salon_marker", 1);
  ros::Publisher map_pub = n.advertise<nav_msgs::OccupancyGrid>("salon_mapa", 1);

  // Variables del salon
  Salon salon;    Mapa mapa;
  int n_mesas = 11;
  Mesa mesa[n_mesas];  Silla silla[n_mesas][2];
  Pos pos_mapa, pos_mesa[n_mesas], pos_silla[n_mesas][2];
  char vec_mapa[MAPH*MAPW];
  for(int i = 0; i < MAPH*MAPW; i++)
    vec_mapa[i] = 0;

  salon.construir(8.9, 6.4);
  salon.llena_mapa(vec_mapa, MAPR);
  pos_mapa.x = -4.45; pos_mapa.y = -3.2;
  mapa.construir(MAPW, MAPH, MAPR, pos_mapa);

  ifstream fe("base.txt");

  //* Crear obstaculos
  for(int i = 0; i < n_mesas; i++){
    //lee el archivo
    fe >> pos_mesa[i].x >> pos_mesa[i].y;
    pos_silla[i][0].x = pos_silla[i][1].x = pos_mesa[i].x - 0.45;
    pos_silla[i][0].y = pos_mesa[i].y - 0.4;
    pos_silla[i][1].y = pos_mesa[i].y + 0.4;
    mesa[i].construir_pos(pos_mesa[i]);
    mesa[i].llena_mapa(vec_mapa, MAPR);
    //silla[i][0].construir_pos(pos_silla[i][0]);
    //silla[i][1].construir_pos(pos_silla[i][1]);
  }//*/

  mapa.actualizar(vec_mapa);
  bool elmapaestapublicado = false;

  // Dibujar el salon
  while (ros::ok())
  {
    while (marker_pub.getNumSubscribers() < 1) {
      if (!ros::ok())
        return 0;
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }

    salon.dibujar(marker_pub);

    for (int i = 0; i < n_mesas; i++) {
      mesa[i].dibujar(marker_pub);
      //silla[i][0].dibujar(marker_pub);
      //silla[i][1].dibujar(marker_pub);
    }
    //if(!elmapaestapublicado){
      mapa.dibujar(map_pub);
      elmapaestapublicado = true;
    //}

  }

  return 0;
}
