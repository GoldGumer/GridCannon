#include "Deck.h"
#include "Card.h"
using namespace std;

void Deck::OverHandShfl()
{
	list<Card>::reverse_iterator pointer = playerCards.rbegin();
	while (pointer != playerCards.rend())
	{
		
	}
}

void Deck::FaroShfl()
{
	list<Card>::iterator pointer = playerCards.begin();
	advance(pointer, 28);
	for (int i = 0; i < 27; i++)
	{
		pointer++;
		playerCards.splice(pointer, playerCards, playerCards.begin());
	}
}

void Deck::Cut()
{
	list<Card>::iterator pointer = playerCards.begin();
	advance(pointer, rand() % 9 + 23);
	playerCards.splice(playerCards.begin(), playerCards, pointer, playerCards.end());
}

void Deck::Shuffle()
{
	for (int i = 0; i < 6; i++)
	{
		srand((unsigned int)time(0));
		OverHandShfl();
		Cut();
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

	Shuffle();
}

Card Deck::GetTopCard()
{
	return playerCards.front();
	playerCards.pop_front();
}

void Deck::SetTopCard(Card cardToAdd)
{
	int iterations = playerCards.size();
	playerCards.push_front(cardToAdd);
	for (int i = 0; i < iterations; i++)
	{
		playerCards.push_front(playerCards.front());
		playerCards.pop_front();
	}
}

Card Deck::LookAtTopCard()
{
	return playerCards.front();
}

int Deck::GetLength()
{
	return playerCards.size();
}
