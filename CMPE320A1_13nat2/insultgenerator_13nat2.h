/*
 * insultgenerator_13nat2.h
 *
 *      Author: Neila Toofuny, NetID: 13nat2
 *      Header file for CMPE320 assignment 1.
 */

#pragma once
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

//create insult generator class 
class InsultGenerator {


	//declare attributes, convert all arrays to vectors
	string filename = "Text.txt";
	string col1[50];// arrays that can hold 50 numbers for each column 
	string col2[50];
	string col3[50];
	string insult;
	vector<string> insults;
	vector<string> saltVec;

		// declare functions
public:
	
	// Two fast random number generation functions taken from:
	//https://software.intel.com/en-us/articles/fast-random-number-generator-on-the-intel-pentiumr-4-processor
	int fast_rand(void); 
	void fast_srand(int seed);
	string talktoMe();
	vector<string> generate(int numInsults);
	void generateAndSave(string fileName, int numInsults);
	void initialize();
	
};

class FileException {
public:
	FileException(const string& message);
	string& what();

private:
	string message;
};

class NumInsultsOutOfBounds {
public:
	NumInsultsOutOfBounds(const string& message);
	string& what();

private:
	string message;
};