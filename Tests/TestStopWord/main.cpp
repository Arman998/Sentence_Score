#include <iostream>
#include "testStopWord.h"
#include <DbCreator.h>
#include <cstring>

int main(int argc, char* argv[]) {
	std::string test = "Test";
	if (argc > 1 && argv[1] == test) {
		test1(argc,argv);
	}
	return 0;
}
