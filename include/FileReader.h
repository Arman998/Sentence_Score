#pragma once
#include <iostream>

class FileReader
{
    public:
        std::string readWord;
        FileReader(){}
        ~FileReader() = default;
        void rWord();
};
