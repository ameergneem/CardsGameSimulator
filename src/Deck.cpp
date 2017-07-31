#include"../include/Deck.h"
#include "../include/Card.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;




Deck::Deck():deck(),numberOfCards(0){}
Deck::Deck(const Deck &anotherDeck):deck(),numberOfCards(anotherDeck.numberOfCards){
int n=anotherDeck.deck.size();
for(int i=0;i<n;i++){
  if(anotherDeck.deck[i]->getValue()=="Number"){
  addCard(*(new NumericCard(*((NumericCard*)anotherDeck.deck[i]))));
}else{
  addCard(*(new FigureCard(*((FigureCard*)anotherDeck.deck[i]))));
  }
}


}

void Deck::addCard(Card& card){
deck.push_back(&card);

}

string Deck::toString(){


vector<Card*>::iterator it;
string str;


int i=0,size = deck.size();
for(i=size-1;i>=0;i--){
  str.append(deck[i]->toString());
     str.append(" ");
}

return str;

      }

Card* Deck::fetchCard(){
  Card& card = *(deck.back());
  deck.pop_back();

  return &card;
}
int Deck::getNumberOfCards(){

  return deck.size();
}
Deck::~Deck(){

  // int count = deck.size();
  // for(int i=0;i<count;i++){delete deck[i];}
  // deck.clear();
}
Deck& Deck::operator=( Deck &anotherDeck){
  if(this==&anotherDeck){
    return *this;
  }
  int count=anotherDeck.getNumberOfCards();
  for(int i=0;i<count;i++){
    if(anotherDeck.deck[i]->getValue()=="Number"){
    Card* card = new NumericCard(*((NumericCard*)anotherDeck.deck[i]));
    addCard(*card);
  }else{
    Card* card = new FigureCard(*((FigureCard*)anotherDeck.deck[i]));
    addCard(*card);
  }
  }
  return *this;
}
void Deck::shuffle(){
  random_shuffle(deck.begin(),deck.end());
}
