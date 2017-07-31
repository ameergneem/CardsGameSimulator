#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include<fstream>
#include <vector>
#include "Player.h"
#include "Deck.h"

using namespace std;

class Game {
private:
 vector<Player*> players;  //The list of the players
  int verbal,cardsNum,count=0,numberOfTurns;
  string cardsNames,currentState,playersNames,winners;
  vector<Card*> cards;
	Deck deck;         //The deck of the game
	vector<Player*> getPlayersFromString(istringstream str);
	void setCardsToMainDeck(int N,string cardsOrder);
	void setPlayers(string names,Deck* deck);
	string getStringFromFile(ifstream inFile);
  void parseFile(char* fileName);
  void initCardsFullMap();
	bool checkWinner();
  void setCurrentState(int turnNumber);
public:
	Game(char* configurationFile);
 Game(const Game &anotherGame);
 void takeInitState();
  Game& operator=( Game &anotherGame);
	void init();
	void play();
	void printState();        //Print the state of the game as described in the assignment.
	void printWinner();       //Print the winner of the game as describe in the assignment.
  void printNumberOfTurns(); //Print the number of played turns at any given time.
  static int N;
 static string **cardsFullMap;
 static string currentMove,initState;
 static Deck* deckMain;
	void printMap();
	void example();
	void pringPlayers(vector<Player*>players,Deck*deck2);
  ~Game();
};

#endif
