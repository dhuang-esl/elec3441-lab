#include <stdio.h>
#include "bfs_dataset_1000.h"

int show_result(){
    printf("graph spanningtree {\n");
    int num_unconnected_nodes = 0;
    int i;
    for(i=0; i<N; i++){
        if(parent[i]==0xDEADBEEF){
            num_unconnected_nodes++;
            printf("%d;\n", i);
        } else {
            printf("%d -- %d;\n", i, parent[i]);
        }
    }
    printf("}\n");
    return num_unconnected_nodes;
}

int queue[N];
int head=0, tail=-1;

void enqueue(int val){
    tail++;
    queue[tail] = val;
}

int dequeue(){
    int val = queue[head];
    head++;
    return val;
}

int not_empty(){
    return head <= tail;
}

void bfs(int root_vertex) {
    parent[root_vertex] = root_vertex;
    enqueue(root_vertex);

    while(not_empty()){
        int current_vertex = dequeue();
        int i;
        for(i=0; i<N; i++){
            if(adjacent[current_vertex][i] && parent[i]==0xDEADBEEF){
                parent[i] = current_vertex;
                enqueue(i);
            }
        }
    }
}

int main(){
    int unconnected_nodes = 0;
    int root_vertex = 3;
    bfs(root_vertex);
 //   unconnected_nodes = show_result();
    return unconnected_nodes;
}
