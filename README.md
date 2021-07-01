This is the template of README file of projects developed by Instigate Design CJSC.

-------------------------------------------------------------------------------
Introduction

This is the README file of Sentence_Score_0.1 version developed by Instigate Design CJSC ...

CONTENTS
1. Getting Started
2. Prerequisites
3. Directory Structure
4. Installation
5. Usage
6. Implementation principles 

1. Getting Started
	For each word of a sentence do hashing, 
	then calculate the sum of the vectors for the final sentence score.

2. Prerequisites 
	Was used.
	- GCC compiler
	- GCC version (Ubuntu 5.4.0-6ubuntu1 ~ 16.04.12) 5.4.0 20160609 and high
	- Is needed 2GB ram  

3. Directory Content
	The main Sentence_Score directory contains the following subdirectories:
	- data_source -  directory contains  DBtxt100.txt file.
	- include -  directory contains DbCreator.h  HashWord.h  Matrix.h header files.
	- src - directory contains DbCreator.cpp  HashWord.cpp  main.cpp  Matrix.cpp source files.

4. Installation
	To build the project follow to the instructions below:
	- make

5. Usage 
	To run the project execute the following command:
	    ./sentence-score dictionary_path <path_to_dictionary> stopWordsDic_path <path_to_stop_word_dictionary> sentence_quantity <count of sentences>
	- enter a sentence and type "․" at the end of the sentence ․
	Example ․
	sentence: "fax china event making ."
	Result: "0000000000000000000000000000011110000101000000110011001001010011111011011110010100111000100010101100"


6. Implementation principles 
    The "sentence-score" program takes the following arguments:
        words dictionary
        stop words dictionary
        count of the sentences that must be processed.

    The program reads all the words from the provided dictionary, calculates hashes for each word and stores the
    content into the hash map as a key-value pairs, where the key is the calculated hash and the value is the 
    binary presentation of the hesh.
    The words, that included in stop word dictionary will be ignored during calculations and will not be part of the hash map container.
    
    Then the user must provide input sentences to serach the corresponding heshes for each word and calculate the score of each sentence.

    For each word of a sentence perforemed hesh calculation and search on the calculated hesh in the hesh-map container.
    The value of each found hesh will be added to a reasult vector thet initialy will be filled with all zeros.
    The final vector (sum of found hash values) will be our calculated score for the sentence.
    The calculated score then will be displayed on CLI as an output for a user.

    NOTE:
     In case if no word found or all the words are available in the stop word dictionary the inital vector(All zeros)
     will be displayed as a score for the provided sentence.
