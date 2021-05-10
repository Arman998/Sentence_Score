#include <iostream>
#include <fstream>
#include <cstring>
#include <DbCreator.h>
#include <HashWord.h>
#include <iomanip>
#include <Matrix.h>
#include <iterator>
#include <DbCreator.h>

std::map<long_int,std::vector<long_int>> DbCreator::rWord()
{
	std::map<long_int,std::vector<long_int>> mp;
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
void DbCreator::splitStringIntoVector()
{
	std::vector<std::string> lines;
	DbCreator cr; 
	std::map<long_int,std::vector<long_int>> vMap;
	vMap = cr.rWord();
	std::string sentence = "";
	std::cout<<"### ENTER THE WORD ###"<<std::endl;
	int wordsCount = 0;
	while (wordsCount < 500) {
		std::cin>> sentence;
		if (sentence == ".") {
			break;
		}
		lines.push_back(sentence);
		++wordsCount;
	}
	for (auto i : lines) {
		HashWord obj(i.c_str());
		long_int hash = obj.hash();
		std::cout << i<< " -->" << obj.hash()<<std::endl; 
		cr.printMap(vMap,hash);
	}
}
void DbCreator::printMap(std::map<long_int,std::vector<long_int>> mp,long_int hash)
{
	std::cout<<"###MAP###"<<std::endl;
	int lineLengthCount = 0;
	std::map<long_int ,std::vector<long_int>>::iterator itr;
	for (itr =mp.begin(); itr != mp.end(); ++itr) {
		if (itr->first == hash) {
			std::cout<<"hash = " << '\t' << itr->first<<std::endl<<std::endl
				<<"vector-->"<<'\t';
			for(auto it2 = itr->second.begin(); it2 != itr->second.end(); ++it2) {
				std::cout << *it2 << " ";
				++lineLengthCount;
				if (lineLengthCount == 10) {
					std::cout<<std::endl<<'\t'<<'\t';
					lineLengthCount = 0;
				}
			}
		} 
	}
	std::cout<<std::endl;
}
