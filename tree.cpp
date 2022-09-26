#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

#include "tree.h"

// Creates new node to be added to tree
void Tree::addTree(char c, std::string s, int i) {
    Node *node = new Node;
    node->data = c;
    node->left = node->right = NULL;
    node->middle.push_back(s);
    node->height = i;

    addNode(root, node);
}

// Places created node in correct place on tree
void Tree::addNode(Node *&ptr, Node *&node) {
    if(ptr == NULL){
        ptr = node;
    }
    else if(node->data < ptr->data) {
        addNode(ptr->left, node);
    }
    else {
        addNode(ptr->right, node);
    }
}

// Command to start tree building process. Searches tree for existing nodes matching new node to calculate the correct height
int Tree::search(char c, Node *root, std::string s) {
    Node *node = root;
    int i = 0;

    while(node) {
        if(node->data == c) {
            node->middle.push_back(s);
            return 1;
        }
        else if(c < node->data) {
            node = node->left;
            i++;
        }
        else {
            node = node->right;
            i++;
        }
    }

    addTree(c, s, i);
    return 0;
}

// Inorder traversal
void Tree::inorder(Node *ptr, char *output) {
	if(ptr) {
	    inorder(ptr->left, output);
            std::ofstream file(output);
	    file << ptr->middle.front();
	    file.close();
            inorder(ptr->right, output);
	}
}

// Preorder travsersal
void Tree::preorder(Node *ptr, char *output) {
	if(ptr) {
            std::ofstream file(output);
	    file << ptr->middle.front();
	    file.close();
            preorder(ptr->left, output);
            preorder(ptr->right, output);
	}
}

// Postorder trasversal
void Tree::postorder(Node *ptr, char *output) {
	if(ptr) {
            postorder(ptr->left, output);
            postorder(ptr->right, output);
	    std::ofstream file(output);
            file << ptr->middle.front();
	    file.close();
	}

}
