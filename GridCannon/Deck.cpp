#include "Deck.h"
#include "Card.h"
#include <stack>
using namespace std;

void Deck::OverHandShuffle()
{
	bool shuffled = false;
	stack<Card> shuffledDeck;
	while (!shuffled)
	{
		int iterations = 0;
		if (playerDeck.size() > 5)
		{
			iterations = rand() % 5 + 1;
		}
		else
		{
			iterations = playerDeck.size();
			shuffled = true;
		}
		
		/*
		using 2 stacks since you need to reverse the first stack
		essentially [1,2,3,4,5,6,7,8,9,10] are the inputs then this will output something along the lines of [9,10,6,7,8,5,2,3,4,1] 
		accurate overhand shuffle
		*/

		stack<Card> reverseDeck;
		for (int i = 0; i < iterations; i++)
		{
			reverseDeck.push(playerDeck.front());
			playerDeck.pop();
		}
		for (int i = 0; i < iterations; i++)
		{
			shuffledDeck.push(reverseDeck.top());
			reverseDeck.pop();
		}

	}
	int iterations = shuffledDeck.size();
	for (int i = 0; i < iterations; i++)
	{
		playerDeck.push(shuffledDeck.top());
		shuffledDeck.pop();
	}
}

void Deck::CuttingTheDeck()
{
	/*
	[1,2,3,4,5,6,7,8,9,10] into [6,7,8,9,10,1,2,3,4,5]
	*/
	stack<Card> cutDeck;
	for (int i = 0; i < 2; i++)
	{
		
		int iterations;
		switch (i) {
		case 0:
			iterations = rand() % 10 + 27;
			break;
		case 1:
			iterations = playerDeck.size();
			break;
		}


		stack<Card> reverseDeck;
		for (int i = 0; i < iterations; i++)
		{
			reverseDeck.push(playerDeck.front());
			playerDeck.pop();
		}
		for (int i = 0; i < iterations; i++)
		{
			cutDeck.push(reverseDeck.top());
			reverseDeck.pop();
		}
	}
	int iterations = cutDeck.size();
	for (int i = 0; i < iterations; i++)
	{
		playerDeck.push(cutDeck.top());
		cutDeck.pop();
	}
}

void Deck::Shuffle()
{
	for (int i = 0; i < 6; i++)
	{
		srand((unsigned int)time(0));
		OverHandShuffle();
	}
}

Deck::Deck()
{
	for (int suit = 0; suit < 4; suit++)
	{
		for (int value = 0; value < 14; value++)
		{
			string facevalue = "999";
			if (value < 10) {
				facevalue = "0" + to_string(value) + to_string(suit);
			}
			else {
				facevalue = to_string(value) + to_string(suit);
			}

			playerDeck.push(Card(facevalue));
		}
	}

	Shuffle();
}

Card Deck::GetTopCard()
{
	return playerDeck.front();
	playerDeck.pop();
}

void Deck::SetTopCard(Card cardToAdd)
{
	int iterations = playerDeck.size();
	playerDeck.push(cardToAdd);
	for (int i = 0; i < iterations; i++)
	{
		playerDeck.push(playerDeck.front());
		playerDeck.pop();
	}
}

Card Deck::LookAtTopCard()
{
	return playerDeck.front();
}

int Deck::GetDeckLength()
{
	return playerDeck.size();
}
