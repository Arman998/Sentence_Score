This is the template of README file of projects developed by Instigate Design CJSC.

-------------------------------------------------------------------------------
Introduction

This is the README file of Sentence_Score_0.1 version developed by Instigate Design CJSC ...

CONTENTS
1. Getting Started
2. Prerequisities
3. Directory Structure
4. Installation
5. Usage
6. Troubleshooting
7. Maintainers
8. Future Scope

1. Getting Started
	For each word of a sentence do hashing, 
	then calculate the sum of the vectors for the final sentence score.

2. Prerequisities 
	Was used.
	- GCC compiler
	- GCC version (Ubuntu 5.4.0-6ubuntu1 ~ 16.04.12) 5.4.0 20160609 and high
	- Is needed 2GB ram  

3. Directory Content
	The main Sentence_Score directory contains the following subdirectories:
	- data_source -  directory contains  DBtxt100.txt file.
	- include -  directory contains DbCreator.h  HashWord.h  Matrix.h header files.
	- Make_F - directory contains Makefile file.
	- src - directory contains DbCreator.cpp  HashWord.cpp  main.cpp  Matrix.cpp source files.

4. Installation
	To build the project follow to the instructions below:
	- cd Make_f
	- make

5. Usage 
	To run the project execute the following command:
	- ․/run
	- enter a sentence and type "․" at the end of the sentence ․
	Example ․
	sentence: "fax china event making ."
	Result: "0000000000000000000000000000011110000101000000110011001001010011111011011110010100111000100010101100"







