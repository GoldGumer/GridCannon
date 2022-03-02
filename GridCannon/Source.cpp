#include <iostream>
#include <time.h>
#include "Card.h"
#include "Deck.h"
using namespace std;

int main() {
	Deck playerDeck = Deck();
	Card nextCard = playerDeck.LookAtTopCard();
	for (int i = 0; i <= 8; i++)
	{
		nextCard.DisplayFaceValue(i);
		cout << endl;
	}
}