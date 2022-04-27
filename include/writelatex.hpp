#pragma once

#include <fstream>

#include "utils.hpp"
#include "node.hpp"

/**
 * @brief Convert a node into a LaTeX Expression
 * 
 * @param Node 
 * @param max_depth 
 * @return std::string 
 */
std::string nodeToLatex(std::shared_ptr<Node> Node, int max_depth = std::numeric_limits<int>::max());

/**
 * @brief Write LaTeX code into a file from the given path
 * 
 * @param path 
 * @param Root 
 * @param max_depth 
 */
void writeTexfile(std::string path, std::shared_ptr<Node> Root, int max_depth = std::numeric_limits<int>::max());