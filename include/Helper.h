#pragma once
#include <iostream>


//void test1(int argc ,char* argv[]);
void help();
inline bool exists(const char* filename);
void handleOptions(int argc, char* argv[]);
void filePathTransfer(std::string dic_path, std::string stopWordsDic_path, int quantity);
