#include <iostream>
#include <fstream>
#include <cstring>
#include <FileReader.h>
#include <HashWord.h>
#include <iomanip>
#include <vector>
#include <Matrix.h>

std::string line;
Matrix ins;
Matrix vec;
int count{};
void FileReader::rWord()
{
    std::ifstream db("DBtxt100.txt");
    if (db.is_open()) {
        while (getline (db,line)) {
            ++count;
            HashWord obj(line.c_str());
            std::cout << std::setw(11); 
            std::cout << line << " -->  "<< obj.hash() << std::endl;
            vec.binMatrix[count] = obj.hash();
        }
        db.close();
    } else {
        std::cout << "Unable to open file";
    }
    ins.inspect(vec.binMatrix);
    }
