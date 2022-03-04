#include "Game.h"
#include "Deck.h"
#include "Card.h"
#include "Grid.h"

Game::Game()
{
	list<Card> royalsFound;
	for (int collumn = 0; collumn < 3; collumn++)
	{
		for (int row = 0; row < 3; row++)
		{
			if (row != 1 || collumn != 1)
			{
				while (stoi(playerDeck.LookAtTopCard().GetFaceValue().substr(0, 2)) > 10)
				{
					royalsFound.push_front(playerDeck.GetTopCard());
				}
				playerGrid.AddCard(playerDeck.GetTopCard(), new int[2]{ row,collumn });
			}
		}
	}
	while (!royalsFound.empty())
	{
		PlaceRoyal(royalsFound.back());
		royalsFound.pop_back();
	}
	while (playerDeck.GetLength() > 0 && currentCard.GetFaceValue() != Card().GetFaceValue()) {

	}
}


void Game::DisplayGrid()
{
	for (int row = 0; row < 3; row++)
	{
		for (int cardLayer = 0; cardLayer < 9; cardLayer++)
		{
			for (int collumn = 0; collumn < 3; collumn++)
			{
				playerGrid.GetCard(new int[2]{ collumn,row }).DisplayFaceValue(cardLayer);
			}
			cout << endl;
		}
	}
}

void Game::DisplayCard()
{
	for (int cardLayer = 0; cardLayer < 9; cardLayer++)
	{
		currentCard.DisplayFaceValue(cardLayer);
		cout << endl;
	}
}

void Game::PlaceCurrentCard(int coordinate[2])
{
	if (stoi(currentCard.GetFaceValue().substr(0, 2)) >= stoi(playerGrid.GetCard(coordinate).GetFaceValue().substr(0, 2)))
	{
		playerGrid.AddCard(currentCard, coordinate);
		currentCard = playerDeck.GetTopCard();
		while (stoi(currentCard.GetFaceValue().substr(0,2)) > 10)
		{
			PlaceRoyal(currentCard);
		}
	}
	else
	{

	}
}

void Game::PlaceRoyal(Card royal)
{

}


