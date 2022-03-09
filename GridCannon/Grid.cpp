#include "Grid.h"

//public

void Grid::AddCard(Card cardToAdd, int coordinate[2])
{
	playingField[coordinate[0]][coordinate[1]].push_front(cardToAdd);
}

Card Grid::GetCard(int coordinate[2])
{
	if (playingField[coordinate[0]][coordinate[1]].empty())
	{
		return Card();
	}
	else 
	{
		return playingField[coordinate[0]][coordinate[1]].front();
	}
	
}

/*
Royals go around the main grid so
the array will be 4 rows one for
each cardinal direction going in
order of North, East, South, West
being rows 0, 1 ,2 ,3
*/

void Grid::AddRoyal(Card cardToAdd, int coordinate[2])
{
	royals[coordinate[0]][coordinate[1]] = cardToAdd;
}

Card Grid::GetRoyal(int coordinate[2])
{
	if (coordinate[0] < 0) coordinate[0] = 0;
	else if (coordinate[0] > 3) coordinate[0] = 3;
	if (coordinate[1] < 0)coordinate[1] = 0;
	else if (coordinate[1] > 2)coordinate[1] = 2;
	return royals[coordinate[0]][coordinate[1]];
}

void Grid::Display()
{
	//The grid is setup in a way where cards will be added from left to right on each row
	//because of this we have to loop throught collumns first then rows
	//We do 2 extra loops for row since we need one before and after the playerField is displayed to show royals
	for (int row = 0; row < 5; row++)
	{
		for (int cardLayer = 0; cardLayer < 9; cardLayer++)
		{
			if (row == 0 || row == 4) 
			{
				Card().Display(cardLayer);
				for (int collumn = 0; collumn < 3; collumn++)
				{
					if (row == 0)
					{
						GetRoyal(new int[2]{ 0, collumn }).Display(cardLayer);
					}
					else
					{
						GetRoyal(new int[2]{ 2, collumn }).Display(cardLayer);
					}
				}
				Card().Display(cardLayer);
			}
			else
			{
				//We display a card before and after the collumn to get the royals in
				GetRoyal(new int[2]{ 3, 3 - row }).Display(cardLayer);
				for (int collumn = 0; collumn < 3; collumn++)
				{
					GetCard(new int[2]{ row - 1,collumn }).Display(cardLayer);
				}
				GetRoyal(new int[2]{ 1, row - 1 }).Display(cardLayer);
			}
			cout << endl;
		}
	}
}

void Grid::PlaceRoyal(Card royal)
{
	Card bestFitCard;
	int position[2] = { 3 };
	for (int row = 0; row < 3; row++)
	{
		for (int collumn = 0; collumn < 3; collumn++)
		{
			if (row != 1 || collumn != 1)
			{
				Card cardBeingChecked = GetCard(new int[2]{ row, collumn });
				if (royal.GetSuit() == cardBeingChecked.GetSuit())
				{
					if (bestFitCard.GetSuit() != cardBeingChecked.GetSuit())
					{
						bestFitCard = cardBeingChecked;
						position[0] = row;
						position[1] = collumn;
					}
					else if (bestFitCard.GetValue() < cardBeingChecked.GetValue())
					{
						bestFitCard = cardBeingChecked;
						position[0] = row;
						position[1] = collumn;
					}
				}
				else if ((bestFitCard.GetSuit() != royal.GetSuit()) && (royal.GetSuit() - 2 == cardBeingChecked.GetSuit() || royal.GetSuit() + 2 == cardBeingChecked.GetSuit()))
				{
					if (bestFitCard.GetSuit() != cardBeingChecked.GetSuit())
					{
						bestFitCard = cardBeingChecked;
						position[0] = row;
						position[1] = collumn;
					}
					else if (bestFitCard.GetValue() < cardBeingChecked.GetValue())
					{
						bestFitCard = cardBeingChecked;
						position[0] = row;
						position[1] = collumn;
					}
				}
				else if ((bestFitCard.GetSuit() != royal.GetSuit() || royal.GetSuit() - 2 != bestFitCard.GetSuit() || royal.GetSuit() + 2 != bestFitCard.GetSuit()) && (bestFitCard.GetValue() < cardBeingChecked.GetValue()) )
				{
					bestFitCard = cardBeingChecked;
					position[0] = row;
					position[1] = collumn;
				}
			}
		}
	}

	
}