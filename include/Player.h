#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <vector>

#include "Hand.h"
#include "Deck.h"

using namespace std;

class Player : public Hand {
private:
	const string name;




public:
 string type;
	Player(string name,string type);
	Player(const Player &anotherPlayer);
	virtual void Play(vector<Player*> &players);
	virtual string findCardToAskFor()=0;
	 virtual vector<Card*> request(vector<Player*> players,string valueToRequest);
		virtual Player* findPlayerToAsk(vector<Player*> &players)=0;
	void takeFromDeck(int num);
	void addCard(Card& card);
	void addCards(vector<Card*> cards);
	 bool checkForHand(Card& card);
   virtual void setType(string type);
	 virtual string getType();
	string getName();   //Returns the name of the player
	string getCards();
	Player* getPlayer();
	//virtual ~Player();

};

class PlayerType1 : public Player {  //For strategy 1
//private:

public:
	PlayerType1(string name);
	PlayerType1(const PlayerType1 &anotherPlayer);
	Player* findPlayerToAsk(vector<Player*> &players);
	string findCardToAskFor();
	 void setType(string type);
	 string getType();






};

class PlayerType2: public Player {  //For strategy 2
public:
	PlayerType2(string name);
	PlayerType2(const PlayerType2 &anotherPlayer);
	Player* findPlayerToAsk(vector<Player*> &players);
	string findCardToAskFor();
	void setType(string type);
	string getType();
};

class PlayerType3: public Player {  //For strategy 3
private:
	int currentIdx=0;
public:
	PlayerType3(string name);
	PlayerType3(const PlayerType3 &anotherPlayer);
	Player* findPlayerToAsk(vector<Player*> &players);
	string findCardToAskFor();
	void setType(string type);
	string getType();
};

class PlayerType4 : public Player {  //For strategy 4
private:
	int currentIdx=0;
public:
	PlayerType4(string name);
	PlayerType4(const PlayerType4 &anotherPlayer);
	Player* findPlayerToAsk(vector<Player*> &players);
	string findCardToAskFor();
	void setType(string type);
	string getType();

};

#endif
