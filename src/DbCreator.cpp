#include <iostream>
#include <fstream>
#include <cstring>
#include <DbCreator.h>
#include <HashWord.h>
#include <iomanip>
#include <Matrix.h>
#include <iterator>
#include <DbCreator.h>
std::map<long_int,std::vector<long_int>> DbCreator::rWord(std::string path)
{
	std::string pathDictionary = path;
	std::map<long_int,std::vector<long_int>> mp;
	std::vector<long_int> insHash;
	std::string line = "";
	Matrix ins;
	Matrix hashbin;
	std::ifstream db(pathDictionary);
	if (db.is_open()) {
		while (getline (db,line)) {
			HashWord obj(line.c_str());
			insHash.push_back(obj.hash());
			mp[obj.hash()] = hashbin.bin(obj.hash());
	//		std::cout<<line<<"--> "<<obj.hash()<<std::endl;
		}
		db.close();
	} else {
		std::cout << "Unable to open file";
	}
	ins.inspect(insHash);
	return mp;
}

void DbCreator::inspectWord(std::vector<std::string> line,
		std::map<long_int,std::vector<long_int>> hashMap)
{
	std::string space = " ";
	unsigned long long int twoWord = 0;
	unsigned long long int oneWord = 0;
	std::string word = " ";
	DbCreator cr;
	std::vector<long_int> resultVector(binaryVectorSize,0);
	for (unsigned int i = 0; i <= line.size()-1; ++i) {
		bool isFound = false;
		if ( line.size() >= 2 && (i <= line.size()-2)) {
			word = line[i] + space + line[i+1];
			HashWord obj(word.c_str());
			twoWord = obj.hash();
		} 
		std::map<long_int ,std::vector<long_int>>::iterator itr;
		itr = hashMap.find(twoWord);
		if (itr != hashMap.end()) {
			resultVector = cr.searchHash(hashMap,twoWord);
			twoWord = 0;
			++i;
			isFound = true;
		}	
		if (!isFound) {
			word = line[i];
			HashWord obj(word.c_str());
			oneWord = obj.hash();
			itr = hashMap.find(oneWord);
			if (itr != hashMap.end()) {
				resultVector = cr.searchHash(hashMap,oneWord);
				oneWord = 0;	
			}
		}
	}
	for (unsigned int i = 0; i <= resultVector.size() - 1; ++i) {
		std::cout<<resultVector[i];
	}
	std::cout<<std::endl;
}

bool DbCreator::inspectStopWrod(std::string sentenceWord) {
	bool isfoundstopWord = false;
	std::string pathStopDic = "./data_source/StopWords.txt:";
	std::map<long_int,std::vector<long_int>> vMap;
	DbCreator cr; 
	vMap = cr.rWord(pathStopDic);
	std::map<long_int ,std::vector<long_int>>::iterator itr;
	long_int stopHash = 0;
	HashWord stopword(sentenceWord.c_str());
	stopHash = stopword.hash();
	itr = vMap.find(stopHash);
	if (itr != vMap.end()) {
		isfoundstopWord = true;
	}
	return isfoundstopWord;
}

void DbCreator::splitStringIntoVector()
{
	std::vector<long_int> emptyEntry (binaryVectorSize,0);
	std::vector<std::string> lines;
	std::string sentence = "";
	std::string pathDic = "./data_source/DBtxt100.txt";
	std::vector<long_int> resultVector(binaryVectorSize,0);
	DbCreator cr; 
	std::map<long_int,std::vector<long_int>> vMap;
	vMap = cr.rWord(pathDic);
	int wordsCount = 0;
	int stopWordsCount = 0;
	while (wordsCount < 500) {
		std::cin>> sentence;
		if (sentence == ".") {
			break;
		}
		if (!inspectStopWrod(sentence)){
		++stopWordsCount;
		lines.push_back(sentence);
		}		
		++wordsCount;
	}
	if ( wordsCount > 0 && stopWordsCount > 0) {
		inspectWord(lines,vMap);
	} else {
		for (auto i :emptyEntry) {
			std::cout<<i;
		}
	}
	std::cout<<std::endl;
}

std::vector<long_int> DbCreator::sumOfBinVector(std::vector<long_int> foundVector)
{
	int binarySum = 0;
	int leftover = 0;
	static std::vector<long_int> sumVector(binaryVectorSize,0);
	for (int i = foundVector.size() - 1; i >= 0; --i) {
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
	std::vector<long_int> resVector(binaryVectorSize,0);
	std::vector<long_int> binaryVector(0);
	long_int vectorelement = 0;
	std::map<long_int ,std::vector<long_int>>::iterator itr;
	itr = mp.find(hash);
	if (itr != mp.end()) {
		for (auto it2 = (itr->second.begin()); it2 != (itr->second.end()); ++it2) {
			vectorelement = *it2;
			binaryVector.push_back(vectorelement);
		}
	}
	resVector = sumOfBinVector(binaryVector);
	return resVector;
}
