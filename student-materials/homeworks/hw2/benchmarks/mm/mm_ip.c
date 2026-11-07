#include "mm_ip.h"

void mm_ip(const int ina[N][N], const int inb[N][N], int out[N][N]){
	int i;
	int j;
	int k;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			out[i][j]=0;
			for(k=0; k<N; k++){
				out[i][j]+=ina[i][k]*inb[k][j];
			}
		}
	}
}
