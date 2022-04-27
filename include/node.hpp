#pragma once

#include "utils.hpp"

/**
 * @brief Node Object to build a tree
 * 
 */
struct Node{
    std::string name;
    bool isDirectory;
    std::shared_ptr<Node> parent;
    std::vector<std::shared_ptr<Node>> children;
    int level;

    inline Node(std::string name) : name(name){};
    ~Node();
};

/**
 * @brief Create a Node object from a name and a parent Node
 * 
 * @param name 
 * @param isDirectory 
 * @param parent 
 * @return std::shared_ptr<Node> 
 */
std::shared_ptr<Node> createNode(std::string name, bool isDirectory, std::shared_ptr<Node> parent);

/**
 * @brief Create a Tree object from a given path and a parent Node
 * 
 * @param path 
 * @param parent 
 */
void createTree(std::string path, std::shared_ptr<Node> parent);

/**
 * @brief Print a Tree in the terminal from the Root for a given maximal depth
 * 
 * @param Root 
 * @param max_depth 
 */
void printTreeFromRoot(std::shared_ptr<Node> Root, int max_depth = std::numeric_limits<int>::max());