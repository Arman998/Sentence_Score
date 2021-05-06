#include <iostream>
#include <fstream>
#include <cstring>
#include <DbCreator.h>
#include <HashWord.h>
#include <iomanip>
#include <Matrix.h>
#include <iterator>
#include <DbCreator.h>

	std::map<unsigned long long int,std::vector<unsigned long long int>> 
DbCreator::rWord()
{
	std::map<unsigned long long int,std::vector<unsigned long long int>> mp;
	std::string line = "";
	int count = 0;
	Matrix ins;
	Matrix hashbin;
	std::ifstream db("../data_source/DBtxt100.txt");
	if (db.is_open()) {
		while (getline (db,line)) {
			HashWord obj(line.c_str());
			std::cout << std::setw(11);
			std::cout << line << " -->  "<< obj.hash() << std::endl;
			ins.insert(obj.hash(), count);
			++count;
			mp[obj.hash()] = hashbin.bin(obj.hash());
		}
		db.close();
	} else {
		std::cout << "Unable to open file";
	}
	ins.inspect();
	return mp;
}
void DbCreator::printMap(std::map<unsigned long long int,std::vector<unsigned long long int>> mp)
{
	std::cout<<"###MAP###"<<std::endl;
	int vcount = 0;
	std::map<unsigned long long int ,std::vector<unsigned long long int>>::iterator itr;
	for (itr = mp.begin(); itr != mp.end(); ++itr) {
		std::cout<<"hash = " << '\t' << itr->first<<std::endl
			<<"vector "<<std::endl;
		for(auto it2 = itr->second.begin(); it2 != itr->second.end(); ++it2) {
			std::cout << *it2 << " ";
			++vcount;
			if (vcount == 10) {
				std::cout<<std::endl;
				vcount = 0;
			}
		}
		std::cout<<std::endl;
	}
}
