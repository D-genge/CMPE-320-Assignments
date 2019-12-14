/*
 * for CMPE 320 by Neila Toofuny
 * NetID: 13nat2
 */


#include "ShapesGood.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

//base class Shape
Shape::Shape() : length(0), width(0) {}
Shape::Shape(int len, int wid) : length(len), width(wid) {}
Shape::~Shape() {}
int Shape::getLength() { return length; }
int Shape::getWidth() { return width; }


//child class Square of Shape
Square::Square(int l, int w, string bC) : borderColor(bC), Shape(l, w) {  };

Square::~Square() {}
	
string Square::getbC() { return borderColor;}

void Square::draw() {
		cout << "\nDrawing a " + getbC() + " square.";
	}

//child class FilledSquare of Square
FilledSquare::FilledSquare(int l, int w, string bC, string fC) : fillColor(fC), Square(l, w, bC) {};

FilledSquare::~FilledSquare() {}

string FilledSquare::getfC() { return fillColor;}

void FilledSquare::draw() {
	Square::draw();
	cout << " With " + getfC() + " fill.";
}

//child class FilledTextSquare of FilledSquare
FilledTextSquare::FilledTextSquare(int l, int w, string bC, string fC, string Text) : Text(Text), FilledSquare(l, w, bC, fC) {};

FilledTextSquare::~FilledTextSquare() {}

string FilledTextSquare::getText() { return Text;}

void FilledTextSquare::draw() {
	FilledSquare::draw();
	cout << " Containing the text: \"" << getText() << "\".";
}

//child class Circle of Square
Circle::Circle(int l, int w, string bC) : Square(l, w, bC) {};

Circle::~Circle() {}

void Circle::draw() {
	cout << "\nDrawing a " + getbC() + " circle.";
}

//child class FilledCircle of FilledSquare
FilledCircle::FilledCircle(int l, int w, string bC, string fC) : FilledSquare(l, w, bC, fC) {}

FilledCircle::~FilledCircle() {}

void FilledCircle::draw() {
	cout << "\nDrawing a " + getbC() + " circle.";
	cout << " With " + getfC() + " fill.";
}

//child class Arc of Square
Arc::Arc(int l, int w, string bC) : Square(l, w, bC) {};

Arc::~Arc() {}

void Arc::draw() {
	cout << "\nDrawing a " + getbC() + " arc.";
}
