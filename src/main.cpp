#include <iostream>
#include <filesystem>

#include "utils.hpp"
#include "writelatex.hpp"
#include "printtree.hpp"
#include "node.hpp"


int main(int ac, char **av)
{
    /* --- Define a parameter to set the max depth of the tree --- */
    int max_depth           = std::numeric_limits<int>::max();

    /* --- Define the path to compute the tree directory --- */
    std::string input_path  = "./"; // Path to compute the tree
    std::string output_path = "./"; // Path to save the LaTeX
    // Check if an argument has been given for the input_path
    if (ac > 1){
        // Check if the input_path refers to a valid directory
        if (std::filesystem::is_directory(av[1])){
            input_path  = av[1];
        }
        else{
            std::cout << "!!! The input_path passed in argument is not a valid directory !!!" << std::endl;
        }
        std::cout<< "------------------------" << std::endl;
        std::cout<< "Input Path : " << input_path << std::endl;
        std::cout<< "------------------------" << std::endl;
        
        if (ac > 2){
            // Set the output path
            output_path = av[2];
            std::cout<< "------------------------" << std::endl;
            std::cout<< "Output Path : " << output_path << std::endl;
            std::cout<< "------------------------" << std::endl;

            if (ac > 3 && isInteger(av[3])){
                // Set the max depth of the tree
                if (std::stoi(av[3]) > 0){
                    max_depth = std::stoi(av[3]);
                    std::cout<< "------------------------" << std::endl;
                    std::cout<< "Max Depth: " << max_depth << std::endl;
                    std::cout<< "------------------------" << std::endl;
                }
            }
        }  
    }

    /* --- Create a Tree from the input_path --- */
    std::string root_name = getName(input_path);
    if (root_name == "") root_name = "./";
    std::shared_ptr<Node> Root = createNode(root_name, true, nullptr); // Define the Root Node
    createTree(input_path, Root); // Create the tree from the Root Node

    /* --- Print the tree directory --- */
    //printTree(input_path, 0);
    printTreeFromRoot(Root, max_depth);

    /* --- Generate LaTeX code source --- */
    // First create an output directory if it does not exist
    std::string filename    = "tree.tex";
    std::filesystem::create_directories(output_path + "/output");
    // Then create a TeX file
    writeTexfile(output_path + "/output/" + filename, Root, max_depth);

    return 0;
}