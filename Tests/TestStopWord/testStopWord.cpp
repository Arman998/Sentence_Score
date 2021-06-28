#include <Helper.h>
#include <DbCreator.h>
#include <fstream>
#include <testStopWord.h>

void test1(int argc, char* argv[]) {
	std::vector<long_int> stopWord(100,0);
	std::vector<long_int> result(100,0);
	std::vector<std::string> testline {"as","at","yet","you","."};
	DbCreator obj;
	std::string dicWWord = "./data_source/DBtxt100.txt";
	std::string stopWWord = "./data_source/StopWords.txt";
	result = obj.testSplitStringFunctionality(dicWWord,stopWWord,testline);
	bool isNotEqual = true;
	for(unsigned int i = 0; i < stopWord.size()-1; ++i) {
		if (stopWord[i] != result[i]) {
			isNotEqual = false;
			break;
		}
	}
	if (isNotEqual) {
		std::cout<< "## The value of all words is zero##"<< std::endl;
		std::cout<< "##              PASS             ##"<< std::endl;
	} else {
		std::cout<< "## FAIL ##"<< std::endl;
	}
}
