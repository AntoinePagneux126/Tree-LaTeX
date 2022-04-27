#include "printtree.hpp"

/* *************** ******* *************** */
/* *************** USELESS *************** */
/* *************** ******* *************** */

void printTree(std::string path, int level){
    if (level == 0){
        std::cout << "./" << std::endl;
    }
    for (const auto& file : std::filesystem::directory_iterator(path)){
        std::string path = file.path();
        std::string name = getName(path);

        std::string line;
        int i = 0;
        while (i < level){
            line += "|   ";
            i++;
        }

        std::cout << line << "|---" << name<<std::endl;

        if (file.is_directory()){
            printTree(file.path(), level + 1);
        }
    }
}