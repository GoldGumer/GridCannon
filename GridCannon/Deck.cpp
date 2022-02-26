#include "Deck.h"
#include "Card.h"
using namespace std;

void Deck::OverHandShfl(int deviation, int fixedAmountTaken)
{
	list<Card>::iterator topIt = playerCards.begin();
	list<Card>::iterator botIt = playerCards.end();
	while (distance(topIt, botIt) >= fixedAmountTaken + deviation - 1)
	{
		int randInt = rand() % deviation + fixedAmountTaken;
		advance(topIt, randInt);
		playerCards.splice(botIt, playerCards, playerCards.begin(), topIt);
		advance(botIt, -randInt);
	}
}

void Deck::FaroShfl()
{

}

void Deck::Cut(int deviation)
{
	list<Card>::iterator it = playerCards.begin();
	advance(it, rand() % deviation + (GetLength() / 2) - ((deviation - 1) / 2));
	playerCards.splice(playerCards.begin(), playerCards, it, playerCards.end());
}

void Deck::Shuffle()
{
	for (int i = 0; i < 6; i++)
	{
		srand((unsigned int)time(0));
		OverHandShfl(5, 5);
		Cut(9);
	}
}

Deck::Deck()
{
	for (int suit = 0; suit < 4; suit++)
	{
		for (int value = 0; value < 13; value++)
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
	for (int i = 0; i < 2; i++) playerCards.push_back(Card("134"));
	Shuffle();
}

Card Deck::GetTopCard()
{
	return playerCards.front();
	playerCards.pop_front();
}

void Deck::SetTopCard(Card cardToAdd)
{
	playerCards.push_front(cardToAdd);
}

Card Deck::LookAtTopCard()
{
	return playerCards.front();
}

int Deck::GetLength()
{
	return playerCards.size();
}
