#pragma once
#include "Card.h"
#include <list>
class Grid
{
private:
	list<Card> playingField[3][3];
	Card outerRoyals[4][3] = {Card()};
public:
	void AddCard(Card cardToAdd, int coordinate[2]);
	Card GetCard(int coordinate[2]);
	void AddRoyal(Card cardToAdd, int coordinate[2]);
	Card GetRoyal(int coordinate[2]);
};