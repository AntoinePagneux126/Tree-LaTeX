# Tree-LaTeX

## About this project
The aim of this project is to be able to generate a tree corresponding to the tree structure of a folder. 
It has two outputs:

* The first one is a tree structure displayed in the terminal.
* The second one is a LaTeX code corresponding to the same tree structure. The LaTeX tree code is generated with [TikZ](https://tikz.net/) (for tree structure) and [fontAwesome5](https://fontawesome.com/) (for icons). 

This project is written in C++.

### Example
* The ouput in the terminal has the following form:
```
test
|---test1
|   |---main.py
|   |---data.txt
|   |---config.yml
|   |---config.ini
|   |---data.csv
|   |---data.xlsx
|---test2
|   |---test21
|   |---test22
|   |---test23
|---test3
|   |---test31
```

* The same LaTeX output has the following form:

![tree](https://user-images.githubusercontent.com/76402335/165479417-6ef07d15-7759-406e-afa6-65268ec7a524.png)

## Download the project
Run the following commands in a terminal:

```bash
git clone https://github.com/AntoinePagneux126/Tree-LaTeX.git
cd Tree-LaTeX
```

## Compile the project
Run the following commands in a terminal:

```bash
mkdir build
cd build
cmake ..
make
```

## Run
If you want to generate a tree, you can run the following command

```bash
tree-latex INPUT_PATH OUTPUT_PATH MAX_DEPTH
```

where:
* INPUT_PATH    is the folder you want to generate a tree
* OUTPUT_PATH   is the folder where the LaTeX source code will be written
* MAX_DEPTH     is the maximum depth of a tree. It allows you to limit the depth.

All of these parameters are optional, by default:
* INPUT_PATH    = ```./```
* OUTPUT_PATH   = ```./```
* MAX_DEPTH     = endless

### Example
In a terminal, run as well:
```bash
./tree-latex ../test ../test 2
```

```bash
./tree-latex ../test ../test
```

```bash
./tree-latex ../test
```

```bash
./tree-latex 
```

## Developper
Antoine Pagneux
