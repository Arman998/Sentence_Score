#include <iostream>
#include <string>
#include <Matrix.h>
#include <HashWord.h>
#include <DbCreator.h>
#include <vector>

int main()
{

    /* ithe rWord function reads a word from the file
       and makes hash function call, wich is will calculates
       the hash of the word and transfers the result to the
       inspect function . the inspect function chacks the existance
       of recurring  numbers and validates that*/
    DbCreator cr; 
    cr.rWord(); 
    return 0;
} 

