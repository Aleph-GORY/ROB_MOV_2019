#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <bits/stdc++.h>

//using namespace std;

class Mesa {
  private:
    // Espaciales
    float px, py;
    //Pedazos
    visualization_msgs::Marker lateralD, lateralI, frontal, superior;
  public:
    //crar los markers
    void construir(float x, float y);
    //imprime la mesa
    void dibujar(ros::Publisher marker_pub);
};

void Mesa::construir(float x, float y) {
  px = x;  py = y;
  //inicializacion de pedazos
  lateralD.header.frame_id =lateralI.header.frame_id = frontal.header.frame_id = superior.header.frame_id = "/my_frame";
  lateralD.header.stamp = lateralI.header.stamp = frontal.header.stamp = superior.header.stamp = ros::Time::now();
  std::string id = "mesa_" + std::to_string(px) + "_" + std::to_string(py);
  std::cout << id << '\n';
  lateralD.ns = lateralI.ns = frontal.ns = superior.ns = id;
  lateralD.id = 0; lateralI.id = 1; frontal.id = 2; superior.id = 3;
  lateralD.type = lateralI.type = frontal.type = superior.type = visualization_msgs::Marker::CUBE;
  lateralD.action = lateralI.action = frontal.action = superior.action = visualization_msgs::Marker::ADD;

  //dimensiones
  lateralD.scale.x = lateralI.scale.x = 0.8;
  lateralD.scale.y = lateralI.scale.y = 0.04;
  lateralD.scale.z = lateralI.scale.z = 0.8;
  superior.scale.x = 0.8;
  superior.scale.y = 1.6;
  superior.scale.z = 0.04;
  frontal.scale.x = 0.04;
  frontal.scale.y = 1.6;
  frontal.scale.z = 0.8;
  //posiciones
  lateralD.pose.position.x = px; lateralD.pose.position.y = py + 0.8; lateralD.pose.position.z = 0.4;
  lateralI.pose.position.x = px; lateralI.pose.position.y = py - 0.8; lateralI.pose.position.z = 0.4;
  frontal.pose.position.x = px - 0.4; frontal.pose.position.y = py; frontal.pose.position.z = 0.4;
  superior.pose.position.x = px; superior.pose.position.y = py; superior.pose.position.z = 0.8;

  lateralD.pose.orientation.x = lateralD.pose.orientation.y = lateralD.pose.orientation.z =
  lateralI.pose.orientation.x = lateralI.pose.orientation.y = lateralI.pose.orientation.z =
  frontal.pose.orientation.x = frontal.pose.orientation.y = frontal.pose.orientation.z =
  superior.pose.orientation.x = superior.pose.orientation.y = superior.pose.orientation.z = 0.0;

  lateralD.pose.orientation.w = lateralI.pose.orientation.w =
  frontal.pose.orientation.w = superior.pose.orientation.w = 1.0;

  // Color
  //cafe
  lateralD.color.r = lateralI.color.r = frontal.color.r = 0.62f;
  lateralD.color.g = lateralI.color.g = frontal.color.g = 0.4f;
  lateralD.color.b = lateralI.color.b = frontal.color.b = 0.18f;
  lateralD.color.a = lateralI.color.a = frontal.color.a = 1.0;
  //balnco
  superior.color.r = 1.0f;
  superior.color.g = 1.0f;
  superior.color.b = 0.8f;
  superior.color.a = 1.0f;
}

void Mesa::dibujar(ros::Publisher marker_pub) {
  lateralD.lifetime = lateralI.lifetime = frontal.lifetime = superior.lifetime = ros::Duration();
  marker_pub.publish(lateralD); marker_pub.publish(lateralI);
  marker_pub.publish(frontal); marker_pub.publish(superior);
}

int main( int argc, char** argv )
{

  ros::init(argc, argv, "mesa");
  ros::NodeHandle n;
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("mesas_marker", 1);

  int n1 = 5;
  Mesa mesa[n1];
  float coord[n1][2];

  coord[0][0] = 0.0; coord[0][1] = 0.0;
  coord[1][0] = 3.0; coord[1][1] = 0.0;
  coord[2][0] = 0.0; coord[2][1] = 3.0;
  coord[3][0] = 3.0; coord[3][1] = 3.0;
  coord[4][0] = 0.0; coord[4][1] = -3.0;

  // crear las mesas
  for(int i = 0; i < n1; i++){
    mesa[i].construir(coord[i][0], coord[i][1]);
  }

  while (ros::ok())
  {
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }

    // dibujar las mesas
    for(int i = 0; i < n1; i++){
      mesa[i].dibujar(marker_pub);
    }
  }
  return 0;
}
