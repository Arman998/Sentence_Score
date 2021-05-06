#pragma once
#include <iostream>
#include <map>
#include <vector>

class DbCreator
{
	public:
		std::string readWord;
		DbCreator(){}
		~DbCreator() = default;
		std::map<unsigned long long int,std::vector<unsigned long long int>> rWord();
		void printMap(std::map<unsigned long long int,std::vector<unsigned long long int>> mp);
};
