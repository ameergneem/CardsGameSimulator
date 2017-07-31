#ifndef HAND_H_
#define HAND_H_

#include <iostream>
#include <vector>
#include "Card.h"



using namespace std;

class Hand {
private:
	vector<Card*> hand;// Declare here the collection of "Card *" of the hand
	string playerName;
	int numberOfCards;


public:
	Hand(string playerName);
	Hand(const Hand &anotherHand);
	bool addCard(Card &card);
	vector<Card*> getCards(string value,string reason);
	bool removeCard(Card &card,string reason);
	bool removeSet(string valueType,string value);
	int getNumberOfCards(); // Get the number of cards in hand
	string toString(); // Return a list of the cards, separated by space, in one line,
 //in a sorted order, ex: "2S 5D 10H"
 string getFullCardName(int i , int j);
 void deleteCard(Card& card,string reason);
  Hand* getHand();
	string printCardsFromVector();
	Hand& operator=( Hand &anotherHand);
	  virtual ~Hand();


};

#endif
