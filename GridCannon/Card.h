#pragma once
#include <iostream>
#include <string>
using namespace std;

class Card
{
private:
	string faceValue;
public:
	Card(string faceValue);
	string GetFaceValue();
	void DisplayFaceValue(int line);
};