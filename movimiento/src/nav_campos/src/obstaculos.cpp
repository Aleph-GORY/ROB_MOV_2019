#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <bits/stdc++.h>
#include <math.h>

#include "obstaculos.h"

std::string frame = "/my_frame";

//POS
Pos::Pos(){
  x = y = 0.0;
}

float Pos::norma(){
  return sqrt(x*x + y*y);
}

//SALON
void Salon::construir(float h, float w) {
  //inicializacion de pedazos
  paredD.header.frame_id = paredI.header.frame_id = paredF.header.frame_id =
  paredR.header.frame_id = pilar.header.frame_id = frame;
  paredD.header.stamp = paredI.header.stamp = paredF.header.stamp =
  paredR.header.stamp = pilar.header.stamp = ros::Time::now();
  std::string id = "salon_" + std::to_string(h) + "_" + std::to_string(w);
  std::cout << id << '\n';
  paredD.ns = paredI.ns = paredF.ns = paredR.ns = pilar.ns = id;
  paredD.id = 0; paredI.id = 1; paredF.id = 2; paredR.id = 3; pilar.id = 4;
  paredD.type = paredI.type = paredF.type = paredR.type =  pilar.type = visualization_msgs::Marker::CUBE;
  paredD.action = paredI.action = paredF.action = paredR.action = pilar.action = visualization_msgs::Marker::ADD;

  //dimensiones
  paredD.scale.x = paredI.scale.x = h; paredD.scale.y = paredI.scale.y = 0.08;
  paredD.scale.z = paredI.scale.z = 3; paredF.scale.x = paredR.scale.x = 0.08;
  pilar.scale.x = pilar.scale.y = 0.8;
  paredF.scale.y = paredR.scale.y = w; paredF.scale.z =
  paredR.scale.z = pilar.scale.z = 3;
  //posiciones
  paredD.pose.position.x = paredI.pose.position.x = 0.0;
  paredD.pose.position.y = -(w/2.0); paredI.pose.position.y = (w/2.0);
  paredD.pose.position.z = paredI.pose.position.z = paredD.scale.z/2.0;

  paredF.pose.position.x = (h/2.0); paredR.pose.position.x = -(h/2.0);
  paredF.pose.position.y = paredR.pose.position.y = 0.0;
  paredF.pose.position.z = paredR.pose.position.z = paredF.scale.z/2.0;

  pilar.pose.position.x = 4.05; pilar.pose.position.y = 2.8; pilar.pose.position.z = paredF.scale.z/2.0;
  //orientaciones
  paredD.pose.orientation.x = paredD.pose.orientation.y = paredD.pose.orientation.z =
  paredI.pose.orientation.x = paredI.pose.orientation.y = paredI.pose.orientation.z =
  paredF.pose.orientation.x = paredF.pose.orientation.y = paredF.pose.orientation.z =
  paredR.pose.orientation.x = paredR.pose.orientation.y = paredR.pose.orientation.z =
  pilar.pose.orientation.x = pilar.pose.orientation.y = pilar.pose.orientation.z = 0.0;
  paredD.pose.orientation.w = paredI.pose.orientation.w = paredF.pose.orientation.w =
  paredR.pose.orientation.w = pilar.pose.orientation.w = 1.0;

  //color
  paredD.color.r = paredI.color.r = paredF.color.r = paredR.color.r = pilar.color.r = 1.0;
  paredD.color.g = paredI.color.g = paredF.color.g = paredR.color.g = pilar.color.g = 1.0;
  paredD.color.b = paredI.color.b = paredF.color.b = paredR.color.b = pilar.color.b = 0.6;
  paredD.color.a = paredI.color.a = paredF.color.a = paredR.color.a = pilar.color.a = 1.0;
}

void Salon::llena_mapa(char mapa[], float res) {
  for(int a = 0; a < 2; a++){
    for(int i = 0; i< 45; i++){
      mapa[i + 45*31*a] = 100;
    }
  }

  for(int a = 0; a < 2; a++){
    for(int i = 0; i< 32; i++){
      mapa[i*45 + 44*a] = 100;
    }
  }
}

void Salon::dibujar(ros::Publisher marker_pub) {
  paredD.lifetime = paredI.lifetime = paredF.lifetime =
  paredR.lifetime = pilar.lifetime = ros::Duration();
  marker_pub.publish(paredD); marker_pub.publish(paredI);
  marker_pub.publish(paredF); marker_pub.publish(paredR);
  marker_pub.publish(pilar);
}

//MAPA

