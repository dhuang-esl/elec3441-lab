#define MAX_ARITY 4

struct Node {
    int id;
    struct Node* parent;
    struct Node* neighbors[MAX_ARITY];
};

typedef struct Node Node;