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
void Tree::inorder(Node *ptr, char *filename) {
	filename = strcat(filename, ".inorder");
	std::ofstream file;
	file.open(filename);
std::cout << "file opened" << std::endl;
	if(!file) {
		perror("Error: inorder()");
	}
	else {
		inorder(ptr->left, filename);
		file << ptr;
		inorder(ptr->right, filename);
	}

	file.close();
}

// Preorder traversal
void Tree::preorder(Node *ptr, char *filename) {
	filename = strcat(filename, ".preorder");
	std::ofstream file;
	file.open(filename);
std::cout << "file opened" << std::endl;
	if(!file) {
		perror("Error: preorder()");
	}
	else {
		file << ptr;
		preorder(ptr->left, filename);
		preorder(ptr->right, filename);
	}

	file.close();
}

// Postorder traversal
void Tree::postorder(Node *ptr, char *filename) {
	filename = strcat(filename, ".postorder");	
	std::ofstream file;
	file.open(filename);
std::cout << "file opened" << std::endl;
	if(!file) {
		perror("Error: postorder()");
	}
	else {
		postorder(ptr->left, filename);
		postorder(ptr->right, filename);
		file << ptr;
	}

	file.close();
}
