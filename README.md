# GridCannon

## Premise
You are trying to kill the royals of the deck by adding together two cards so that their value is more than or equal to that of the royals value.

## [How To Play](https://www.pentadact.com/2019-08-20-gridcannon-a-single-player-game-with-regular-playing-cards/)

### Placing cards
You as a the player can place cards in the middle 3x3 grid. These cards must always be placed ontop of other cards or empty spaces.
You cannot place a lower valued card ontop of a higher value one (e.g. 2 ontop of a 5). You cannot place cards outside the 3x3 grid.
A card can be placed by typing in the console `play card x y` where x and y are the coordinates you want to place it (e.g. `play card 1 2`),
x coresponds to the horizontal place, starting from 0 on the left and incresing as you move to the right, and y to the vertical place, starting from
0 on the bottom and increasing as you move up.

### Ploys
As you play you will collect ploys. These ploys can be used once per card and are used to manipulate already placed cards. Here's what they do and how to use them :
- Ace : Returns a pile from the grid to the bottom of the deck. Use `ploy ace x y` to activate an ace ploy.
- Joker : Moves the top card of a pile to the top of another pile. Use `ploy joker x1 y1 x2 y2` to move the card at `x1 y1` to `x2 y2`.

### Killing Royals
As royals are drawn from the deck they are placed autmatically around the perimiter of the grid according to these rules in order of significance:
1. Same suit as the royal.
2. Same colour as the royal.
3. Highest value.

Once a royal is placed no other royal can be placed on the same square, even if they are killed. Royals can be killed if you place a card 2 spaces away from the royal
and the sum of the two cards between the just placed card and the royal is higher than or equal to the royals value. The royal costs go like this:
- King : 13
- Queen : 12
- Jack : 11

### End Of The Game
The game officially ends when the last card is drawn.

## Known Bugs
- Sometimes some royals are not placed
- On earlier builds the game crashed when starting the game(not sure if it still happens)

## References

Gridcannon: A Single Player Game With Regular Playing Cards - a post on Tom Francis’ blog. (2019, August 20). https://www.pentadact.com/2019-08-20-gridcannon-a-single-player-game-with-regular-playing-cards/
