#include <stdlib.h>
#include <iostream>
#include <math.h>

#define PI 3.14159265

#define H1 9
#define H2 3.2
#define H3 9
#define H4 8.5

using namespace std;

int main() {
  //Variables de entrada
  double x, y, z, alpha, alpha1;
  //Variables de slaida
  double t1, t2, t3, t4;
  //Variables temporales
  double u, u4, z4, a1, a2, a3, a4, H5, H6;

  cin >> x >> y >> z >> alpha;

  alpha1 = alpha * PI / 180.0;

  t1 = atan(y/x)*180.0 / PI;
  u = sqrt(x*x + y*y);

  z4 = z - H4*sin(alpha1);
  u4 = u - H4*cos(alpha1);

  a1 = atan(z4/u4)*180.0 / PI;
  a2 = atan(H2/H1)*180.0 / PI;
  H5 = sqrt(H1*H1 + H2*H2);
  H6 = sqrt(z4*z4 + u4*u4);

  a3 = acos(((H6*H6) - (H5*H5) - (H3*H3))/(-2*H5*H3));
  a4 = asin(H3*sin(a3)/H6)*180.0 / PI;
  //cout << a3 << a4 << '\n';

  t2 = a1 + a2 + a4 - 90;
  t3 = (a3*180.0 / PI) -90 - a2;
  t4 = alpha - t2 - t3;

  cout << t1 << " " << t2 << " " << t3 << " " << t4 << '\n';

  return 0;
}
