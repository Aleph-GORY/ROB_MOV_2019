#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <bits/stdc++.h>
#include <math.h>

#include "obstaculos.h"
#include "sensores.h"

void Sonar::medir(Mapa mapa){
  float angulo, m;
  double xn, yn;
  int l, k;

  for(int i = 0; i < 8; i++){
    theta = (M_PI/4.0)*float(i) + theta_0;
    if(theta > 2*M_PI)
      theta -= 2*M_PI;
    m = tan(theta);

    //PRIMER CUADRANTE
    if(theta < M_PI/2.0){
      l = posicion.x; k = posicion.y;

      while(k < mapa.h && l >= 0) {
        xn = (k + 1.0)*anchoCelda;
        yn = y - m*(xn - x);

        if(yn < (l + 1)*anchoCelda && yn > l*anchoCelda) {
          k++;
          if(k == mapa.h || mapa[l][k] == 1) {
            print("Ya pegó");
            return(x, y, xn, yn)
          }
        } else if (yn == l * anchoCelda) {
          k++;  l--;
          if(l < 0 || k == mapa.h || mapa[l][k] == 1) {
            print("Ya pegó");
            return(x, y, xn, yn)
          }
        } else {
          l--;
          yn = (l + 1) * anchoCelda;
          xn = (-yn - b) / m;
        }


      }
    }
  }
  /*

                    } else {
                        l--; // arriba

                        yn = (l + 1) * anchoCelda;
                        xn = (-yn - b)/m;
                        if (        if (angulo > 0) {
            if (angulo < Math.PI/2) {
                // Primer cuadrante
                int l = i, k = j;
                // arriba y a la derecha
                while(k < mapaDiscretizado[0].length && l >= 0) {
                    int[] indx = {l, k};
                    ilumina.add(indx);

                    xn = (k + 1) * anchoCelda;
                    yn = y - m * (xn - x);
                    if (yn < (l + 1) * anchoCelda && yn > l * anchoCelda) {
                        k++; // ve a la derecha
                        if (k == mapaDiscretizado[0].length || this.mapaDiscretizado[l][k] == OCUPADA) {
                            //System.out.println("Caso 1");
                            return colision(x, y, xn, yn);
                        }
                    } else if (yn == l * anchoCelda) {
                        k++; // a la derrecha
                        l--; // arriba
                        if (l < 0 || k == mapaDiscretizado[0].length || this.mapaDiscretizado[l][k] == OCUPADA) {
                            //System.out.println("Caso 2");
                            return colision(x, y, xn, yn);
                        }l < 0 || this.mapaDiscretizado[l][k] == OCUPADA) {
                            //System.out.println("Caso 3");
                            return colision(x, y, xn, yn);
                        }
                    }codigo_java
                }
            } else if (angulo <= Math.PI) {
                // Segundo cuadrante
                int l = i, k = j;
                // arriba y a la izquierda
                while(k >= 0 && l >= 0) {
                    int[] indx = {l, k};
                    ilumina.add(indx);
                    yn = l * anchoCelda;
                    xn = (-yn - b)/m;
                    if (xn > k * anchoCelda && xn < (k + 1) * anchoCelda) {
                        l--; // ve arriba
                        if (l < 0 || this.mapaDiscretizado[l][k] == OCUPADA) {
                            return colision(x, y, xn, yn);
                        }
                    } else if (xn == (k + 1) * anchoCelda) {
                        k--; // a la izquierda
                        l--; // arriba
                        if (l < 0 || k < 0 || this.mapaDiscretizado[l][k] == OCUPADA) {
                            return colision(x, y, xn, yn);
                        }
                    } else {
                        k--; // a la izquierda
                        xn = (k + 1) * anchoCelda;
                            yn = y - m * (xn - x);
                        if (k < 0 || this.mapaDiscretizado[l][k] == OCUPADA) {
                            return colision(x, y, xn, yn);
                        }
                    }
                }
            }
        } else {
            if (angulo > -Math.PI/2) {
                // Cuarto cuadrante
                int l = i, k = j;
                // abajo y a la derecha
                while(k < mapaDiscretizado[0].length && l < mapaDiscretizado.length) {
                    int[] indx = {l, k};
                    ilumina.add(indx);

                    xn = (k + 1) * anchoCelda;
                    yn = y - m * (xn - x);
                    if (yn < (l + 1) * anchoCelda && yn > l * anchoCelda) {
                        k++; // ve a la derecha
                        if (k == mapaDiscretizado[0].length || this.mapaDiscretizado[l][k] == OCUPADA) {
                            //System.out.println("Caso 1");
                            return colision(x, y, xn, yn);
                        }
                    } else if (yn == (l + 1) * anchoCelda) {
                        k++; // a la derrecha
                        l++; // abajo
                        if (l == this.mapaDiscretizado.length || k == mapaDiscretizado[0].length && this.mapaDiscretizado[l][k] == OCUPADA) {
                            //System.out.println("Caso 2");
                            return colision(x, y, xn, yn);
                        }
                    } else {
                        l++; // abajo
                        if (l == this.mapaDiscretizado.length || this.mapaDiscretizado[l][k] == OCUPADA) {
                            yn = l * anchoCelda;
                            xn = (-yn - b)/m;
                            //System.out.println("Caso 3");
                            return colision(x, y, xn, yn);
                        }
                    }
                }
            } else if (angulo > -Math.PI) {
                // Tercer cuadrante
                int l = i, k = j;
                // abajo y a la izquierda
                while(k >= 0 && l < this.mapaDiscretizado.length) {
                    int[] indx = {l, k};
                    ilumina.add(indx);
                    yn = (l + 1) * anchoCelda;
                    xn = (-yn - b)/m;codigo_java
                    if (xn > k * anchoCelda && xn < (k + 1) * anchoCelda) {
                        l++; // ve abajo
                        if (l == this.mapaDiscretizado.length || this.mapaDiscretizado[l][k] == OCUPADA) {
                            return colision(x, y, xn, yn);
                        }
                    } else if (xn == (k + 1) * anchoCelda) {
                        k--; // a la izquierda
                        l++; // ve abajo
                        if (l == this.mapaDiscretizado.length || k < 0 || this.mapaDiscretizado[l][k] == OCUPADA) {
                            return colision(x, y, xn, yn);
                        }
                    } else {
                        k--; // a la izquierda
                        if (k < 0 || this.mapaDiscretizado[l][k] == OCUPADA) {
                            xn = (k + 1) * anchoCelda;
                            yn = y - m * (xn - x);

                            return colision(x, y, xn, yn);
                        }
                    }
                }
            }
        }
        return -1;
    }
  */
}
