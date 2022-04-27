#include "node.hpp"


Node::~Node(){}

std::shared_ptr<Node> createNode(std::string name, bool isDirectory, std::shared_ptr<Node> parent){
    std::shared_ptr<Node> NewNode = std::make_shared<Node>(name);
    NewNode -> isDirectory = isDirectory;
    NewNode -> parent = parent;
    if (parent != nullptr){
        parent -> children.push_back(NewNode);
        NewNode -> level = parent -> level + 1;
    }
    else{
        NewNode -> level = 0;
    }
    return NewNode;
}

void createTree(std::string path, std::shared_ptr<Node> parent){
    for (auto& file : std::filesystem::directory_iterator(path)){
        std::string path = file.path();
        std::string child_name = getName(path);
        std::shared_ptr<Node> NewNode = createNode(child_name, file.is_directory(), parent);
        if (file.is_directory()){
            createTree(path, NewNode);
        }
    }
}

void printTreeFromRoot(std::shared_ptr<Node> Root, int max_depth){
    std::string line;
    int i = 1;
    while (i < Root -> level){
        line += "|   ";
        i++;
    }
    if (Root ->parent != nullptr)
        std::cout << line << "|---" << Root -> name<<std::endl;
    else
        std::cout << Root -> name<<std::endl;
    //std::cout << Root -> name << " (" << Root ->level << ")" << std::endl;
    for (auto& child : Root->children){
        if (child -> level <= max_depth)
            printTreeFromRoot(child, max_depth);
    }
}