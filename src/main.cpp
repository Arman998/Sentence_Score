#include <iostream>
#include <Matrix.h>
#include <HashWord.h>
#include <DbCreator.h>

int main()
{
	/* ithe rWord function reads a word from the file
	   and makes hash function call, wich is will calculates
	   the hash of the word and transfers the result to the
	   inspect function . the inspect function chacks the existance
	   of recurring  numbers and validates that*/
	DbCreator cr; 
	std::map<unsigned long long int,std::vector<unsigned long long int>> vMap;
	vMap = cr.rWord();
	std::string sentence = "";
	std::cout<<"### ENTER THE WORD ###"<<std::endl;
	std::cin >> sentence;
	HashWord obj(sentence.c_str());
	std::cout<<"###MAP###"<<std::endl;
	int lineLengthCount = 0;
	
	std::map<unsigned long long int ,std::vector<unsigned long long int>>::iterator itr;
	for (itr =vMap.begin(); itr != vMap.end(); ++itr) {
		if (itr->first == obj.hash()) {
			std::cout<<"hash = " << '\t' << itr->first<<std::endl<<std::endl
				<<"vector-->"<<'\t';
			for(auto it2 = itr->second.begin(); it2 != itr->second.end(); ++it2) {
				std::cout << *it2 << " ";
				++lineLengthCount;
				if (lineLengthCount == 10) {
					std::cout<<std::endl<<'\t'<<'\t';
					lineLengthCount = 0;
				}
			}
		} 
	}
	std::cout<<std::endl;
	return 0;
} 

