#pragma once
#include "Card.h"
#include <iostream>
#include <list>

class Deck
{
private:
	list<Card> playerCards;
	void OverHandShuffle(int deviation, int fixedAmountTaken);
	void Cut(int deviation);
	void Shuffle();
public:
	Deck();
	Card GetTopCard();
	void PushBack(list<Card> pileToAdd);
	Card LookAtTopCard();
	int GetLength();
};