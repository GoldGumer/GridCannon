#pragma once
#include <iostream>
#include <string>
using namespace std;

class Card
{
private:
	string faceValue;
	string displayGraphics[9];
public:
	Card();
	Card(string faceValue);
	string GetFaceValue();
	void DisplayFaceValue(int line);
};