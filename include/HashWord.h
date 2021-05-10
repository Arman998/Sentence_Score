#pragma once
typedef unsigned long long int long_int;
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
        long_int hash();
};
