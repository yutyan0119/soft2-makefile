#ifndef _FUNC_H_
#define _FUNC_H_

typedef struct locationdata {
  char name[100];
  double altitude;
  double temperture;
} Location;

typedef struct parameter {
  double a;
  double b;
  double alpha;
} Param;

double f_gradient(Location* L, const int n, Param p,
                  double (*calc)(double, double, Param));

double del_a(double x, double y, Param p);

double del_b(double x, double y, Param p);

double f_value(Location* l, const int n, Param p);

#endif