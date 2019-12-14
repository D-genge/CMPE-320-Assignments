//NetID: 13nat2
//Date: 2019-11-17
// Assignment 4 for CMPE 320
//
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "CMPE320A4_13nat2.h"

using namespace std;


BadJumbleException::BadJumbleException(const std::string& m) : message(m) {}
std::string& BadJumbleException::what() { return message; }

//define constructors
JumblePuzzle::JumblePuzzle() {
	gameArr = nullptr;
	len = 0;
	dir = 0;
	row = 0;
	col = 0;
}


JumblePuzzle::JumblePuzzle(std::string word, char diff) {
	gameArr = nullptr;
	len = 0;
	dir = 0;
	row = 0;
	col = 0;
	int wordlen = word.length();
	switch (diff) {
	case 'E': {
		len = wordlen * 2;
		gameArr = new char* [len]; //need to create array of pointers to fill with other pointers

		for (int i = 0; i < len; i++) {
			gameArr[i] = new char[len]; //using heap

		}
		break;
	}
	case 'M': {
		len = wordlen * 3;
		gameArr = new char* [len]; //need to create array of pointers to fill with other pointers

		for (int i = 0; i < len; i++) {
			gameArr[i] = new char[len];

		}
		break;
	}
	case 'H': {
		len = wordlen * 4;
		gameArr = new char* [len]; //need to create array of pointers to fill with other pointers

		for (int i = 0; i < len; i++) {
			gameArr[i] = new char[len];

		}
		break;
	}
	default:
		throw BadJumbleException("Input Invalid. Please enter (E)asy, (M)edium, or (H)ard.");
	}

	//std::cout << "SIZE:" + std::to_string(sizeof(gameArr[0])) << endl;

	//fill array w/ random letters
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			gameArr[i][j] = 97 + rand() % 26; //generate random char from ASCII values
			//std::cout << gameArr[i][j];
		}
	}

	//generate random row and column position from 0 to size-1
	srand(time(NULL)); //generate random seed
	row = rand() % len;
	col = rand() % len;

	std::cout << "ROW: " + std::to_string(row) + " COL: " + std::to_string(col) + "\n";
	//put first letter of this word in the row, col generated


	//generate random direction (1,2,3,4)
	srand(time(NULL));
	int i = 0;
	//continue loop until all chars in word have been placed into the game array
	while (word[i] != '\0') {
		dir = rand() % 4;
		switch (dir) {
		case 0: //UP: keep row index, decrement column
			if ((col - wordlen) < 0) {
				//throw BadJumbleException("Word is out of bounds.");
				break;
			}
			else if (word[i] != '\0') {
				for (int j = col; j > 0; j--) {
					if (word[i] != '\0') {
						gameArr[row][j] = word[i];
						i++;
					}
				}
			}
			else {
				break;
			}

		case 1: //DOWN: keep row index, increment column
			if ((col + wordlen) > len) {
				//throw BadJumbleException("Word is out of bounds.");
				break;
			}
			else if (word[i] != '\0') {
				for (int j = col; j < len; j++) {
					if (word[i] != '\0') {
						gameArr[row][j] = word[i];
						i++;
					}
				}
			}
			else {
				break;
			}

		case 2: //LEFT: decrement row index
			for (int j = row; j > 0; j--) {
				if ((row - wordlen) < 0) {
					//throw BadJumbleException("Word is out of bounds.");
					break;
				}
				else if (word[i] != '\0') {
					for (int j = row; j > 0; j--) {
						if (word[i] != '\0') {
							gameArr[j][col] = word[i];
							i++;
						}
					}
				}
			}
			break;

		case 3: //RIGHT: increment row index
			if ((row + wordlen) > len) {
				//throw BadJumbleException("Word is out of bounds.");
				break;
			}
			else if (word[i] != '\0') {
				for (int j = row; j < len; j++) {
					if (word[i] != '\0') {
						gameArr[j][col] = word[i];
						i++;
					}
				}
			}
			else {
				break;
			}
		}
	}
	//print out array

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			std::cout << gameArr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

JumblePuzzle::JumblePuzzle(JumblePuzzle& other) {
	len = other.getSize();
	dir = other.getDirection();
	row = other.getRowPos();
	col = other.getColPos();

	char** gameArr = new char* [len]; //using heap, need to create array of pointers to fill with other pointers

	for (int i = 0; i < len; i++) {
		gameArr[i] = new char[len];
	}

		//copy gameArray
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				gameArr[i][j] = other.gameArr[i][j]; //copy contents
			}
		}
	}

JumblePuzzle::~JumblePuzzle() { //destructor
	for (int i = 0; i < len; i++) {
		delete[] gameArr[i];
	}
	delete[] gameArr;
}

//assignment overloading
JumblePuzzle& JumblePuzzle::operator=(JumblePuzzle& right) {

	if (this != &right) {		// Check to see if assigning to self
		for (int i = 0; i < len; i++) {
			delete[] gameArr[i];
		}
		delete[] gameArr;
	}
		len = right.getSize();
		dir = right.getDirection();
		row = right.getRowPos();
		col = right.getColPos();
		
		char** newArr = new char* [len]; //need to create array of pointers to fill with other pointers

		for (int i = 0; i < len; i++) {
			newArr[i] = new char[len];
		}

		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				newArr[i][j] = right.gameArr[i][j]; //copy contents of right
			}
		}
	return *this;				// Return ref to self
}

int JumblePuzzle::getSize() {
	return len;
}

int JumblePuzzle::getRowPos() {
	return row;
}

int JumblePuzzle::getColPos() {
	return col;
}

char** JumblePuzzle::getJumble() {
	return gameArr;
}

int JumblePuzzle::getDirection() { // char JumblePuzzle::getDirection() {
	/*
	switch (dir) {
	case 0:
	{char result = 'n'; }
	case 1:
	{char result = 's'; }
	case 2:
	{char result = 'w'; }
	case 3:
	{char result = 'e'; }

	return result;
	}
	*/
	return dir;
}

char JumblePuzzle::charDirection() { 
	char result;
	switch (dir) {
	case 0:
	{char result = 'n'; }
	case 1:
	{char result = 's'; }
	case 2:
	{char result = 'w'; }
	case 3:
	{char result = 'e'; }//get char to compare directions in test

	return result;
	}
}

