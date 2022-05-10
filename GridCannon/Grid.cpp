#include "Grid.h"

//private

int* Grid::NearestRoyalToCard(int pos[2], bool returnVertical)
{
	int intToReturn[2] = { 0,0 };
	switch (pos[0])
	{
	case 0:
		if (pos[1] == 1)
		{
			intToReturn[0] = 0;
			intToReturn[1] = 1;
		}
		else if (pos[1] == 0 && returnVertical)
		{
			intToReturn[0] = 0;
			intToReturn[1] = 0;
		}
		else if (pos[1] == 2 && returnVertical)
		{
			intToReturn[0] = 0;
			intToReturn[1] = 2;
		}
		else if (pos[1] == 0 && !returnVertical)
		{
			intToReturn[0] = 3;
			intToReturn[1] = 2;
		}
		else if (pos[1] == 2 && !returnVertical)
		{
			intToReturn[0] = 1;
			intToReturn[1] = 0;
		}
		break;
	case 1:
		if (pos[1] == 0)
		{
			intToReturn[0] = 3;
			intToReturn[1] = 1;
		}
		else if (pos[1] == 2)
		{
			intToReturn[0] = 1;
			intToReturn[1] = 1;
		}
		break;
	case 2:
		if (pos[1] == 1)
		{
			intToReturn[0] = 2;
			intToReturn[1] = 1;
		}
		else if (pos[1] == 0 && returnVertical)
		{
			intToReturn[0] = 2;
			intToReturn[1] = 2;
		}
		else if (pos[1] == 2 && returnVertical)
		{
			intToReturn[0] = 2;
			intToReturn[1] = 0;
		}
		else if (pos[1] == 0 && !returnVertical)
		{
			intToReturn[0] = 3;
			intToReturn[1] = 0;
		}
		else if (pos[1] == 2 && !returnVertical)
		{
			intToReturn[0] = 1;
			intToReturn[1] = 2;
		}
		break;
	default:
		break;
	}

	delete[] pos;
	pos = NULL;

	return intToReturn;
}

//public

void Grid::CannonActivation(int coordinate[2])
{
	//For loop to check both Horizontal and Vertical directions
	/*
	0 = vertical checks 
	1 = horizontal checks
	*/
	for (int i = 0; i < 2; i++)
	{
		//Defaults to 0 if its one of the middle cards
		int directionToCheck = 0;
		switch (coordinate[i])
		{
		case 0:
			//Right or Up
			directionToCheck = 1;
			break;
		case 2:
			//Left or Down
			directionToCheck = -1;
			break;
		default:
			break;
		}
		//Both come out zero if its the middle square being checked
		//One is always 0 if the other is being checked
		int horizontalMultiplier = (i * directionToCheck);
		int verticalMultiplier = (((i - 1) * -1) * directionToCheck);
		//Position is being passed since we need to change the card if the if statement is true
		int* royalPositionToCheck = NearestRoyalToCard(new int[2]{ coordinate[0] + (verticalMultiplier * 2) , coordinate[1] + (horizontalMultiplier * 2) }, !i);
		if (GetRoyal(royalPositionToCheck).GetValue() != Card().GetValue() && GetRoyal(royalPositionToCheck).GetValue() <= 
			GetCard(new int[2]{ coordinate[0] + (verticalMultiplier * 2) , coordinate[1] + (horizontalMultiplier * 2) }).GetValue() +
			GetCard(new int[2]{ coordinate[0] + (verticalMultiplier * 1) , coordinate[1] + (horizontalMultiplier * 1) }).GetValue() &&
			horizontalMultiplier != verticalMultiplier)
		{
			//"999" since it prevents another royal from being placed ontop and 
			//Also gives a blank card instead of an empty space
			SetRoyal(Card("999"), royalPositionToCheck);
		}
	}
	delete[] coordinate;
	coordinate = NULL;
}

void Grid::AddCard(Card cardToAdd, int coordinate[2])
{
	playingField[coordinate[0]][coordinate[1]].push_front(cardToAdd);
	delete[] coordinate;
	coordinate = NULL;
}

Card Grid::GetCard(int coordinate[2])
{
	Card cardToReturn;
	if (playingField[coordinate[0]][coordinate[1]].empty())
	{
		cardToReturn = Card();
	}
	else
	{
		cardToReturn = playingField[coordinate[0]][coordinate[1]].front();
	}
	delete[] coordinate;
	coordinate = NULL;

	return cardToReturn;
}

/*
Royals go around the main grid so
the array will be 4 rows one for
each cardinal direction going in
order of North, East, South, West
being rows 0, 1 ,2 ,3
*/

void Grid::SetRoyal(Card cardToAdd, int coordinate[2])
{
	if (coordinate[0] > 3) coordinate[0] = 3;
	else if (coordinate[0] < 0) coordinate[0] = 0;
	if (coordinate[1] > 2) coordinate[1] = 2;
	else if (coordinate[1] < 0) coordinate[1] = 0;

	royals[coordinate[0]][coordinate[1]] = cardToAdd;

	delete[] coordinate;
	coordinate = NULL;
}

Card Grid::GetRoyal(int coordinate[2])
{
	if (coordinate[0] < 0) coordinate[0] = 0;
	else if (coordinate[0] > 3) coordinate[0] = 3;
	if (coordinate[1] < 0)coordinate[1] = 0;
	else if (coordinate[1] > 2)coordinate[1] = 2;

	Card royalToReturn = royals[coordinate[0]][coordinate[1]];

	delete[] coordinate;
	coordinate = NULL;

	return royalToReturn;
}

