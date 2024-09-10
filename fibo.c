#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// divide && conquer
int dnc_fibo(int n) { // O(2^n)
  if (n <= 1)
    return n;
  return dnc_fibo(n - 1) + dnc_fibo(n - 2);
}
//  Dynamic Programming top-down
int dptd_fibo(int n, int *memo) { // O(N)
  if (n <= 1)
    return n;
  if (memo[n] != -1)
    return memo[n];
  memo[n] = dptd_fibo(n - 1, memo) + dptd_fibo(n - 2, memo);
  return memo[n];
}
// Dynamic Programming button-up
int dpbu_fibo(int n) {
  int memo[n + 1]; // space O(N)
  memo[0] = 0;
  memo[1] = 1;
  for (int i = 2; i <= n; i++) { // O(N)
    memo[i] = memo[i - 1] + memo[i - 2];
  }
  return memo[n];
}

// Dynamic Programming button-up (Optimized)
int dpbuo_fibo(int n) {
  int fnp1 = 1, fnp2 = 0, temp = 0; // space O(1)
  for (int i = 1; i < n; i++) {     // O(N)
    temp = fnp1 + fnp2;
    fnp2 = fnp1;
    fnp1 = temp;
  }
  return fnp1;
}
int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  clock_t t;
  double time_taken;
  t = clock();
  printf("Divide && Conquer: %d\n", dnc_fibo(n));
  t = clock() - t;
  time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
  printf("Divide && Conquer took %f seconds to execute \n", time_taken);
  t = clock();
  int *memo = malloc((n + 1) * sizeof(int));
  for (int i = 0; i <= n; i++)
    memo[i] = -1;

  printf("Dynamic Programming Top-Down: %d\n", dptd_fibo(n, memo));
  t = clock() - t;
  time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
  free(memo);
  printf("Dynamic Programming Top-Down took %f seconds to execute \n",
         time_taken);

  t = clock();
  printf("Dynamic Programming button-up: %d\n", dpbu_fibo(n));
  t = clock() - t;
  time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
  printf("Dynamic Programming button-up took %f seconds to execute \n",
         time_taken);

  t = clock();
  printf("Dynamic Programming button-up (Optimized): %d\n", dpbuo_fibo(n));
  t = clock() - t;
  time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
  printf(
      "Dynamic Programming button-up (Optimized) took %f seconds to execute \n",
      time_taken);

  return EXIT_SUCCESS;
}
