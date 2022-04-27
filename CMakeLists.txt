cmake_minimum_required(VERSION 3.21)

# Project name
project(Tree-LaTeX VERSION 1.0)

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(tree-latex
    src/main.cpp
    src/utils.cpp
    src/printtree.cpp
    src/writelatex.cpp
    src/node.cpp
)