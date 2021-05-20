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
	std::vector<long_int> resultVector(100,0);
	DbCreator cr; 
	std::map<long_int,std::vector<long_int>> vMap;
	vMap = cr.rWord();
	std::string sentence = "";
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
		resultVector = cr.searchHash(vMap,hash);
	}
	std::cout<<"result -> ";
	for (unsigned int i = 0; i <= resultVector.size() - 1; ++i) {
		std::cout<<resultVector[i];
	}
	std::cout<<std::endl;
}

std::vector<long_int> DbCreator::sumOfBinVector(std::vector<long_int> foundVector)
{
	int binarySum = 0;
	int leftover =0;
	static std::vector<long_int> sumVector(100,0);
	for (int i = foundVector.size() - 1; i >= 0 ; --i) {
		binarySum = foundVector[i] + sumVector[i];
		switch(binarySum + leftover) {
			case 0:
				sumVector[i] = binarySum;
				leftover = 0;
				break;
			case 1:
				sumVector[i] = 1;
				leftover = 0;
				break;
			case 2:
				sumVector[i] = 0;
				leftover = 1;
				break;
			case 3:
				sumVector[i] = 1;
				leftover = 1;
				break;
		}
	}
	return sumVector;
}

std::vector<long_int> DbCreator::searchHash(std::map<long_int,std::vector<long_int>> mp,long_int hash)
{
	std::vector<long_int> binaryVector(0);
	std::vector<long_int> resVector(100,0);
	long_int vectorelement = 0;
	std::map<long_int ,std::vector<long_int>>::iterator itr;
	for (itr = mp.begin(); itr != mp.end(); ++itr) {
		if (itr->first == hash) {
			for( auto it2 = (itr->second.begin()); it2 != (itr->second.end()); ++it2) {
				vectorelement = *it2;
				binaryVector.push_back(vectorelement);
			}
		}
		resVector = sumOfBinVector(binaryVector);
	}
	return resVector;
}

