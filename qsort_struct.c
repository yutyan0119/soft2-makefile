/*
 * 構造体配列をqsortする
 * この場合、構造体の中身を比較対象とする
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
  int id;
  char name[100];
} Student;

int comp_name(const void *x0, const void *x1) {
  const Student *p0 = (Student *)x0;
  const Student *p1 = (Student *)x1;

  // Comparison part for type Student
  // p0->name and p1->name should be evaluated
  char *c1 = (char*)p0->name;
  char *x2 = (char*)p1->name;
  while (*c1 == *x2) {
    if (*c1 == '\0') {
      return 1;
    }
    if (*x2 == '\0'){
        return -1;
    }
    c1++;
    x2++;
  }
  return (*x2 - *c1 < 0) ? 1 : -1;
}

int main(int argc, char **argv) {
  Student v[] = {
      (Student){.id = 1, .name = "situ"}, (Student){.id = 2, .name = "hrs"},
      (Student){.id = 3, .name = "ire"},  (Student){.id = 4, .name = "hsgw"},
      (Student){.id = 5, .name = "aizw"}, (Student){.id = 6, .name = "mti"}};
  const int n = sizeof(v) / sizeof(v[0]);

  // before sort
  printf("== before ==\n");
  for (int i = 0; i < n; i++) {
    printf("%d: v[%d] = %s\n", v[i].id, i, v[i].name);
  }
  qsort(v, n, sizeof(v[0]), comp_name);

  // after qsort
  printf("== after ==\n");
  for (int i = 0; i < n; i++) {
    printf("%d: v[%d] = %s\n", v[i].id, i, v[i].name);
  }
  return EXIT_SUCCESS;
}
