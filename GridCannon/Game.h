#pragma once
#include "Card.h"
#include "Deck.h"
#include "Grid.h"
#include <fstream>
class Game
{
private:
	Deck playerDeck;
	Card currentCard;
	Grid playerGrid;
	void DisplayCard();
	void PlaceCard(int coordinate[2]);
	
	void InputManager();
public:
	Game();
};