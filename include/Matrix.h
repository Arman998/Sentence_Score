#pragma once
typedef unsigned long long int long_int;
#include <iostream>
#include <vector>
#define vecSize 100
class Matrix
{
	public:
		Matrix(){}
		~Matrix() = default;
		std::vector<long_int> bin(long_int hash);
		void inspect();
		void insert (long_int hash, int count);
		void setbinMatrix(std::vector<long_int> BinMatrix);
		std::vector<long_int> getbinMatrix();
	private:
		std::vector<long_int> binMatrix 
		{std::vector<long_int>(100,0)};
};
