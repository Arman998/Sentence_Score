#pragma once
typedef unsigned long long int long_int;
#include <iostream>
#include <vector>
#define binaryVectorSize 100
class Matrix
{
	public:
		Matrix(){}
		~Matrix() = default;
		std::vector<long_int> bin(long_int hash);
		void inspect(std::vector<long_int> inspectElement);
		void setbinMatrix(std::vector<long_int> BinMatrix);
		std::vector<long_int> getbinMatrix();
	private:
		std::vector<long_int> binMatrix 
		{std::vector<long_int>(binaryVectorSize,0)};
};
