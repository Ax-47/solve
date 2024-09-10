#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
  int s;
  scanf("%d", &s);
  if (s >= 80)
    printf("A");
  else if (s >= 70)
    printf("B");
  else if (s >= 60)
    printf("C");
  else if (s >= 50)
    printf("D");
  else
    printf("F");

  return EXIT_SUCCESS;
}
