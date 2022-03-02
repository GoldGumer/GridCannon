#include "Card.h"
using namespace std;

Card::Card(string faceValue)
{
	this->faceValue = faceValue;

	//Top of the card
	displayGraphics[0] = " ____________ ";
	displayGraphics[1] = "|            |";

	//Number display adding
	switch (stoi(faceValue.substr(0, 2))) {
	case 0:
		displayGraphics[2] = "|   ---      |";
		displayGraphics[3] = "|    | /\\    |";
		displayGraphics[4] = "|   \\| \\";
		break;
	case 1:
		displayGraphics[2] = "|  /\\        |";
		displayGraphics[3] = "| /__\\       |";
		displayGraphics[4] = "|/    \\ ";
		break;
	case 2:
		displayGraphics[2] = "|  __        |";
		displayGraphics[3] = "|  __|       |";
		displayGraphics[4] = "| |__   ";
		break;
	case 3:
		displayGraphics[2] = "| __         |";
		displayGraphics[3] = "|  _)        |";
		displayGraphics[4] = "| __)   ";
		break;
	case 4:
		displayGraphics[2] = "|  /|        |";
		displayGraphics[3] = "| /_|_       |";
		displayGraphics[4] = "|   |   ";
		break;
	case 5:
		displayGraphics[2] = "|  __        |";
		displayGraphics[3] = "| |__        |";
		displayGraphics[4] = "|  __|  ";
		break;
	case 6:
		displayGraphics[2] = "|  __        |";
		displayGraphics[3] = "| |__        |";
		displayGraphics[4] = "| |__|  ";
		break;
	case 7:
		displayGraphics[2] = "| ___        |";
		displayGraphics[3] = "|   /        |";
		displayGraphics[4] = "|  /    ";
		break;
	case 8:
		displayGraphics[2] = "|  __        |";
		displayGraphics[3] = "| (__)       |";
		displayGraphics[4] = "| (__)  ";
		break;
	case 9:
		displayGraphics[2] = "|  __        |";
		displayGraphics[3] = "| (__)       |";
		displayGraphics[4] = "|  __)  ";
		break;
	case 10:
		displayGraphics[2] = "|/|  /\\      |";
		displayGraphics[3] = "| | (  )     |";
		displayGraphics[4] = "|_|_ \\/ ";
		break;
	case 11:
		displayGraphics[2] = "| ---        |";
		displayGraphics[3] = "|  |         |";
		displayGraphics[4] = "| \\|    ";
		break;
	case 12:
		displayGraphics[2] = "|  /\\        |";
		displayGraphics[3] = "| ( \\)       |";
		displayGraphics[4] = "|  \\/\\  ";
		break;
	case 13:
		displayGraphics[2] = "| | /        |";
		displayGraphics[3] = "| |<         |";
		displayGraphics[4] = "| | \\   ";
		break;
	default:
		displayGraphics[2] = "|            |";
		displayGraphics[3] = "|            |";
		displayGraphics[4] = "|       ";
		break;
	}

	//Suit display adding
	switch (stoi(faceValue.substr(2, 1))) {
	case 0:
		displayGraphics[4] += "  ^  |";
		displayGraphics[5] = "|        / \\ |";
		displayGraphics[6] = "|        \\ / |";
		displayGraphics[7] = "|         v  |";
		break;
	case 1:
		displayGraphics[4] += "  ^  |";
		displayGraphics[5] = "|        / \\ |";
		displayGraphics[6] = "|       (_ _)|";
		displayGraphics[7] = "|         I  |";
		break;
	case 2:
		displayGraphics[4] += " _ _ |";
		displayGraphics[5] = "|       ( V )|";
		displayGraphics[6] = "|        \\ / |";
		displayGraphics[7] = "|         v  |";
		break;
	case 3:
		displayGraphics[4] += "  _  |";
		displayGraphics[5] = "|        ( ) |";
		displayGraphics[6] = "|       (_ _)|";
		displayGraphics[7] = "|         I  |";
		break;
	case 4:
		displayGraphics[4] += "/    |";
		displayGraphics[5] = "|   | / _    |";
		displayGraphics[6] = "|   |< /_\\   |";
		displayGraphics[7] = "|   | \\\\_    |";
		break;
	default:
		displayGraphics[4] += "     |";
		displayGraphics[5] = "|            |";
		displayGraphics[6] = "|            |";
		displayGraphics[7] = "|            |";
		break;
	}

	//Bottom of the card
	displayGraphics[8] = "|____________|";
}

string Card::GetFaceValue()
{
	return faceValue;
}

void Card::DisplayFaceValue(int line)
{
	if (line > 8) line = 8;
	else if (line < 0) line = 0;
	cout << displayGraphics[line];
}
