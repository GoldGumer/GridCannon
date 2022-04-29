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
		playerGrid.CannonActivation(coordinate);
		while (playerDeck.LookAtTopCard().GetValue() > 10 || playerDeck.LookAtTopCard().GetValue() < 2)
		{
			if (playerDeck.LookAtTopCard().GetValue() > 10)
			{
				playerGrid.AddRoyal(playerDeck.GetTopCard());
			}
			else
			{
				playerGrid.AddPloy(playerDeck.GetTopCard());
			}
		}
		currentCard = playerDeck.GetTopCard();
	}
}

void Game::InputManager()
{
	string playerInput;
	cin >> playerInput;
	if (playerInput == "play")
	{
		cin >> playerInput;
		if (playerInput == "card")
		{
			string coordStrInput[2] = { "0" };
			cin >> coordStrInput[1];
			cin >> coordStrInput[0];
			// use atoi() as it gives back 0 if string is included with some ints
			// whereas stoi() just crashes with the same inputs
			int coordIntInput[2] = { atoi(coordStrInput[0].c_str()), atoi(coordStrInput[1].c_str()) };
			if (coordIntInput[0] > 0 && coordIntInput[0] < 4 && coordIntInput[1] > 0 && coordIntInput[1] < 4)
			{
				PlaceCard(new int[2]{ 3 - coordIntInput[0], coordIntInput[1] - 1 });
			}
		}
	}
	else if (playerInput == "ploy")
	{
		cin >> playerInput;
		if (playerInput == "ace")
		{
			string coordStrInput[2] = { "0" };
			cin >> coordStrInput[1];
			cin >> coordStrInput[0];
			int coordIntInput[2] = { atoi(coordStrInput[0].c_str()), atoi(coordStrInput[1].c_str()) };
			if (coordIntInput[0] > 0 && coordIntInput[0] < 4 && coordIntInput[1] > 0 && coordIntInput[1] < 4)
			{
				playerDeck.PushBack(playerGrid.PloyAce(new int[2]{ 3 - coordIntInput[0], coordIntInput[1] - 1 }));
			}
		}
		else if (playerInput == "joker")
		{
			string coordStrInput[4] = { "0" };
			cin >> coordStrInput[1];
			cin >> coordStrInput[0];
			cin >> coordStrInput[3];
			cin >> coordStrInput[2];
			int coordIntInput[4] = { atoi(coordStrInput[0].c_str()), atoi(coordStrInput[1].c_str()), atoi(coordStrInput[2].c_str()), atoi(coordStrInput[3].c_str()) };
			if (coordIntInput[0] > 0 && coordIntInput[0] < 4 && coordIntInput[1] > 0 && coordIntInput[1] < 4 && coordIntInput[2] > 0 && coordIntInput[2] < 4 && coordIntInput[3] > 0 && coordIntInput[3] < 4 &&
				playerGrid.GetCard(new int[2]{ 3 - coordIntInput[0], coordIntInput[1] - 1 }).GetValue() >= playerGrid.GetCard(new int[2]{ 3 - coordIntInput[2], coordIntInput[3] - 1 }).GetValue())
			{
				playerGrid.PloyJoker(new int[2]{ 3 - coordIntInput[0], coordIntInput[1] - 1 }, new int[2]{ 3 - coordIntInput[2], coordIntInput[3] - 1 });
			}
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
				while (playerDeck.LookAtTopCard().GetValue() > 10 || playerDeck.LookAtTopCard().GetValue() < 2)
				{
					if (playerDeck.LookAtTopCard().GetValue() > 10)
					{
						royalsFound.push_front(playerDeck.GetTopCard());
					}
					else
					{
						playerGrid.AddPloy(playerDeck.GetTopCard());
					}
				}
				playerGrid.AddCard(playerDeck.GetTopCard(), new int[2]{ row,collumn });
			}
		}
	}

	while (!royalsFound.empty())
	{
		playerGrid.AddRoyal(royalsFound.back());
		royalsFound.pop_back();
	}

	while (currentCard.GetValue() > 10 || currentCard.GetValue() < 2)
	{
		if (currentCard.GetValue() > 10)
		{
			playerGrid.AddRoyal(currentCard);
			currentCard = playerDeck.GetTopCard();
		}
		else if (currentCard.GetValue() < 2)
		{
			playerGrid.AddPloy(currentCard);
			currentCard = playerDeck.GetTopCard();
		}
	}

	while (playerDeck.GetLength() > 0 && currentCard.GetValue() != Card().GetValue())
	{
		//system("CLS");
		//"evil way" https://www.cplusplus.com/articles/4z18T05o/
		playerGrid.Display();
		DisplayCard();
		InputManager();
	}
}