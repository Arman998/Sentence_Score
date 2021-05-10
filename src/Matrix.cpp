#include <iostream>
#include <Matrix.h>
std::vector<long_int> Matrix::bin(long_int hash)
{
	int binNumber = 0;
	int count = 0;
	while (hash > 0) {
		binNumber = hash % 2;
		hash = hash / 2; 
	//	std::cout<<"hash = "<<hash<<" binNumber = "<< binNumber <<std::endl;
		binMatrix[vecSize-count] = binNumber;
		++count;
	}
	return binMatrix;
}
void Matrix::insert(long_int hash, int count)
{
	binMatrix[count] = hash;
}
void Matrix::inspect()
{
	for (unsigned int i = 0; i < binMatrix.size(); ++i) {
		for (unsigned int j = i+1; j < binMatrix.size(); ++j) {
			if (binMatrix[i] == binMatrix[j]) {
				std::cout << "i = " << i <<" j = "<<j<<std::endl;
			}
		}
	}
}
void Matrix::setbinMatrix(std::vector<long_int> BinMatrix)
{
	binMatrix = BinMatrix;
}
std::vector<long_int> Matrix::getbinMatrix()
{
	return this->binMatrix;
}

