#include <HashWord.h>
#include <iostream>

unsigned long long int HashWord::hash()
{
    const char *word = this->word;
    unsigned long long int hash = 5381;
    int it{};
    if (word != nullptr) {
        while (it = *word++) {
            hash = ((hash << 5) + hash) + it; // hash * 33 + c 
        }
    } else {
        std::cout << "Memory allocation failed: "<< std::endl;
    }
    return hash;
}

