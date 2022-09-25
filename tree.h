#include "node.h"

class Tree {
    public:
    Node *root;
    Tree() {
        root = NULL;
    }

    void addTree(char, std::string, int);
    void addNode(Node *&, Node *&);
    int search(char, Node *, std::string);
    void inorder(Node *, char *);
    void preorder(Node *, char *);
    void postorder(Node *, char *);
};
