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

void Game::PlaceCard(int coordinate[2])
{
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

void Game::InputManager()
{
	string playerInput;
	cin >> playerInput;
	if (playerInput.find("card") != string::npos)
	{
		string coord[2];
		cin >> playerInput;

		coord[0] = playerInput;
	}
	else if (playerInput.find("ploy") != string::npos)
	{
		if (playerInput.find("ace") != string::npos)
		{
			//playerGrid.ActivatePloy(true);
		}
		else if (playerInput.find("joker") != string::npos)
		{
			//playerGrid.ActivatePloy(false);
		}
	}
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
		InputManager();
		system("CLS");
		//"evil way" https://www.cplusplus.com/articles/4z18T05o/
	}
}