void Mapa::construir(int w, int h, float res, Pos p) {
  mapa.header.frame_id = frame; mapa.header.stamp = ros::Time::now();
  mapa.info.map_load_time = ros::Time::now(); mapa.info.resolution = res;
  mapa.info.width = w;  mapa.info.height = h;
  mapa.info.origin.position.x = posicion.x = p.x;
  mapa.info.origin.position.y = posicion.y = p.y;
  mapa.info.origin.position.z = 0.0;
  mapa.info.origin.orientation.x = mapa.info.origin.orientation.y = mapa.info.origin.orientation.z =  0.0;
  mapa.info.origin.orientation.w = 1.0;
}

void Mapa::actualizar(char vec_mapa[]) {
  int x = mapa.info.width*mapa.info.height;
  mapa.data = std::vector<int8_t>(vec_mapa, vec_mapa + x);
}

void Mapa::dibujar(ros::Publisher map_pub) {
  map_pub.publish(mapa);
}

//MESA

void Mesa::construir(float x, float y) {
  posicion.x = x;  posicion.y = y;
  //inicializacion de pedazos
  lateralD.header.frame_id =lateralI.header.frame_id = frontal.header.frame_id =
  superior.header.frame_id = frame;
  lateralD.header.stamp = lateralI.header.stamp = frontal.header.stamp = superior.header.stamp = ros::Time::now();
  std::string id = "mesa_" + std::to_string(x) + "_" + std::to_string(y);
  std::cout << id << '\n';
  lateralD.ns = lateralI.ns = frontal.ns = superior.ns = id;
  lateralD.id = 0; lateralI.id = 1; frontal.id = 2; superior.id = 3;
  lateralD.type = lateralI.type = frontal.type = superior.type = visualization_msgs::Marker::CUBE;
  lateralD.action = lateralI.action = frontal.action = superior.action = visualization_msgs::Marker::ADD;

  //dimensiones
  lateralD.scale.x = lateralI.scale.x = 0.7;
  lateralD.scale.y = lateralI.scale.y = 0.04;
  lateralD.scale.z = lateralI.scale.z = 0.8;
  superior.scale.x = 0.7; superior.scale.y = 1.6; superior.scale.z = 0.04;
  frontal.scale.x = 0.04; frontal.scale.y = 1.6; frontal.scale.z = 0.6;
  //posiciones
  lateralD.pose.position.x = x; lateralD.pose.position.y = y + 0.8; lateralD.pose.position.z = 0.4;
  lateralI.pose.position.x = x; lateralI.pose.position.y = y - 0.8; lateralI.pose.position.z = 0.4;
  frontal.pose.position.x = x + 0.35; frontal.pose.position.y = y; frontal.pose.position.z = 0.5;
  superior.pose.position.x = x; superior.pose.position.y = y; superior.pose.position.z = 0.8;
  //orientaciones
  lateralD.pose.orientation.x = lateralD.pose.orientation.y = lateralD.pose.orientation.z =
  lateralI.pose.orientation.x = lateralI.pose.orientation.y = lateralI.pose.orientation.z =
  frontal.pose.orientation.x = frontal.pose.orientation.y = frontal.pose.orientation.z =
  superior.pose.orientation.x = superior.pose.orientation.y = superior.pose.orientation.z = 0.0;
  lateralD.pose.orientation.w = lateralI.pose.orientation.w =
  frontal.pose.orientation.w = superior.pose.orientation.w = 1.0;

  //color
  //cafe
  lateralD.color.r = lateralI.color.r = frontal.color.r = 0.62f;
  lateralD.color.g = lateralI.color.g = frontal.color.g = 0.4f;
  lateralD.color.b = lateralI.color.b = frontal.color.b = 0.18f;
  lateralD.color.a = lateralI.color.a = frontal.color.a = 1.0;
  //balnco
  superior.color.r = 1.0f; superior.color.g = 1.0f;
  superior.color.b = 0.8f; superior.color.a = 1.0f;
}

void Mesa::construir_pos(Pos p) {
  construir(p.x, p.y);
}

