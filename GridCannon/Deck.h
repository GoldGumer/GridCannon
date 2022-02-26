#pragma once
#include "Card.h"
#include <iostream>
#include <list>

class Deck
{
private:
	list<Card> playerCards;
	void OverHandShfl(int deviation, int fixedAmountTaken);
	void FaroShfl();
	void Cut(int deviation);
	void Shuffle();
public:
	Deck();
	Card GetTopCard();
	void SetTopCard(Card cardToAdd);
	Card LookAtTopCard();
	int GetLength();
};