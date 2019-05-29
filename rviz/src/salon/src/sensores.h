#ifndef SENSORES_H
#define SENSORES_H

#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/OccupancyGrid.h>
#include <bits/stdc++.h>
#include "obstaculos.h"

class Sonar {
  private:
    //Espaciales
    Pos posicion;
    float theta_0;
    //Medidas
    float distancia[8];
    //std::std::vector<float> distancia;
  public:
    //crear los markers
    void medir(Mapa mapa);
};

#endif // SENSORES_H
