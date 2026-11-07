#include <stdio.h>
#include "bfs.h"
#include "bfs_dataset_1000.h"

Node* queue[N];
int head=0, tail=-1;


int show_result(){
    printf("graph spanningtree {\n");
    int num_unconnected_nodes = 0;
    int i;
    for(i=0; i<N; i++){
        if(!nodes[i].parent){
            num_unconnected_nodes++;
            printf("%d;\n", nodes[i].id);
        } else {
            printf("%d -- %d;\n", nodes[i].id, nodes[i].parent->id);
        }
    }
    printf("}\n");
    return num_unconnected_nodes;
}

void enqueue(Node* val){
    tail++;
    queue[tail] = val;
}

Node* dequeue(){
    Node* val = queue[head];
    head++;
    return val;
}

int not_empty(){
    return head <= tail;
}

void bfs(Node* root_vertex) {
    root_vertex->parent = root_vertex;
    enqueue(root_vertex);

    while(not_empty()){
        Node* current_vertex = dequeue();
        int i;
        for(i=0; i<MAX_ARITY; i++){
            Node* neighbor = current_vertex->neighbors[i];
            if(neighbor && !neighbor->parent){
                neighbor->parent = current_vertex;
                enqueue(neighbor);
            }
        }
    }
}

int main(){
    int unconnected_nodes = 0;
    Node* root_vertex = &nodes[3];
    bfs(root_vertex);
//    unconnected_nodes = show_result();
    return unconnected_nodes;
}

