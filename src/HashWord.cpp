#include <iostream>
#include <cctype>
#include <HashWord.h>

/*the function performs word hashing*/
long_int HashWord::hash()
{
	const char *word = this->word;
	long_int hash = 5381;
	int it{};
	if (word != nullptr) {
		while ((it = *word++)) {
			hash = ((hash << 5) + hash) +tolower(it); // hash * 33 + c
		}
	} else {
		std::cout << "Memory allocation failed: "<< std::endl;
	}
	return hash;
}

