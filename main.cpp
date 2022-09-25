#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

#include "tree.h"

int main(int argc, char* argv[]) {

    char *filename;
    std::string data;
    std::string output = "outP0";
    char *fname = const_cast<char *>(output.c_str());
    Tree tree;

    // Checks if no inputs given, then gets data from keyboard inputs
    if(argc == 1) {
        std::cout << ("No input file given. Please enter data manually.\n");
        getline(std::cin, data);

        int result = tree.search(data[0], tree.root, data);

        tree.inorder(tree.root, fname);
        tree.preorder(tree.root, fname);
        tree.postorder(tree.root, fname);
    }

    // Checks if filename is given, and appends ".cs4280" to the end
    else if(argc == 2) {
        filename = strcat(argv[1], ".cs4280");

        std::ifstream file;
        file.open(filename);
	std::ostringstream temp;
	temp << file.rdbuf();
	data = temp.str();
       
        int result = tree.search(data[0], tree.root, data);

        tree.inorder(tree.root, fname);
        tree.preorder(tree.root, fname);
        tree.postorder(tree.root, fname);
    }

    // Checks if filename given following "<", and attempts to open specified file
    else if(argc == 3) {
        if(argv[1] == "<"){
            filename = argv[2];

            std::ifstream file;
            file.open(filename);
            std::ostringstream temp;
	    temp << file.rdbuf();
	    data = temp.str();

            int result = tree.search(data[0], tree.root, data);

            tree.inorder(tree.root, fname);
            tree.preorder(tree.root, fname);
            tree.postorder(tree.root, fname);
        }
    }

    else {
        std::cout << ("Error opening file. Please invoke with the command:\n./P0			        -> Reads input from the keyboard\n./P0 < \"somefile\"	    -> Reads input from specified file \"somefile\"\n./P0 \"somefile\"		-> Reads input from \"somefile\".cs4280");
    }

    return 0;
}
