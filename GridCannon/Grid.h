#pragma once
#include "Card.h"
#include <list>
class Grid
{
private:
	list<Card> playingField[3][3];
	Card outerRoyals[4][3];
public:
	void AddCardToPos(Card cardToAdd, int coordinate[2]);
	Card GetCardAtPos(int coordinate[2]);
	void AddRoyalToPos(Card cardToAdd, int coordinate[2]);
	Card GetRoyalAtPos(int coordinate[2]);
};