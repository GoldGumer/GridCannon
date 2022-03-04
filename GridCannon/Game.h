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
	Game();
	void DisplayGrid();
	void DisplayCard();
	void PlaceCurrentCard(int coordinate[2]);
	void PlaceRoyal(Card royal);
};

