#include <iostream>
#include <Matrix.h>
#include <vector>

void Matrix::bin(unsigned long long int hash)
{
	int binNumber{};
	int count{};
	int vecCount{};
	Matrix obj;
	while (hash > 0) {
		++count;
		binNumber = hash % 2;
		hash = hash / 2; 
		std::cout<<"hash = "<<hash<<" binNumber = "<< binNumber <<std::endl;
		obj.binMatrix[vecSize-count] = binNumber;
	}
	for (int i = 0; i <obj.binMatrix.size(); ++i) {
		++vecCount;
		std::cout<<obj.binMatrix[i]<< " ";
		if (vecCount == 10) {
			std::cout<<std::endl;
			vecCount = 0;
		}
	}
}

	std::vector<unsigned long long int>
Matrix::insert(unsigned long long int hash, int count)
{

	binMatrix[count] = hash;
	return binMatrix;
}

void Matrix::inspect()
{
	for (int i = 0; i < binMatrix.size(); ++i) {
		for(int j = i+1; j < binMatrix.size(); ++j) {
			if (binMatrix[i] == binMatrix[j]) {
				std::cout << "i = " << i <<" j = "<<j<<std::endl;
			}
		}
		std::cout<<binMatrix[i] << std::endl;
	}
}
void Matrix::setbinMatrix(std::vector<unsigned long long int> BinMatrix)
{
	binMatrix = BinMatrix;
}

std::vector<unsigned long long int> Matrix::getbinMatrix()
{
	return this->binMatrix;
}


