#ifndef SENSORES_H
#define SENSORES_H

#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/Pose.h>
#include <nav_msgs/OccupancyGrid.h>
#include <bits/stdc++.h>
#include "obstaculos.h"

class Sonar {
  private:
    //Medida
    float distancia;
    //std::std::vector<float> distancia;
  public:
    //Espaciales
    float theta;
    //Fuerza repulsora
    Pos fuerza;
    Pos col;
    //medir respecto a la posición
    void medir(char mapa[], geometry_msgs::Pose pose);
    void theta_i(float x);
};


#endif // SENSORES_H
