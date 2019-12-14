/*
 * insultgenerator_13nat2.cpp
 *
 *      Author: Neila Toofuny, NetID: 13nat2
 *      Implementation file for CMPE320 assignment 1.
 */


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
#include "13nat2.h"
#undef main
using namespace std;

//main testing function supplied by Dr. Alan Mcleod as a testing program for CISC320 assignment 1.
int main() {

	InsultGenerator ig;
	vector<string> insults;
	double start, finish;

	// The initialize() method should load all the source phrases from the InsultsSource.txt file into the attributes.
	// If the file cannot be read, the method should throw an exception.
	try {
		ig.initialize();
	}
	catch (FileException & e) {
		cerr << e.what() << endl;
		return 1;
	}

	// talkToMe() returns a single insult, generated at random.
	cout << "A single insult:" << endl;
	cout << ig.talktoMe() << endl;

	// Check number to generate limits.
	try {
		insults = ig.generate(-100);
	}
	catch (NumInsultsOutOfBounds & e) {
		cerr << e.what() << endl;
	}
	try {
		insults = ig.generate(40000);
	}
	catch (NumInsultsOutOfBounds & e) {
		cerr << e.what() << endl;
	}

	// generate() generates the requested number of unique insults.
	cout << "\n100 insults, all different:" << endl;
	insults = ig.generate(100);
	if (insults.size() > 0)
		for (int i = 0; i < 100; i++)
			cout << insults[i] << endl;
	else
		cerr << "Insults could not be generated!" << endl;

	// generateAndSave() generates the requested number of unique insults and saves them to the filename
	// supplied.  If the file cannot be written, the method should throw an exception.  Note that the
	// insults in the file should be in alphabetical order!
	// Check the number to generate limits first:
	try {
		ig.generateAndSave("Nothing.txt", 40000);
	}
	catch (NumInsultsOutOfBounds & e) {
		cerr << e.what() << endl;
	}
	cout << "\nSaving 1000 unique insults to a file...";
	try {
		ig.generateAndSave("SavedInsults.txt", 1000);
	}
	catch (FileException & e) {
		cerr << e.what() << endl;
		return 1;
	}
	cout << "done." << endl;

	// Test ability to generate the maximum number of insults and how long it takes.
	try {
		start = clock();
		insults = ig.generate(10000);
		finish = clock();

	}
	catch (NumInsultsOutOfBounds & e) {
		cerr << e.what() << endl;
	}
	cout << "\n" << insults.size() << " insults generated." << endl;
	cout << (finish - start) << " msec to complete." << endl;

	return 0;

} // end main


FileException::FileException(const string& message) : message(message) {}
string& FileException::what() { return message; }

NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& message) : message(message) {}
string& NumInsultsOutOfBounds::what() { return message; }

// First two fast random number generation function taken from:
	//https://software.intel.com/en-us/articles/fast-random-number-generator-on-the-intel-pentiumr-4-processor
int InsultGenerator::fast_rand(void) { 
	static unsigned int g_seed;
	g_seed = (214013 * g_seed + 2531011); return (g_seed >> 16) & 0x7FFF; }

void InsultGenerator::fast_srand(int seed) { 
	static unsigned int g_seed;
	g_seed = seed; }

void InsultGenerator::initialize() {
	ifstream fileIn;
	fileIn.open("Text.txt");// file containing numbers in 3 columns 
	if (fileIn.fail()) // checks to see if file opended 
	{
		throw FileException("File cannot be read."); //try to throw an exception
	}
	int index = 0;
	while (!fileIn.eof()) //loops as long as the end of the file hasn't been reached
	{
		fileIn >> col1[index];
		fileIn >> col2[index];
		fileIn >> col3[index];

		index++; // go to the next index of each column

	}
	fileIn.close(); 

}

string InsultGenerator::talktoMe()
{	

	srand(fast_rand()); //get random seed so that different "random" numbers are output every time
	insult = "Thou " + col1[rand() % 50] + " " + col2[rand() % 50] + " " + col3[rand() % 50] + "!";
	
	return insult;
}


//function generateAndSave() generates the requested number of unique insults and saves them to the filename
	// supplied.
void InsultGenerator::generateAndSave(string fileName, int numInsults) {
	saltVec = generate(numInsults);
	ofstream saltyFile;
	saltyFile.open(fileName);
	//print all vector contents to output file
	for (int i = 0; i < saltVec.size(); i++) {
		saltyFile << saltVec[i];
	
	saltyFile.close();
	}
}


//generate() generates unique insults and returns them to an array

vector<string> InsultGenerator::generate(int numInsults)
{
	vector<string> saltVec;
	if (numInsults < 0 || numInsults > 2000){
		throw NumInsultsOutOfBounds ("You are too insulting.");
	}
	else {
		for (int i = 0; i < numInsults; i++) { //generate as many insults as required
			insult = talktoMe(); //generate insult
			saltVec.push_back(insult); //append to vector
			sort(saltVec.begin(), saltVec.end()); //sort the vector list alphabetically
		}
	}
	return saltVec;
	
}
