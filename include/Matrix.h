#pragma once
#include <iostream>
#include <vector>
#define vecSize 100
class Matrix
{
    public:
        std::vector<unsigned long long int> binMatrix 
        {std::vector<unsigned long long int>(100,0)};
        Matrix(){}
        ~Matrix() = default;
        void bin(unsigned long long int hash);
        void inspect(std::vector<unsigned long long int> vec);
};