void Mesa::llena_mapa(char mapa[], float res) {
  Pos pos_rel;
  float e1, e2, f1, f2;
  //coordenadas relativas a la esquina
  pos_rel.x = posicion.x + 4.45;
  pos_rel.y = posicion.y + 3.2;

  //algoritmo de llenado
  e1 = pos_rel.y + 0.82; e2 = pos_rel.y - 0.82;
  f1 = pos_rel.x + 0.37; f2 = pos_rel.x + 0.33;
  e1 = floor(e1/res); e2 = floor(e2/res);
  f1 = floor(f1/res); f2 = floor(f2/res);
  for(int i = int(e2); i <= int(e1); i++){
    for(int j = int(f2); j <= int(f1); j++){
      mapa[i*45 + j] = 100;
    }
  }

  e1 = pos_rel.y + 0.82; e2 = pos_rel.y + 0.78;
  f1 = pos_rel.x + 0.35; f2 = pos_rel.x - 0.35;
  e1 = floor(e1/res); e2 = floor(e2/res);
  f1 = floor(f1/res); f2 = floor(f2/res);
  for(int i = int(e2); i <= int(e1); i++){
    for(int j = int(f2); j <= int(f1); j++){
      mapa[i*45 + j] = 100;
    }
  }

  e1 = pos_rel.y - 0.78; e2 = pos_rel.y - 0.82;
  f1 = pos_rel.x + 0.35; f2 = pos_rel.x - 0.35;
  e1 = floor(e1/res); e2 = floor(e2/res);
  f1 = floor(f1/res); f2 = floor(f2/res);
  for(int i = int(e2); i <= int(e1); i++){
    for(int j = int(f2); j <= int(f1); j++){
      mapa[i*45 + j] = 100;
    }
  }//*/
}

void Mesa::dibujar(ros::Publisher marker_pub) {
  lateralD.lifetime = lateralI.lifetime = frontal.lifetime = superior.lifetime = ros::Duration();
  marker_pub.publish(lateralD); marker_pub.publish(lateralI);
  marker_pub.publish(frontal); marker_pub.publish(superior);
}

//SILLA

void Silla::construir(float x, float y) {
  posicion.x = x;  posicion.y = y;
  //inicializacion de pedazos
  pata1.header.frame_id = pata2.header.frame_id = pata3.header.frame_id =
  pata4.header.frame_id = asiento.header.frame_id = respaldo.header.frame_id = frame;
  pata1.header.stamp = pata2.header.stamp = pata3.header.stamp = pata4.header.stamp =
  asiento.header.stamp = respaldo.header.stamp =  ros::Time::now();
  std::string id = "silla_" + std::to_string(x) + "_" + std::to_string(y);
  std::cout << id << '\n';
  pata1.ns = pata2.ns = pata3.ns = pata4.ns = asiento.ns = respaldo.ns = id;
  pata1.id = 0; pata2.id = 1; pata3.id = 2; pata4.id = 4; asiento.id = 5; respaldo.id = 6;
  pata1.type = pata2.type = pata3.type = pata4.type = visualization_msgs::Marker::CYLINDER;
  asiento.type = respaldo.type = visualization_msgs::Marker::CUBE;
  pata1.action = pata2.action = pata3.action = pata4.action =
  asiento.action = respaldo.action = visualization_msgs::Marker::ADD;

  // dimensiones
  pata1.scale.x = pata2.scale.x = pata3.scale.x = pata4.scale.x =
  pata1.scale.y = pata2.scale.y = pata3.scale.y = pata4.scale.y = 0.1;
  pata1.scale.z = pata2.scale.z = pata3.scale.z = pata4.scale.z = 0.55;
  asiento.scale.x = 0.6; asiento.scale.y = 0.5; asiento.scale.z = 0.06;
  respaldo.scale.x = 0.05; respaldo.scale.y = 0.4; respaldo.scale.z = 0.6;
  //posiciones
  pata1.pose.position.x = x - 0.25; pata1.pose.position.y = y + 0.2; pata1.pose.position.z = 0.2;
  pata2.pose.position.x = x - 0.25; pata2.pose.position.y = y - 0.2; pata2.pose.position.z = 0.2;
  pata3.pose.position.x = x + 0.25; pata3.pose.position.y = y + 0.2; pata3.pose.position.z = 0.2;
  pata4.pose.position.x = x + 0.25; pata4.pose.position.y = y - 0.2; pata4.pose.position.z = 0.2;
  asiento.pose.position.x = x; asiento.pose.position.y = y; asiento.pose.position.z = 0.45;
  respaldo.pose.position.x = x - 0.25; respaldo.pose.position.y = y; respaldo.pose.position.z = 0.75;
  //orientaciones
  pata1.pose.orientation.x = 0.3; pata1.pose.orientation.y = 0.7;
  pata1.pose.orientation.z = 0.0; pata1.pose.orientation.w = 4.7;
  pata2.pose.orientation.x = -0.3; pata2.pose.orientation.y = 0.7;
  pata2.pose.orientation.z = 0.0; pata2.pose.orientation.w = 4.7;
  pata3.pose.orientation.x = 0.3; pata3.pose.orientation.y = -0.7;
  pata3.pose.orientation.z = 0.0; pata3.pose.orientation.w = 4.7;
  pata4.pose.orientation.x = -0.3; pata4.pose.orientation.y = -0.7;
  pata4.pose.orientation.z = 0.0; pata4.pose.orientation.w = 4.7;
  asiento.pose.orientation.x = asiento.pose.orientation.y = asiento.pose.orientation.z =
  respaldo.pose.orientation.x = respaldo.pose.orientation.y = respaldo.pose.orientation.z = 0.0;
  respaldo.pose.orientation.w = asiento.pose.orientation.w = 1.0;

  //color
  //cafe
  pata1.color.r = pata2.color.r = pata3.color.r = pata4.color.r = 0.0f;
  pata1.color.g = pata2.color.g = pata3.color.g = pata4.color.g = 0.0f;
  pata1.color.b = pata2.color.b = pata3.color.b = pata4.color.b = 0.0f;
  pata1.color.a = pata2.color.a = pata3.color.a = pata4.color.a = 1.0f;
  //verde
  asiento.color.r = respaldo.color.r = 1.0f;
  asiento.color.g = respaldo.color.g = 0.47f;
  asiento.color.b = respaldo.color.b = 0.2f;
  asiento.color.a = respaldo.color.a = 1.0;
}

