#include <Helper.h>
#include <DbCreator.h>
#include <fstream>

void help()
{ 
	std::cout<<"## HELP"<<std::endl;
	std::cout<<"## usage: " <<std::endl;
	std::cout<<"##  ./sentence-score dictionary_path <path_to_dictionary> "
        << "stopWordsDic_path <path_to_stop_word_dictionary> "
        << "sentence_quantity <count of sentences>" <<std::endl;


	std::cout<<std::endl;
	std::cout<<"## The followng options are mandatory options "
        <<"and must be specified with their values: " <<std::endl;
	std::cout<<"## dictionary_path "
        <<"- The option takes dictionary path as a value"<<std::endl;
	std::cout<<"## stopWordsDic_path "
        <<"- The option takes the path of the stop word dictionary as a value "<<std::endl;
	std::cout<<"## sentence_quantity "
        <<"- The option takes an integer value as a count of the sentences that must be provided "<<std::endl;
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
