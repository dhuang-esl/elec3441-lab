// loop2.c
#define N 5
void loop2(const int a[], const int b[], int c[], int d[]){
    for(int i=0; i<N; i++){
        c[i] = a[i] + b[i];
        d[i] = a[i] - b[i];
    }
}
