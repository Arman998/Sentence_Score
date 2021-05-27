#pragma once
typedef unsigned long long int long_int;
#include <iostream>
#include <map>
#include <vector>
class DbCreator
{
	public:
		DbCreator(){}
		~DbCreator() = default;
		std::map<long_int,std::vector<long_int>> rWord(std::string path);
		void splitStringIntoVector();
		std::vector<long_int> sumOfBinVector(std::vector<long_int> foundVector);
		std::vector<long_int> searchHash(std::map<long_int,std::vector<long_int>> mp, long_int hash);
		void inspectWord(std::vector<std::string> line,std::map<long_int,std::vector<long_int>> hashMap);
		bool inspectStopWrod(std::string sentenceWord);
};
