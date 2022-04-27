#include "utils.hpp"


std::map<std::string, std::string> getExtTofa(){
    std::map<std::string, std::string> extTofa;
    extTofa["py"]   = "\\faPython";
    extTofa["txt"]  = "\\faFile*";
    extTofa["csv"]  = "\\faFileCsv";
    extTofa["xlsx"] = "\\faFileExcel";
    extTofa["pdf"]  = "\\faFilePdf";
    extTofa["jpg"]  = "\\faFileImage";
    extTofa["png"]  = "\\faFileImage";
    extTofa["docx"] = "\\faFileWord";
    extTofa["pptx"] = "\\faFilePowerpoint";
    extTofa["cpp"]  = "\\faFileCode";
    extTofa["hpp"]  = "\\faFileCode";
    extTofa["c"]    = "\\faFileCode";
    extTofa["h"]    = "\\faFileCode";
    extTofa["git"]  = "\\faGithub";
    extTofa["dockerfile"]   = "\\faDocker ";
    extTofa["ini"]   = "\\faCogs";
    extTofa["yml"]   = "\\faCogs";

    return extTofa;
}

bool isInteger(const std::string & s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

   char * p;
   strtol(s.c_str(), &p, 10);

   return (*p == 0);
}

std::vector<std::string> getTokens(std::string s, std::string tokenizer){
    std::vector<std::string> tokens;

    int start = 0;
    int end = s.find(tokenizer);

    while (end != -1) {
        start = end + tokenizer.size();
        end = s.find(tokenizer, start);
    }
    tokens.push_back(s.substr(start, end - start));

    return tokens;
}

std::string getName(std::string path){
    std::vector<std::string> tokens = getTokens(path, "/");
    return tokens.back();
}

std::string getExtention(std::string name){
    return getTokens(name, ".").back();
}

std::string correctStringForTex(std::string s){
    std::string new_s;
    for (auto c : s){
        if (c == '_')
            new_s += '\\';
        new_s += c;
    }
    return new_s;
}
