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

void Matrix::inspect(std::vector<unsigned long long int> vec)
{
    for (int i = 0; i < vec.size(); ++i) {
        for(int j = i+1; j < vec.size(); ++j) {
            if (vec[i] == vec[j]) {
                std::cout << "i = " << i <<" j = "<<j<<std::endl;
            }
        }
    //    std::cout<<vec[i] << std::endl;
    }
}


