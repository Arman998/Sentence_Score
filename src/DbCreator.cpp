
#include <DbCreator.h>
#include <HashWord.h>
#include <Matrix.h>

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <iterator>

static std::vector<long_int> sumVector(binaryVectorSize,0);
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
		//	std::cout<<line<<"--> "<<obj.hash()<<std::endl;
		}
		db.close();
	} else {
		std::cout << "Unable to open file"<<std::endl;
	}
	ins.inspect(insHash);
	return mp;
}

std::vector<long_int> DbCreator::inspectWord(std::vector<std::string> line,
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
	for (unsigned int i = 0; i <= sumVector.size()-1; ++i ) {
		sumVector[i] = 0;
	}
	return resultVector;
}

bool DbCreator::inspectStopWrod(std::string sentenceWord,std::string stopWDicpath) {
	bool isfoundstopWord = false;
	std::string pathStopDic = stopWDicpath;
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

std::vector<long_int> DbCreator::splitStringIntoVector(std::string dicPath,
std::string stopWDicpath)
{
	std::vector<long_int> resultVector(binaryVectorSize,0);
	std::vector<std::string> lines;
	std::string sentence = "";
	std::string pathDic = dicPath;
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
		if (!inspectStopWrod(sentence ,stopWDicpath)){
			++stopWordsCount;
			lines.push_back(sentence);
		}		
		++wordsCount;
	}
	if ( wordsCount > 0 && stopWordsCount > 0) {
		resultVector = inspectWord(lines,vMap);
	}

	std::cout<<std::endl;

	for (unsigned int i = 0; i <= resultVector.size() - 1; ++i) {
		std::cout<<resultVector[i];
	}
	std::cout<<std::endl;
	return resultVector;
}

std::vector<long_int> DbCreator::workingWithTests(std::string dicPath,
std::string stopWDicpath, std::vector<std::string> testline)
{
	std::vector<long_int> resultVector(binaryVectorSize,0);
	std::vector<std::string> lines;
	std::string pathDic = dicPath;
	DbCreator cr; 
	std::map<long_int,std::vector<long_int>> vMap;
	vMap = cr.rWord(pathDic);
	unsigned int wordsCount = 0;
	int stopWordsCount = 0;
	while (wordsCount < testline.size()-1) {
		if (testline[wordsCount] == ".") {
			break;
		}
		if (!inspectStopWrod(testline[wordsCount] ,stopWDicpath)){
			++stopWordsCount;
			lines.push_back(testline[wordsCount]);
		}		
		++wordsCount;
	}
	if ( wordsCount > 0 && stopWordsCount > 0) {
		resultVector = inspectWord(lines,vMap);
	}

	std::cout<<std::endl;

	for (unsigned int i = 0; i <= resultVector.size() - 1; ++i) {
		std::cout<<resultVector[i];
	}
	std::cout<<std::endl;
	return resultVector;
}
std::vector<long_int> DbCreator::sumOfBinVector(std::vector<long_int> foundVector)
{
	int binarySum = 0;
	int leftover = 0;
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
