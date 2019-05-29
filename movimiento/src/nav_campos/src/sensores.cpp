#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/Pose.h>
#include <bits/stdc++.h>
#include <math.h>

#include "obstaculos.h"
#include "sensores.h"

#define MAPH 32
#define MAPW 45
#define MAPR 0.20
#define N_SONARES 8
#define PI 3.14159265
#define LCONST 2

void Sonar::medir(char mapa[], geometry_msgs::Pose pose){
  float angulo, angulo2, m;
  Pos celda, celda_colision;
  int entrada;
  bool colision = false;

  //angulo respecto al mundo
  angulo = theta + pose.orientation.z;
  if(angulo >= 2*PI){
    angulo -= 2*PI;
  }
  //Temporales
  float x_i, x_2i, y_i, y_2i, b;

  //Ecuacion de la recta y casos especiales
  int r1, r2;
  r1 = r2 = 1;
  angulo2 = angulo;

  if(angulo2 == PI/2.0 || angulo2 == 3.0*PI/2.0){
    angulo2 = angulo2 + 0.01;
  }
  if(angulo2 > PI/2.0 && angulo2 <= PI){
    r1 = -1; r2 = 1;
    angulo2 = PI - angulo2;
  }
  if(angulo2 > PI && angulo2 < 3.0*PI/2.0){
    r1 = -1; r2 = -1;
    angulo2 = angulo2 - PI;
  }
  if(angulo2 > 3.0*PI/2.0 && angulo2 <= 2.0*PI){
    r1 = 1; r2 = -1;
    angulo2 = 2.0*PI - angulo2;
  }

  //Checar cuadrante
  m = tan(angulo2);
  b = (1-m)/2.0;
  x_i = 0; y_i = b;
  while (!colision) {
    x_2i = x_i + 1;
    y_2i = m*x_2i + b;
    celda.x = x_i;
    celda.y = floor(y_i);
    for(int i = 0; i <= ceil(y_2i) - celda.y; i++){
      if(r2*(celda.y + i) + pose.position.y < MAPH && r2*(celda.y + i) + pose.position.y >= 0){
        int j = (r1*celda.x + pose.position.x) + (r2*(celda.y + i) + pose.position.y)*(MAPW);
        if(mapa[j] != 0 && !colision){
          celda_colision.x = celda.x + r1*0.5;
          celda_colision.y = celda.y + float(i) + r2*0.5;
          col.x = r1*celda_colision.x + pose.position.x;
          col.y = r2*celda_colision.y + pose.position.y;
          colision = true;
        }
      }
    }
    x_i = x_2i; y_i = y_2i;
  }

  //Calcular distancia a obstáculo
  distancia = MAPR*sqrt((celda_colision.x - r1*0.5)*(celda_colision.x - r1*0.5) +
   (celda_colision.y - r2*0.5)*(celda_colision.y - r2*0.5));

  //Calcular fuerza repulsora
  fuerza.x = -(LCONST/(distancia -0.1))*cos(angulo);
  fuerza.y = -(LCONST/(distancia -0.1))*sin(angulo);
  return;
}

void Sonar::theta_i(float x){
  theta = x;
}
