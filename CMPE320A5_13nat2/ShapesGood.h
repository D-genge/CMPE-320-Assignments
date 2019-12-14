/*
 * for CMPE 320 by Neila Toofuny
 * NetID: 13nat2
 */

#pragma once
#include <iostream>.
#include <string>
using namespace std;


class Shape { //Base class
public:
	Shape();
	Shape(int l, int w);
	virtual ~Shape(); //virtual destructor
	int getLength(); //accessors
	int getWidth();
	virtual void draw() { cout << "\nThis uses the shape class"; } //so each child can inherit draw function
private:
	int length, width; //defined once
}; 

class Square : public Shape { //Square is the parent class of all polygons
public:
	Square(int l, int w, string bC);
	~Square(); //destructor
	void draw();
	string getbC(); //accessor
private:
	string borderColor; //defined once
};

class FilledSquare : public Square { //FilledSquare is the parent class of all filled polygons
public:
	FilledSquare(int l, int w, string bC, string fC);
	~FilledSquare(); //destructor
	void draw();
	string getfC(); //accessor
private:
	string fillColor; //defined once
};

class FilledTextSquare : public FilledSquare { //FilledTextSquare is the parent class of all filled polygons w/ text
public:
	FilledTextSquare(int l, int w, string borderColor, string fillColor, string Text);
	~FilledTextSquare(); //destructor
	void draw();
	string getText(); //accessor
private:
	string Text; //defined once
};

class Circle : public Square { //inherits from Square, parent of all polygons
public:
	Circle(int l, int w, string bC);
	~Circle(); //destructor
	void draw();
};

class FilledCircle : public FilledSquare { //inherits from filled polygon parent
public:
	FilledCircle(int l, int w, string borderColor, string fillColor);
	~FilledCircle(); //destructor
	void draw();
};

class Arc : public Square { //inherits from Square, parent of all polygons
public:
	Arc(int l, int w, string bC);
	~Arc(); //destructor
	void draw();
};