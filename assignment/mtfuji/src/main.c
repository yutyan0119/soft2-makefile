#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "func.h"

int main() {
  FILE *fp;
  fp = fopen("src/data.csv", "r");
  if (fp == NULL) {
    printf("file dose not found\n");
    return EXIT_FAILURE;
  }
  Param p = {.a = 1, .alpha = 0.01, .b = 0};
  size_t maxnum = 100;
  Location L[maxnum];
  int n = 0;
  char buf[maxnum];
  while (fgets(buf, maxnum, fp) && n < maxnum) {
    char *name;
    char *p;
    buf[strlen(buf) - 1] = 0;
    name = strtok(buf, ",");
    p = strtok(NULL, ",");
    double altitude = atof(p);
    p = strtok(NULL, "\0");
    double temperature = atof(p);
    L[n] = (Location){
        .altitude = altitude, .temperture = temperature};
    strcpy(L[n].name,name); 
    n++;
  }
  double norm = 1000;
  int step = 0;
  while ( norm > 0.001 && step < 10000)
  {     
    //   printf("value = %f\n",value);
      double dela = f_gradient(L,n,p,del_a);
      // printf("%f\n",dela);
      double delb = f_gradient(L,n,p,del_b);
      // printf("%f\n",delb);
      norm = sqrt(dela*dela + delb*delb);
      p.a -= p.alpha*dela;
      p.b -= p.alpha*delb;
    //   printf("a = %f, b = %f\n",p.a,p.b);
      step++;
  }
  printf("富士山の予想平均気温は%2.3f度です。\n",p.a*3.776+p.b);
  return 0;
}