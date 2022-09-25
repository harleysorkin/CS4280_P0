#include <stdio.h>
#include <string>
#include <vector>

// Create Node structure holding values of left and right children, current value, and height
struct Node {
    char data;
    struct Node *left;
    struct Node *right;
    std::vector<std::string> middle;
    int height;
};
