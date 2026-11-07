#include <stdio.h>

#define N 100 
#define R 2


void conv2D(
	const int in[N][N],
	const int kernel[2*R+1][2*R+1],
	int out[N][N]
)
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++){
            int sum = 0;

            for (int i = -R; i <= R; i++)
            {
                for (int j = -R; j <= R; j++)
                {
                    int ii = x + i;
                    int jj = y + j;

                    if (ii >= 0 && ii < N && jj >= 0 && jj < N){
                        sum += in[ii][jj] * kernel[R - i][R - j];
                    }
                }
            }
            out[x][y] = sum;
        }
    }

}


int main(){

        const int a[N][N]={
    #include "in.txt"
        };

        const int k[2*R+1][2*R+1]={
    #include "kernel.txt"
        };

        int out[N][N];
        conv2D(a, k, out);
        
        return 0;

}

