#pragma once
#include <iostream>
#include <vector>
#define vecSize 100
class Matrix
{
	public:
		Matrix(){}
		~Matrix() = default;
		void bin(unsigned long long int hash);
		void inspect();
		std::vector<unsigned long long int> insert (unsigned long long int hash, int count);
			void setbinMatrix(std::vector<unsigned long long int> BinMatrix);
		std::vector<unsigned long long int> getbinMatrix();

	private:
		std::vector<unsigned long long int> binMatrix 
		{std::vector<unsigned long long int>(100,0)};
};
