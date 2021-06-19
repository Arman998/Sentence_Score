#include <iostream>
#include <DbCreator.h>
#include <Matrix.h>
/*The function gets a binary representation from
 * the hash and converts it to a vector
 */
std::vector<long_int> Matrix::bin(long_int hash)
{
	int binNumber = 0;
	int count = 0;
	for (unsigned int i = 0; i < binMatrix.size()-1; ++i) {
		binMatrix[i] = 0;	
	}
	while (hash > 0) {	
		++count;
		binNumber = hash % 2;
		hash = hash / 2; 
		binMatrix[binaryVectorSize - count] = binNumber;
	}
	return binMatrix;
}
/*The function checks for the presence of a duplicate hash*/
void Matrix::inspect(std::vector<long_int> inspectElement)
{
	for (unsigned int i = 0; i < inspectElement.size(); ++i) {
		for (unsigned int j = i+1; j < inspectElement.size(); ++j) {
			if (inspectElement[i] == inspectElement[j]) {
				std::cout<<"There is a collision in the dictionary"<<std::endl;
				std::cout << "elements = " << i + 1 <<" elements = "<< j + 1 <<std::endl;
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

