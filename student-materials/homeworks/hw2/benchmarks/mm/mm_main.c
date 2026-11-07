#include <stdio.h>
#include "mm_ip.h"

int main(){
	int i;
	int j;
	int id;


	const int a[N][N]={
    #include "in_a.txt"
	};

	const int b[N][N]={
    #include "in_b.txt"
	};

	int out[N][N];
	mm_ip(a, b, out);
	
	return 0;

}
