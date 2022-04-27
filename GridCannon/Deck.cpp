#include "Deck.h"
#include "Card.h"
using namespace std;

//private

void Deck::OverHandShfl(int deviation, int fixedAmountTaken)
{
	list<Card>::iterator topIt = playerCards.begin();
	list<Card>::iterator botIt = playerCards.end();
	while (distance(topIt, botIt) >= fixedAmountTaken + deviation)
	{
		int randInt = rand() % deviation + fixedAmountTaken;
		advance(topIt, randInt);
		playerCards.splice(botIt, playerCards, playerCards.begin(), topIt);
		advance(botIt, -randInt);
	}
}

void Deck::Cut(int deviation)
{
	list<Card>::iterator it = playerCards.begin();
	advance(it, rand() % deviation + (GetLength() / 2) - ((deviation - 1) / 2));
	playerCards.splice(playerCards.begin(), playerCards, it, playerCards.end());
}

void Deck::Shuffle()
{
	for (int i = 0; i < 25; i++)
	{
		srand((unsigned int)time(0) + i);
		OverHandShfl(19, 9);
		Cut(10);
	}
}

//public

Deck::Deck()
{
	for (int suit = 1; suit < 5; suit++)
	{
		for (int value = 1; value < 14; value++)
		{
			string facevalue = "999";
			if (value < 10)
			{
				facevalue = "0" + to_string(value) + to_string(suit);
			}
			else
			{
				facevalue = to_string(value) + to_string(suit);
			}

			playerCards.push_front(Card(facevalue));
		}
	}
	for (int i = 0; i < 2; i++) playerCards.push_back(Card("000"));
	Shuffle();
}

Card Deck::GetTopCard()
{
	if (playerCards.size() <= 0) return Card();
	Card topCard = playerCards.front();
	playerCards.pop_front();
	return topCard;
}

void Deck::PushBack(list<Card> pileToAdd)
{
	playerCards.splice(playerCards.end(), pileToAdd);
}

Card Deck::LookAtTopCard()
{
	if (playerCards.size() <= 0) return Card();
	return playerCards.front();
}

int Deck::GetLength()
{
	return playerCards.size();
}
