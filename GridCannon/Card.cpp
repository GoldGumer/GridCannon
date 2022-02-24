#include "Card.h"
using namespace std;

Card::Card(string faceValue)
{
	//Top of the card
	this->faceValue = faceValue + " ____________ |            |";
	
	//Number display adding
	switch (stoi(faceValue.substr(0, 2))) {
	case 0:
		this->faceValue += "|  /\\        || /__\\       ||/    \\ ";
		break;
	case 1:
		this->faceValue += "|/|          || |          ||_|_    ";
		break;
	case 2:
		this->faceValue += "|  __        ||  __|       || |__   ";
		break;
	case 3:
		this->faceValue += "| __         ||  _)        || __)   ";
		break;
	case 4:
		this->faceValue += "|  /|        || /_|_       ||   |   ";
		break;
	case 5:
		this->faceValue += "|  __        || |__        ||  __|  ";
		break;
	case 6:
		this->faceValue += "|  __        || |__        || |__|  ";
		break;
	case 7:
		this->faceValue += "| ___        ||   /        ||  /    ";
		break;
	case 8:
		this->faceValue += "|  __        || (__)       || (__)  ";
		break;
	case 9:
		this->faceValue += "|  __        || (__)       ||  __)  ";
		break;
	case 10:
		this->faceValue += "|/|  /\\      || | (  )     ||_|_ \\/ ";
		break;
	case 11:
		this->faceValue += "|---         || |  /\\      ||\\| /--\\";
		break;
	case 12:
		this->faceValue += "|            ||            ||       ";
		break;
	case 13:
		this->faceValue += "|| /         |||<  o       ||| \\ I  ";
		break;
	default:
		this->faceValue += "|            ||            ||       ";
		break;
	}

	//Suit display adding
	switch (stoi(faceValue.substr(2, 1))) {
	case 0:
		this->faceValue += "  ^  ||        / \\ ||        \\ / ||         v  |";
		break;
	case 1:
		this->faceValue += "  ^  ||        / \\ ||       (_ _)||         I  |";
		break;
	case 2:
		this->faceValue += " _ _ ||       ( V )||        \\ / ||         v  |";
		break;
	case 3:
		this->faceValue += "  _  ||        ( ) ||       (_ _)||         I  |";
		break;
	default:
		this->faceValue += "     ||            ||            ||            |";
		break;
	}

	//Bottom of the card
	this->faceValue += "|____________|";
}

string Card::GetFaceValue()
{
	return faceValue.substr(0,3);
}

void Card::DisplayFaceValue(int line)
{
	if (line > 8) line = 8;
	else if (line < 0) line = 0;
	cout << faceValue.substr(3 + 14 * line, 14);
}
