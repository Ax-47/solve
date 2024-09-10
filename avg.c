#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
  int sum = 0;
  int a, b = 1, count = 0;
  while (b == 1) {
    printf("Input Number (press A for calculate avg): ");
    b = scanf("%d", &a);
    if (b != 1) {
      break;
    }
    sum += a;
    count++;
  }
  if (count == 0) {
    printf("error\n");
    return EXIT_FAILURE;
  }
  printf("avg: %.21f\n", (float)sum / count);
  return EXIT_SUCCESS;
}
