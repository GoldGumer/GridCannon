#pragma once
#include "Card.h"
#include <iostream>
#include <queue>

class Deck
{
private:
	queue<Card> playerDeck;
	void OverHandShuffle();
	void FaroShuffle();
	void CuttingTheDeck();
	void Shuffle();
public:
	Deck();
	Card GetTopCard();
	void SetTopCard(Card cardToAdd);
	Card LookAtTopCard();
	int GetDeckLength();
};