#pragma once
typedef unsigned long long int long_int;
#include <iostream>
#include <map>
#include <vector>
class DbCreator
{
	public:
		std::string readWord;
		DbCreator(){}
		~DbCreator() = default;
		std::map<long_int,std::vector<long_int>> rWord();
		void splitStringIntoVector();
		void printMap(std::map<long_int,std::vector<long_int>> mp, long_int hash);
};
