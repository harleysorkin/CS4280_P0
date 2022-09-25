#include <stdio.h>
#include <string>
#include <vector>

struct Node {
    char data;
    struct Node *left;
    struct Node *right;
    std::vector<std::string> middle;
    int height;
};
