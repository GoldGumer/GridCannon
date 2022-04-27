#include "Grid.h"

//private

int* Grid::NearestRoyalToCard(int pos[2], bool returnVertical)
{
	switch (pos[0])
	{
	case 0:
		if (pos[1] == 1)
		{
			return new int[2]{ 0,1 };
		}
		else if (pos[1] == 0 && returnVertical)
		{
			return new int[2]{ 0,0 };
		}
		else if (pos[1] == 2 && returnVertical)
		{
			return new int[2]{ 0,2 };
		}
		else if (pos[1] == 0 && !returnVertical)
		{
			return new int[2]{ 3,2 };
		}
		else if (pos[1] == 2 && !returnVertical)
		{
			return new int[2]{ 1,0 };
		}
		break;
	case 1:
		if (pos[1] == 0)
		{
			return new int[2]{ 3,1 };
		}
		else if (pos[1] == 2)
		{
			return new int[2]{ 1,1 };
		}
		break;
	case 2:
		if (pos[1] == 1)
		{
			return new int[2]{ 2,1 };
		}
		else if (pos[1] == 0 && returnVertical)
		{
			return new int[2]{ 2,2 };
		}
		else if (pos[1] == 2 && returnVertical)
		{
			return new int[2]{ 2,0 };
		}
		else if (pos[1] == 0 && !returnVertical)
		{
			return new int[2]{ 3,0 };
		}
		else if (pos[1] == 2 && !returnVertical)
		{
			return new int[2]{ 1,2 };
		}
		break;
	default:
		break;
	}
	return new int[2]{ 0,0 };
}

//public

