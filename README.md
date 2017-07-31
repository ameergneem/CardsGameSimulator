# CardsGameSimulator
Program that simulate cards game (reviiyot) with specific rules:

1. Each player has a unique name and a position around the table (Ex: Sarah at position 1, Yossi at position 2, Ruth at position 3, defined by the order at the input configuration file, see below). In the rest of this document we will use the pseudo names: Player1, Player2, etc. according to their allocation order.

 2. Each player gets 7 cards from the shuffled deck of cards, starting with Player1. All 7 cards are distributed at once before moving to the next player.

 3. A player that received 4 cards of a single value discards the set from his hand before the first play of the first player.

 4. Player1 plays first followed by Player2, Player3, … 

 5. At his/her turn, the player, according to his/her strategy, asks another player for a card of a specific value (2-N, Jack, Queen, King and Ace). The asking player can ask only for values that he/she holds at least one card of that same value. If the asked player holds K(>0) cards of that value he/she has to give all of his/her cards of that value to the asking player and draw K (see 6) new cards from the top of the deck. If the asked player doesn't have any card of that value the asking player picks up one card from the top of the deck.

6. A player draws card(s) from the deck ONLY if his/her hand is not empty, regardless if he/she is the asking or the asked player.

7. Any player that has all 4 cards of a single value discards the set from his hand. Be sure to handle all possible ways to complete a set.

8. The turn moves on to the next player after each turn regardless of the outcome of the current player.

9. If the deck of cards is empty the game continues without drawing new cards.

10.Each turn is played to its completion, i.e. asking player and asked player get to fulfill their actions (steps 5-7) – Hand over cards, draw cards, discard sets.

11.The first player(s) that gets rid of his/her cards wins and the game ends. Be aware that two players can win the game simultaneously.

Player Strategies:

PlayerType1: Requests the value he has the most from the player with most cards at hand. In case he has two or more values with the same highest amount, choose the higher value. In case two players have the most amount of cards, choose the one with the higher position. 

Ex: The player’s hand is 2, 2, 3, 3, 3, 6, 6, 6, K, K. Choose: 6.

PlayerType2: Requests the value he has the least from the player with most cards at hand. In case he has two or more values with the lowest amount, choose the lower value. In case two players have the most amount of cards, choose the one with higher position. 

Ex: The player’s hand is 2, 2, 3, 3, 3, 6, 6, 6, K, K. Choose: 2.


PlayerType3: Start from the first player (except for oneself), move to the next one at each turn in a cyclic order. The player requests for the highest value he/she has at hand. 

Ex: The player’s hand is 2, 2, 3, 3, 3, 6, 6, 6, K, K. Choose: K.

PlayerType4: Start from the first player (except for oneself), move to the next one at each turn in a cyclic order. The player requests for the lowest value he/she has at hand. 

Ex: The player’s hand is 2, 2, 3, 3, 3, 6, 6, 6, K, K. Choose: 2.



![Alt text](/relative/path/to/Capture.PNG?raw=true "Optional Title")

