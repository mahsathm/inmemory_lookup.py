#include <stdio.h>
#include <math.h>
#define min(x, y) (((x) < (y)) ? (x) : (y))
int main(void)
{

int ib=20, kb=64; //according to system spec
int acc00,acc01,acc10,acc11;
int i,j,k,ii,kk,A[100][100], B[100][50],C[100][50];
int N = 100;
for (ii = 0; ii < N; ii += ib)
{
    for (kk = 0; kk < N; kk += kb)
    {
        for (j=0; j < N; j += 2)
        {
            for (i = ii; i < ii + ib; i += 2)
            {
                if (kk == 0)
                    acc00 = acc01 = acc10 = acc11 = 0;
                else
                {
                    acc00 = C[i + 0][j + 0];
                    acc01 = C[i + 0][j + 1];
                    acc10 = C[i + 1][j + 0];
                    acc11 = C[i + 1][j + 1];
                }
                for (k = kk; k < kk + kb; k++)
                {
                    acc00 += B[k][j + 0] * A[i + 0][k];
	                acc01 += B[k][j + 1] * A[i + 0][k];
	                acc10 += B[k][j + 0] * A[i + 1][k];
	                acc11 += B[k][j + 1] * A[i + 1][k];
                }
                C[i + 0][j + 0] = acc00;
                C[i + 0][j + 1] = acc01;
                C[i + 1][j + 0] = acc10;
                C[i + 1][j + 1] = acc11;
            }
        }
    }
}
  printf("%d\n", C[1][1]);

}
