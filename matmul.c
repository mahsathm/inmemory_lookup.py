#include <stdio.h>
#include <math.h>
#define min(x, y) (((x) < (y)) ? (x) : (y))
int main(void)
{
int i, j, x, y, a[100][100], b[100], c[100];
  int n = 100;
  for (i = 0; i < n; i += 2) {
    c[i] = 0;
    c[i + 1] = 0;
    for (j = 0; j < n; j += 2) {
      for (x = i; x < min(i + 2, n); x++) {
        for (y = j; y < min(j + 2, n); y++) {
          c[x] = c[x] + a[x][y] * b[y];
        }
      }
    }
  }


  printf("%d\n", c[4]);

}