void Grid::CannonActivation(int coordinate[2])
{
	/*
	Write down each direction to check then add and take away from "coordinate"
	North  =   0
	East   =   1
	South  =   2
	West   =   3
	*/
	list<int> directionsToCheck;
	switch (coordinate[0])
	{
	case 0:
		switch (coordinate[1])
		{
		case 0:
			directionsToCheck.push_back(1);
			directionsToCheck.push_back(2);
			break;
		case 1:
			directionsToCheck.push_back(2);
			break;
		case 2:
			directionsToCheck.push_back(2);
			directionsToCheck.push_back(3);
			break;
		default:
			break;
		}
		break;
	case 1:
		switch (coordinate[1])
		{
		case 0:
			directionsToCheck.push_back(1);
			break;
		case 2:
			directionsToCheck.push_back(3);
			break;
		default:
			break;
		}
		break;
	case 2:
		switch (coordinate[1])
		{
		case 0:
			directionsToCheck.push_back(0);
			directionsToCheck.push_back(1);
			break;
		case 1:
			directionsToCheck.push_back(0);
			break;
		case 2:
			directionsToCheck.push_back(0);
			directionsToCheck.push_back(3);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	while (directionsToCheck.empty())
	{
		switch (directionsToCheck.front())
		{
		case 0:
			if (coordinate[1] / 2 == 1 &&
				GetRoyal(NearestRoyalToCard(new int[2]{ coordinate[0] + 2, coordinate[1] }, false)).GetValue() == Card().GetValue() &&
				GetRoyal(NearestRoyalToCard(new int[2]{ coordinate[0] + 2, coordinate[1] }, false)).GetValue() <=
				(GetCard(new int[2]{ coordinate[0] + 2, coordinate[1] }).GetValue()
					+ GetCard(new int[2]{ coordinate[0] + 1, coordinate[1] }).GetValue()))
			{
				SetRoyal(Card("999"), NearestRoyalToCard(new int[2]{ coordinate[0] + 2, coordinate[1] }, false));
			}
			else if (coordinate[1] / 2 == 0 &&
				GetRoyal(NearestRoyalToCard(new int[2]{ coordinate[0] + 2, coordinate[1] }, true)).GetValue() == Card().GetValue() &&
				GetRoyal(NearestRoyalToCard(new int[2]{ coordinate[0] + 2, coordinate[1] }, true)).GetValue() <=
				(GetCard(new int[2]{ coordinate[0] + 2, coordinate[1] }).GetValue()
					+ GetCard(new int[2]{ coordinate[0] + 1, coordinate[1] }).GetValue()))
			{
				SetRoyal(Card("999"), NearestRoyalToCard(new int[2]{ coordinate[0] + 2, coordinate[1] }, true));
			}
			break;
		case 1:
			if (coordinate[0] / 2 == 1 &&
				GetRoyal(NearestRoyalToCard(new int[2]{ coordinate[0], coordinate[1] + 2 }, false)).GetValue() == Card().GetValue() &&
				GetRoyal(NearestRoyalToCard(new int[2]{ coordinate[0], coordinate[1] + 2 }, false)).GetValue() <=
				(GetCard(new int[2]{ coordinate[0], coordinate[1] + 2 }).GetValue()
					+ GetCard(new int[2]{ coordinate[0], coordinate[1] } + 1).GetValue()))
			{
				SetRoyal(Card("999"), NearestRoyalToCard(new int[2]{ coordinate[0], coordinate[1] + 2 }, false));
			}
			else if (coordinate[0] / 2 == 0 &&
				GetRoyal(NearestRoyalToCard(new int[2]{ coordinate[0], coordinate[1] + 2 }, true)).GetValue() == Card().GetValue() &&
				GetRoyal(NearestRoyalToCard(new int[2]{ coordinate[0], coordinate[1] + 2 }, true)).GetValue() <=
				(GetCard(new int[2]{ coordinate[0], coordinate[1] + 2 }).GetValue()
					+ GetCard(new int[2]{ coordinate[0], coordinate[1] } + 1).GetValue()))
			{
				SetRoyal(Card("999"), NearestRoyalToCard(new int[2]{ coordinate[0], coordinate[1] + 2 }, true));
			}
			break;
		case 2:
			if (coordinate[1] / 2 == 0 &&
				GetRoyal(NearestRoyalToCard(new int[2]{ coordinate[0] - 2, coordinate[1] }, true)).GetValue() == Card().GetValue() &&
				GetRoyal(NearestRoyalToCard(new int[2]{ coordinate[0] - 2, coordinate[1] }, true)).GetValue() <=
				(GetCard(new int[2]{ coordinate[0] - 2, coordinate[1] }).GetValue()
					+ GetCard(new int[2]{ coordinate[0] - 1, coordinate[1] }).GetValue()))
			{
				SetRoyal(Card("999"), NearestRoyalToCard(new int[2]{ coordinate[0] - 2, coordinate[1] }, true));
			}
			else if (coordinate[1] / 2 == 1 &&
				GetRoyal(NearestRoyalToCard(new int[2]{ coordinate[0] - 2, coordinate[1] }, false)).GetValue() == Card().GetValue() &&
				GetRoyal(NearestRoyalToCard(new int[2]{ coordinate[0] - 2, coordinate[1] }, false)).GetValue() <=
				(GetCard(new int[2]{ coordinate[0] - 2, coordinate[1] }).GetValue()
					+ GetCard(new int[2]{ coordinate[0] - 1, coordinate[1] }).GetValue()))
			{
				SetRoyal(Card("999"), NearestRoyalToCard(new int[2]{ coordinate[0] - 2, coordinate[1] }, false));
			}
			break;
		case 3:
			if (coordinate[0] / 2 == 0 &&
				GetRoyal(NearestRoyalToCard(new int[2]{ coordinate[0], coordinate[1] + 2 }, true)).GetValue() == Card().GetValue() &&
				GetRoyal(NearestRoyalToCard(new int[2]{ coordinate[0], coordinate[1] + 2 }, true)).GetValue() <=
				(GetCard(new int[2]{ coordinate[0], coordinate[1] - 2 }).GetValue()
					+ GetCard(new int[2]{ coordinate[0], coordinate[1] - 1 }).GetValue()))
			{
				SetRoyal(Card("999"), NearestRoyalToCard(new int[2]{ coordinate[0], coordinate[1] - 2 }, true));
			}
			else if (coordinate[0] / 2 == 1 &&
				GetRoyal(NearestRoyalToCard(new int[2]{ coordinate[0], coordinate[1] - 2 }, false)).GetValue() == Card().GetValue() &&
				GetRoyal(NearestRoyalToCard(new int[2]{ coordinate[0], coordinate[1] - 2 }, false)).GetValue() <=
				(GetCard(new int[2]{ coordinate[0], coordinate[1] - 2 }).GetValue()
					+ GetCard(new int[2]{ coordinate[0], coordinate[1] - 1 }).GetValue()))
			{
				SetRoyal(Card("999"), NearestRoyalToCard(new int[2]{ coordinate[0], coordinate[1] - 2 }, false));
			}
			break;
		default:
			break;
		}
		directionsToCheck.pop_front();
	}
}

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

void Grid::SetRoyal(Card cardToAdd, int coordinate[2])
{
	if (coordinate[0] > 3) coordinate[0] = 3;
	else if (coordinate[0] < 0) coordinate[0] = 0;
	if (coordinate[1] > 2) coordinate[0] = 2;
	else if (coordinate[1] < 0) coordinate[0] = 0;

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

void Grid::AddPloy(Card ployCard)
{
	switch (ployCard.GetSuit())
	{
	//checking if the suit is 0 since joker is the only card with suit 0
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
	list<Card> pile = playingField[coordinate[0]][coordinate[1]];
	pile.reverse();
	for (int i = 0; i < 4; i++)
	{
		if (ploys[i].GetValue() >= 0)
		{
			ploys[i] = Card("999");
			break;
		}
	}
	playingField[coordinate[0]][coordinate[1]].clear();
	return pile;
}

void Grid::PloyJoker(int cardToMove[2], int placeToMove[2])
{
	playingField[placeToMove[0]][placeToMove[1]].push_front(playingField[cardToMove[0]][cardToMove[1]].front());
	playingField[cardToMove[0]][cardToMove[1]].pop_front();
	for (int i = 0; i < 2; i++)
	{
		if (ploys[3 + i].GetValue() >= 0)
		{
			ploys[3 + i] = Card("999");
			break;
		}
	}
}

void Grid::Display()
{
	//The grid is setup in a way where cards will be added from left to right on each row
	//because of this we have to loop throught collumns first then rows
	//We do 2 extra loops for row since we need one before and after the playerField is displayed to show royals
	for (int row = 0; row < 6; row++)
	{
		for (int cardLayer = 0; cardLayer < 9; cardLayer++)
		{
			if (row == 0 || row == 4)
			{
				Card().Display(cardLayer);
				for (int collumn = 0; collumn < 3; collumn++)
				{
					GetRoyal(new int[2]{ row / 2, row / 2 - collumn }).Display(cardLayer);
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

void Grid::AddRoyal(Card royal)
{
	int position[2] = { 0 };
	for (int row = 0; row < 3; row++)
	{
		for (int collumn = 0; collumn < 3; collumn++)
		{
			if (row != 1 || collumn != 1)
			{
				Card cardBeingChecked = GetCard(new int[2]{ row, collumn });
				for (int i = 0; i < 2; i++)
				{
					if (GetRoyal(NearestRoyalToCard(new int[2]{ row, collumn }, i)).GetValue() == Card().GetValue())
					{
						if (cardBeingChecked.GetSuit() % 2 == royal.GetSuit() % 2)
						{
							if (cardBeingChecked.GetSuit() == royal.GetSuit() && cardBeingChecked.GetValue() > GetCard(position).GetValue())
							{
								position[0] = row;
								position[1] = collumn;
							}
							else if (GetCard(position).GetSuit() != royal.GetSuit() && cardBeingChecked.GetValue() > GetCard(position).GetValue())
							{
								position[0] = row;
								position[1] = collumn;
							}
						}
						else if (cardBeingChecked.GetValue() > GetCard(position).GetValue() && GetCard(position).GetSuit() % 2 != royal.GetSuit() % 2)
						{
							position[0] = row;
							position[1] = collumn;
						}
					}
				}
			}
		}
	}
	//royal is placed
	for (int i = 0; i < 2; i++)
	{
		if (GetRoyal(NearestRoyalToCard(position, i)).GetValue() == Card().GetValue())
		{
			int* posRoyal = { NearestRoyalToCard(position, i) };
			SetRoyal(royal, posRoyal);
		}
	}
}