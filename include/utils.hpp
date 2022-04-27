#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <map>
#include <limits>

/**
 * @brief Return a boolean corresponding if a given string is convertible into an integer
 * 
 * @param s 
 * @return true 
 * @return false 
 */
bool isInteger(const std::string & s);

/**
 * @brief Return a map which make the link beetwen an extention and the corresponding fontAwesome LaTeX token.
 * 
 * @return std::map<std::string, std::string> 
 */
std::map<std::string, std::string> getExtTofa();

/**
 * @brief Get the Tokens from a given string and a tokenizer
 * 
 * @param s
 * @param tokenizer 
 * @return std::vector<std::string> 
 */
std::vector<std::string> getTokens(std::string s, std::string tokenizer);

/**
 * @brief Get the name of a file or a folder from a given path
 * 
 * @param path 
 * @return std::string 
 */
std::string getName(std::string path);

/**
 * @brief Get the extention of a file from its name (e.g. txt, py, cpp...)
 * 
 * @param name 
 * @return std::string 
 */
std::string getExtention(std::string name);

/**
 * @brief Function to add a '\' before '_' to make a string compilable in LaTeX
 * 
 * @param s 
 * @return std::string 
 */
std::string correctStringForTex(std::string s);