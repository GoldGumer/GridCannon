#include "Deck.h"
#include "Card.h"
using namespace std;

//private


//Realistic over hand shuffle implementation using one list and two iterators
//Higher deviation = more random card placements
//fixedAmountTaken should be set higher the bigger the deck
void Deck::OverHandShuffle(int deviation, int fixedAmountTaken)
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

//Moves one half of the deck over the other half
void Deck::Cut(int deviation)
{
	if (deviation < (GetLength() / 2))
	{
		list<Card>::iterator it = playerCards.begin();
		advance(it, rand() % deviation + (GetLength() / 2) - ((deviation - 1) / 2));
		playerCards.splice(playerCards.begin(), playerCards, it, playerCards.end());
	}
}

void Deck::Shuffle()
{
	for (int i = 0; i < 25; i++)
	{
		srand((unsigned int)time(0) + i);
		OverHandShuffle(19, 9);
		Cut(10);
	}
}

//public

Deck::Deck()
{
	///Makes french style deck with 2 jokers
	for (int suit = 1; suit < 5; suit++)
	{
		for (int value = 9; value < 14; value++)
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

void Deck::PushBack(list<Card> pileToAdd)
{
	playerCards.splice(playerCards.end(), pileToAdd);
}

Card Deck::LookAtTopCard()
{
	if (GetLength() <= 0) return Card();
	return playerCards.front();
}

//Same as LookAtTopCard() but gets rid of the top card as well
Card Deck::GetTopCard()
{
	Card topCard = LookAtTopCard();
	playerCards.pop_front();
	return topCard;
}

int Deck::GetLength()
{
	return playerCards.size();
}
