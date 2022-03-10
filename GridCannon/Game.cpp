#include "Game.h"
#include "Deck.h"
#include "Card.h"
#include "Grid.h"

//private

void Game::DisplayCard()
{
	for (int cardLayer = 0; cardLayer < 9; cardLayer++)
	{
		currentCard.Display(cardLayer);
		cout << endl;
	}
}

void Game::PlaceCurrentCard(int coordinate[2])
{
	//if card being placed is more than the card ontop
	if (currentCard.GetValue() >= playerGrid.GetCard(coordinate).GetValue())
	{
		playerGrid.AddCard(currentCard, coordinate);
		currentCard = playerDeck.GetTopCard();
		while (currentCard.GetValue() > 10)
		{
			playerGrid.PlaceRoyal(currentCard);
			currentCard = playerDeck.GetTopCard();
		}
	}
}

void Game::PlayerPlaceCard()
{
	int coordinate[2] = { 1 };
	for (int i = 0; i < 2; i++)
	{
		int playerInput;
		cin >> playerInput;
		if (playerInput >= 0 && playerInput <= 2)
		{
			coordinate[i] = playerInput;
		}
	}
	PlaceCurrentCard(coordinate);
}

//public

Game::Game()
{
	list<Card> royalsFound;
	for (int collumn = 0; collumn < 3; collumn++)
	{
		for (int row = 0; row < 3; row++)
		{
			if (row != 1 || collumn != 1)
			{
				while (playerDeck.LookAtTopCard().GetValue() > 10)
				{
					royalsFound.push_front(playerDeck.GetTopCard());
				}
				playerGrid.AddCard(playerDeck.GetTopCard(), new int[2]{ row,collumn });
			}
		}
	}
	while (!royalsFound.empty())
	{
		playerGrid.PlaceRoyal(royalsFound.back());
		royalsFound.pop_back();
	}
	currentCard = playerDeck.GetTopCard();
	while (playerDeck.GetLength() > 0 && currentCard.GetValue() != Card().GetValue())
	{
		playerGrid.Display();
		DisplayCard();
		PlayerPlaceCard();
		system("CLS");
		//"evil way" https://www.cplusplus.com/articles/4z18T05o/
	}
}