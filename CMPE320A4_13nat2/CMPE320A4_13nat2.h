#pragma once

//define Jumble Puzzle Class
class JumblePuzzle {
	private:
		int len;
		int dir;
		int row;
		int col;
		char** gameArr;
	public:
		JumblePuzzle(); //default constructor
		JumblePuzzle(std::string word, char diff); //simple constructor
		JumblePuzzle(JumblePuzzle& otherJumble); //copy constructor
		~JumblePuzzle(); //destructor
		char** getJumble(); //game array accessor
		int getSize(); //get size of the difficulty
		int getRowPos(); //get the random position
		int getColPos(); //get the random column 
		int getDirection(); //get the direction decided upon
		char charDirection(); //get char Direction
		JumblePuzzle& operator=(JumblePuzzle& right); //assignment operator overload
};

//make an error class 
class BadJumbleException {
public:
	BadJumbleException(const std::string& message);
	std::string& what();

private:
	std::string message;
};

