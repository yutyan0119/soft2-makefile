#include <stdio.h>
#include <stdlib.h>
#include "func.h"

double f_gradient(Location* L, const int n, Param p,
                  double (*calc)(double, double, Param)) {
  double res = 0;
  for (int i = 0; i < n; i++) {
    double x = (L + i)->altitude;
    double y = (L + i)->temperture;
    res += (*calc)(x, y, p);
  }
  return res;
}

double del_a(double x, double y, Param p) {
  double a = p.a;
  double b = p.b;
  return -2 * x * (y - a * x - b);
}

double del_b(double x, double y, Param p) {
  double a = p.a;
  double b = p.b;
  return -2 * (y - a * x - b);
}

double f_value(Location* l, const int n, Param p) {
  double sum = 0;
  double a = p.a;
  double b = p.b;
  for (int i = 0; i < n; i++) {
    double x = (l + i)->altitude;
    double y = (l + i)->temperture;
    sum += (y - a * x - b) * (y - a * x - b);
  }
  return sum;
}