void Grid::AddPloy(Card ployCard)
{
	//Checking suit since jokers are the only card with suit = 0
	//Also all aces can be sorted easily this way
	switch (ployCard.GetSuit())
	{
	
	case 0:
		if (ploys[4].GetValue() == Card().GetValue())
		{
			ploys[4] = ployCard;
		}
		else
		{
			ploys[5] = ployCard;
		}
		break;
	case 1:
		ploys[0] = ployCard;
		break;
	case 2:
		ploys[1] = ployCard;
		break;
	case 3:
		ploys[2] = ployCard;
		break;
	case 4:
		ploys[3] = ployCard;
		break;
	default:
		break;
	}
}

list<Card> Grid::PloyAce(int coordinate[2])
{
	list<Card> pile;
	for (int i = 0; i < 4; i++)
	{
		if (ploys[i].GetValue() == 1)
		{
			pile = playingField[coordinate[0]][coordinate[1]];
			pile.reverse();
			//"999" so no other ace can be placed over the top of it
			ploys[i] = Card("999");
			playingField[coordinate[0]][coordinate[1]].clear();
			break;
		}
	}
	delete[] coordinate;
	coordinate = NULL;
	return pile;
}

void Grid::PloyJoker(int cardToMove[2], int placeToMove[2])
{
	for (int i = 0; i < 2; i++)
	{
		if (ploys[3 + i].GetValue() == 0)
		{
			AddCard(GetCard(cardToMove), placeToMove);
			playingField[cardToMove[0]][cardToMove[1]].pop_front();
			CannonActivation(placeToMove);
			ploys[3 + i] = Card("999");
			break;
		}
	}
	delete[] cardToMove;
	cardToMove = NULL;

	delete[] placeToMove;
	placeToMove = NULL;
}

void Grid::Display()
{
	//The grid is setup in a way where cards will be added from left to right on each row
	//because of this we have to loop throught collumns first then rows
	//We do 3 extra loops for row since we need to display royals and ploys above and below the playingField
	for (int row = 0; row < 6; row++)
	{
		for (int cardLayer = 0; cardLayer < 9; cardLayer++)
		{
			if (row == 0 || row == 4)
			{
				Card().Display(cardLayer);
				for (int collumn = 0; collumn < 3; collumn++)
				{
					GetRoyal(new int[2]{ row / 2, abs((row / 2) - collumn) }).Display(cardLayer);
				}
				Card().Display(cardLayer);
			}
			else if (row > 0 && row < 4)
			{
				//We display a card before and after the collumn to get the royals in
				GetRoyal(new int[2]{ 3, 3 - row }).Display(cardLayer);
				for (int collumn = 0; collumn < 3; collumn++)
				{
					GetCard(new int[2]{ row - 1,collumn }).Display(cardLayer);
				}
				GetRoyal(new int[2]{ 1, row - 1 }).Display(cardLayer);
			}

			else if (row == 5)
			{
				for (int i = 0; i < 6; i++)
				{
					ploys[i].Display(cardLayer);
				}
			}
			cout << endl;
		}
	}
}

//Automatic royal adding
void Grid::AddRoyal(Card royal)
{
	int finalPosition[2] = { 1,1 };
	for (int row = 0; row < 3; row++)
	{
		for (int collumn = 0; collumn < 3; collumn++)
		{
			if (row != 1 || collumn != 1)
			{
				int newPosition[2] = { row, collumn };
				Card cardBeingChecked = GetCard(newPosition);
				for (int i = 0; i < 2; i++)
				{
					//if there's an open royal place
					if (GetRoyal(NearestRoyalToCard(newPosition, i)).GetValue() == Card().GetValue())
					{
						// if same colour as royal and not an empty card
						if (cardBeingChecked.GetSuit() % 2 == royal.GetSuit() % 2 && cardBeingChecked.GetSuit() != 0)
						{
							//if last card's suit doesn't match royals suit and new card's suit matches royal's suit
							if (GetCard(finalPosition).GetSuit() != royal.GetSuit() && cardBeingChecked.GetSuit() == royal.GetSuit())
							{
								finalPosition[0] = newPosition[0];
								finalPosition[1] = newPosition[1];
							}
							//if last card isn't same colour as royal
							else if (GetCard(finalPosition).GetSuit() % 2 != royal.GetSuit() % 2)
							{
								finalPosition[0] = newPosition[0];
								finalPosition[1] = newPosition[1];
							}
							//if last card and new card are same suit and new card is higher in value than last card
							else if (GetCard(finalPosition).GetSuit() == cardBeingChecked.GetSuit() && cardBeingChecked.GetValue() > GetCard(finalPosition).GetValue())
							{
								finalPosition[0] = newPosition[0];
								finalPosition[1] = newPosition[1];
							}
						}
						//if new card is higher than or equal to old card and old card isn't same colour as royal
						else if (cardBeingChecked.GetValue() >= GetCard(finalPosition).GetValue() && GetCard(finalPosition).GetSuit() % 2 != royal.GetSuit() % 2)
						{
							finalPosition[0] = newPosition[0];
							finalPosition[1] = newPosition[1];
						}
						//if the middle square is selected
						else if (finalPosition[0] == 1 && finalPosition[1] == 1)
						{
							finalPosition[0] = newPosition[0];
							finalPosition[1] = newPosition[1];
						}
					}
				}
			}
		}
	}
	//royal is placed
	for (int i = 0; i < 2; i++)
	{
		if (GetRoyal(NearestRoyalToCard(finalPosition, i)).GetValue() == Card().GetValue())
		{
			int* royalPosition = { NearestRoyalToCard(finalPosition, i) };
			SetRoyal(royal, royalPosition);
			break;
		}
	}
}