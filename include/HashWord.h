#pragma once
#include <string>

class HashWord
{
    public:
        const char *word;
        HashWord(const  char *w)
        {
            word = w;
        }
        ~HashWord() = default;
        unsigned long long int hash();
};
