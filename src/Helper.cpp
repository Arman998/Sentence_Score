#include <Helper.h>
#include <DbCreator.h>
#include <fstream>

/*void test1(int argc, char* argv[]) {
	std::vector<long_int> stopWord(100,0);
	std::vector<long_int> result(100,0);
	std::vector<std::string> testline {"as","at","yet","you","."};
	DbCreator obj;
	std::string dicWWord = argv[2];
	std::string stopWWord = argv[3];
	result = obj.workingWithTests(dicWWord,stopWWord,testline);
	bool isNotEqual = true;
	for(unsigned int i = 0; i < stopWord.size()-1; ++i) {
		if (stopWord[i] != result[i]) {
			isNotEqual = false;
			break;
		}
	}
	if (isNotEqual) {
		std::cout<< "## PASS ##"<< std::endl;
	} else {
		std::cout<< "## FAIL ##"<< std::endl;
	}
}*/

void help()
{ 
	std::cout<<"## HELP ##"<<std::endl;
	std::cout<<"## dictionary_path ##"<<std::endl;
	std::cout<<"## stopWordsDic_path ##"<<std::endl;
	std::cout<<"## sentence_quantity ##"<<std::endl;
}

inline bool exists(const char* filename)
{
	std::ifstream file(filename);
	return file.good();
}

void filePathTransfer(std::string dic_path, std::string stopWordsDic_path,int quantity)
{
	int sentence_quantity = quantity;
	if (sentence_quantity >= 0) {
		while (sentence_quantity > 0) {
			DbCreator obj;
			obj.splitStringIntoVector(dic_path, stopWordsDic_path);
			--sentence_quantity;
		}
	} else {
		help();
	}
}

void handleOptions(int argc, char* argv[]) 
{
	if (argc == 1) {
		help();
	}
	if (argc > 1) {
		std::string dic_path = "dictionary_path";
		std::string stopWordsDic_path = "stopWordsDic_path";
		if (argv[1] == dic_path && argv[3] == stopWordsDic_path) {
			dic_path = argv[2];	
			stopWordsDic_path = argv[4];
			if (exists(stopWordsDic_path.c_str()) == false) {
				std::cout<<"Unable to open file -> "<<stopWordsDic_path<<std::endl;
				exit(1);
			}
			if (exists(dic_path.c_str()) == false) {
				std::cout<<"Unable to open file -> "<<dic_path<<std::endl;
				exit(1);
			}
		}
		int sentence_quantity = 0;
		std::string sentence_q = "sentence_quantity";
		if (argc == 7 && argv[5] == sentence_q) {
			sentence_quantity = atoi(argv[6]);
		}
		if (sentence_quantity == 0) {
			help();
		}
		filePathTransfer(dic_path,stopWordsDic_path, sentence_quantity);
	} else {
		exit(1);
	}
}
