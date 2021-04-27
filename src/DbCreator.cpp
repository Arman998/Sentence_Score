#include <iostream>
#include <fstream>
#include <cstring>
#include <DbCreator.h>
#include <HashWord.h>
#include <iomanip>
#include <vector>
#include <Matrix.h>

void DbCreator::rWord()
{
	std::string line;
	int count{};
	Matrix ins;
	std::ifstream db("DBtxt100.txt");
	if (db.is_open()) {
		while (getline (db,line)) {
			++count;
			HashWord obj(line.c_str());
			std::cout << std::setw(11); 
			std::cout << line << " -->  "<< obj.hash() << std::endl;
			ins.insert(obj.hash(), count);
		}
		db.close();
	} else {
		std::cout << "Unable to open file";
	}
	ins.inspect();
}
