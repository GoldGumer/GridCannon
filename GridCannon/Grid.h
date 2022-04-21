#pragma once
#include "Card.h"
#include <list>
class Grid
{
private:
	list<Card> playingField[3][3];
	Card royals[4][3] = { Card() };
	Card ploys[6] = { Card() };
	int* NearestRoyalToCard(int pos[2], bool returnClockwise);
public:
	void AddCard(Card cardToAdd, int coordinate[2]);
	Card GetCard(int coordinate[2]);
	void AddRoyal(Card cardToAdd, int coordinate[2]);
	Card GetRoyal(int coordinate[2]);
	void AddPloy(Card ployCard);
	list<Card> PloyAce(int coordinate[2]);
	void PloyJoker(int cardToMove[2], int placeToMove[2]);
	void Display();
	void PlaceRoyal(Card royal);
};