#include "Grid.h"

void Grid::AddCardToPos(Card cardToAdd, int coordinate[2])
{
	playingField[coordinate[0]][coordinate[1]].push_front(cardToAdd);
}

Card Grid::GetCardAtPos(int coordinate[2])
{
	return playingField[coordinate[0]][coordinate[1]].front();
}

void Grid::AddRoyalToPos(Card cardToAdd, int coordinate[2])
{
	outerRoyals[coordinate[0]][coordinate[1]] = cardToAdd;
}

Card Grid::GetRoyalAtPos(int coordinate[2])
{
	return outerRoyals[coordinate[0]][coordinate[1]];
}