void Silla::construir_pos(Pos p) {
  construir(p.x, p.y);
}

void Silla::llena_mapa(char mapa[], float res) {
  Pos pos_rel;
  float e1, e2, f1, f2;
  //coordenadas relativas a la esquina
  pos_rel.x = posicion.x + 4.45;
  pos_rel.y = posicion.y + 3.2;

  //algoritmo de llenado
  e1 = pos_rel.y + 0.82; e2 = pos_rel.y - 0.82;
  f1 = pos_rel.x + 0.37; f2 = pos_rel.x + 0.33;
  e1 = floor(e1/res); e2 = floor(e2/res);
  f1 = floor(f1/res); f2 = floor(f2/res);
  for(int i = int(e2); i <= int(e1); i++){
    for(int j = int(f2); j <= int(f1); j++){
      mapa[i*45 + j] = 100;
    }
  }

  e1 = pos_rel.y + 0.82; e2 = pos_rel.y + 0.78;
  f1 = pos_rel.x + 0.35; f2 = pos_rel.x - 0.35;
  e1 = floor(e1/res); e2 = floor(e2/res);
  f1 = floor(f1/res); f2 = floor(f2/res);
  for(int i = int(e2); i <= int(e1); i++){
    for(int j = int(f2); j <= int(f1); j++){
      mapa[i*45 + j] = 100;
    }
  }

  e1 = pos_rel.y - 0.78; e2 = pos_rel.y - 0.82;
  e1 = floor(e1/res); e2 = floor(e2/res);
  f1 = floor(f1/res); f2 = floor(f2/res);
  for(int i = int(e2); i <= int(e1); i++){
    for(int j = int(f2); j <= int(f1); j++){
      mapa[i*45 + j] = 100;
    }
  }//*/
}

void Silla::dibujar(ros::Publisher marker_pub) {
  pata1.lifetime = pata2.lifetime = pata3.lifetime = pata4.lifetime =
  asiento.lifetime = respaldo.lifetime = ros::Duration();
  marker_pub.publish(pata1); marker_pub.publish(pata2); marker_pub.publish(pata3);
  marker_pub.publish(pata4); marker_pub.publish(asiento); marker_pub.publish(respaldo);
}

//FLECHA

void Flecha::construir(float x1, float x2, float y1, float y2) {
  posicion1.x = x1;  posicion1.y = x2;
  posicion2.x = y1;  posicion2.y = y2;
  //inicializacion de pedazos
  flecha.header.frame_id = frame;
  flecha.header.stamp = ros::Time::now();
  std::string id = "flecha_" + std::to_string(x1) + "_" + std::to_string(x2)
  + "_" + std::to_string(y1)+ "_" + std::to_string(y2);
  flecha.ns = id; flecha.id = 0; flecha.type = visualization_msgs::Marker::ARROW;
  flecha.action = visualization_msgs::Marker::ADD;

  //color
  //verde
  flecha.color.r = 1.0f;
  flecha.color.g = 0.47f;
  flecha.color.b = 0.2f;
  flecha.color.a = 1.0;
}

void Flecha::construir_pos(Pos p1, Pos p2) {
  construir(p1.x, p1.y, p2.x, p2.y);
}

void Flecha::dibujar(ros::Publisher marker_pub) {
  flecha.lifetime = ros::Duration();
  marker_pub.publish(flecha);
}
