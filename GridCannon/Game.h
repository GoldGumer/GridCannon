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
	void DisplayCard();
	void PlaceCurrentCard(int coordinate[2]);
	void PlayerPlaceCard();
public:
	Game();
};

