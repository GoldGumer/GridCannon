#include "Grid.h"

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
	outerRoyals[coordinate[0]][coordinate[1]] = cardToAdd;
}

Card Grid::GetRoyal(int coordinate[2])
{
	return outerRoyals[coordinate[0]][coordinate[1]];
}
