#ifndef OBSTACULOS_H
#define OBSTACULOS_H

#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/OccupancyGrid.h>
#include <bits/stdc++.h>

struct Pos {
  float x, y;
  Pos();
};

struct Salon {
  visualization_msgs::Marker paredD, paredI, paredF, paredR, pilar;
  void construir(float h, float w);
  void llena_mapa(char vec_mapa[], float res);
  void dibujar(ros::Publisher marker_pub);
};

struct Mapa {
  Pos posicion;
  nav_msgs::OccupancyGrid mapa;
  void construir(int w, int h, float res, Pos p);
  void actualizar(char vec_mapa[]);
  void dibujar(ros::Publisher map_pub);
};

class Mesa {
  private:
    //Espaciales
    Pos posicion;
    //Pedazos
    visualization_msgs::Marker lateralD, lateralI, frontal, superior;
  public:
    //crear los markers
    void construir(float x, float y);
    void construir_pos(Pos p);
    //llenar mapa
    void llena_mapa(char vec_mapa[], float res);
    //imprime la mesa
    void dibujar(ros::Publisher marker_pub);
};

class Silla {
  private:
    //Espaciales
    Pos posicion;
    //Pedazos
    visualization_msgs::Marker pata1, pata2, pata3, pata4, asiento, respaldo;
  public:
    //crear los markers
    void construir(float x, float y);
    void construir_pos(Pos p);
    //llenar mapa
    void llena_mapa(char vec_mapa[], float res);
    //imprime la mesa
    void dibujar(ros::Publisher marker_pub);
};

#endif // OBSTACULOS_H
