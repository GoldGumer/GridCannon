#pragma once
#include "Card.h"
#include "Deck.h"
#include "Grid.h"
class Game
{
private:
	Deck playerDeck;
	Card currentCard;
	Grid playerGrid;
public:
	void DisplayGrid();
	void DisplayCard();
};

