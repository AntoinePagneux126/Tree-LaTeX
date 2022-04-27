#include "writelatex.hpp"

std::string nodeToLatex(std::shared_ptr<Node> Node, int max_depth){
    std::map<std::string, std::string> extTofa = getExtTofa();
    std::string res = "";
    if (Node ->parent == nullptr){
        res += "\\FTdir(\\FTroot," + correctStringForTex(Node->name) + "," + correctStringForTex(Node->name) + "){ \n";
        for (auto& child : Node->children){
            if (child -> level <= max_depth)
                res += nodeToLatex(child, max_depth);
        }
        res += "}; \n \n";
    }   
    else if (Node -> isDirectory){
        res += std::string(Node -> level, '\t');
        res += "\\FTdir(" + correctStringForTex(Node->parent->name) + "," + correctStringForTex(Node -> name) + "," + correctStringForTex(Node -> name) + "){ \n";
        for (auto& child : Node->children){
            if (child -> level <= max_depth)
                res += nodeToLatex(child, max_depth);
        }
        res += std::string(Node -> level, '\t');
        res += "} \n \n";
    }
    else{
        res += std::string(Node -> level, '\t');
        if (extTofa.contains(getExtention(Node -> name)))
            res += "\\FTfileX(" + correctStringForTex(Node->parent->name) + ", " + correctStringForTex(Node -> name) + ", " + extTofa[getExtention(Node -> name)] +") \n";
        else
            res += "\\FTfile(" + correctStringForTex(Node->parent->name) + ", " + correctStringForTex(Node -> name) + ") \n";
    }
    return res;
}

void writeTexfile(std::string path, std::shared_ptr<Node> Root, int max_depth){
    std::fstream tex_file;

    tex_file.open(path, std::ios_base::out);
    if (!tex_file.is_open()) {
        std::cout << "failed to open: " << path << '\n';
    }
    else {
        tex_file <<     "\\usepackage{fontawesome5}" << std::endl <<
                        "\\usepackage{tikz}" << std::endl << std::endl <<

                        "\\newcommand{\\FTroot}{}" << std::endl << 
                        "\\def\\FTroot{tmp.west}" << std::endl << std::endl <<

                        "\\newcommand{\\FTdir}{}" << std::endl <<
                        "\\def\\FTdir(#1,#2,#3){" << std::endl <<
                        "\\FTfile(#1,{{\\color{black!40!white}\\faFolderOpen}\\hspace{0.2em}#3})" << std::endl <<
                        "(tmp.west)++(0.8em,-0.4em)node(#2){}" << std::endl <<
                        "(tmp.west)++(1.5em,0)" << std::endl <<
                        "++(0,-1.3em) " << std::endl <<
                        "}" << std::endl << std::endl <<

                        "\\newcommand{\\FTfile}{}" << std::endl <<
                        "\\def\\FTfile(#1,#2){" << std::endl <<
                        "node(tmp){}" << std::endl <<
                        "(#1|-tmp)++(0.6em,0)" << std::endl <<
                        "node(tmp)[anchor=west,black]{\\tt #2}" << std::endl <<
                        "(#1)|-(tmp.west)" << std::endl <<
                        "++(0,-1.2em) " << std::endl <<
                        "}" << std::endl << std::endl <<

                        "\\newcommand{\\FTfileX}{}"<< std::endl <<
                        "\\def\\FTfileX(#1,#2, #3){"<< std::endl <<
                        "node(tmp){}"<< std::endl <<
                        "(#1|-tmp)++(0.6em,0)"<< std::endl <<
                        "node(tmp)[anchor=west,black]{\\tt {\\color{black!40!white} #3} #2}"<< std::endl <<
                        "(#1)|-(tmp.west)"<< std::endl <<
                        "++(0,-1.2em)"<< std::endl <<
                        "}" << std::endl << std::endl <<

                        "\\begin{document}"  << std::endl <<
                        "\\begin{tikzpicture}[scale=1.,every node/.style={scale=1.}]"<< std::endl <<
                        "\\draw[color=black!60!white]"<< std::endl << std::endl;
        
        tex_file << nodeToLatex(Root, max_depth) << std::endl;        
        tex_file <<     "\\end{tikzpicture}"    << std::endl <<
                        "\\end{document}"       << std::endl;
        tex_file.close();
    }
    std::cout << "LaTeX Writing Success!" << std::endl;
}