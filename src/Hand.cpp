#include "../include/Hand.h"
#include "../include/Game.h"


#include <iostream>

using namespace std;
#define JACK numberOfCards-4
#define QUEEN numberOfCards-3
#define KING numberOfCards-2
#define ACE numberOfCards-1


Hand::Hand(string name):hand(),playerName(name),numberOfCards(Game::N+3){


}

Hand::Hand(const Hand &anotherHand):hand(),playerName(anotherHand.playerName),numberOfCards(anotherHand.numberOfCards){
  playerName = anotherHand.playerName;
int n=anotherHand.hand.size();
for(int i=0;i<n;i++){
  if(anotherHand.hand[i]->getValue()=="Number"){
    addCard(*(new NumericCard(*((NumericCard*)anotherHand.hand[i]))));
  }else{
    addCard(*(new FigureCard(*((FigureCard*)anotherHand.hand[i]))));
  }

}

}


bool Hand::addCard(Card &card){

hand.push_back(&card);
//cout<<"Hello"<<endl;
if(card.getValue() == "Number"){
  NumericCard& numericCard = (NumericCard&)card;
  Game::cardsFullMap[numericCard.getShape()][numericCard.getNumber()-2] = playerName;


}//Number

if(card.getValue() == "Figure"){

  FigureCard& figureCard = (FigureCard&)card;
  if(figureCard.getFigureStr() == "J")
  Game::cardsFullMap[figureCard.getShape()][JACK] = playerName;

  if(figureCard.getFigureStr() == "Q")
  Game::cardsFullMap[figureCard.getShape()][QUEEN] = playerName;

  if(figureCard.getFigureStr() == "K")
  Game::cardsFullMap[figureCard.getShape()][KING] = playerName;

  if(figureCard.getFigureStr() == "A")
  Game::cardsFullMap[figureCard.getShape()][ACE] = playerName;


}//Figure

return true;
}

vector<Card*> Hand::getCards(string value,string reason){

  vector<Card*>::iterator it;
  vector<Card*> cardsToReturn;
  int num = ((int)hand.size());
  for(int i=0;i<num;i++){
if(hand[i]->getValue() == "Number"){

  NumericCard* numCard = (NumericCard*)hand[i];

    if(to_string(numCard->getNumber()) == value){
         //card = new NumericCard(*numCard);
         cardsToReturn.push_back(numCard);
}
      }else{

        FigureCard* figCard = (FigureCard*)hand[i];
        if(figCard->getFigureStr() == value){
         //card = new FigureCard(*figCard);
         cardsToReturn.push_back(figCard);
           }
      }

  }

if(cardsToReturn.size()>0){
for(it=cardsToReturn.begin();it!=cardsToReturn.end();++it)
removeCard(**it,reason);
}

return cardsToReturn;


}

bool Hand::removeSet(string valueType,string value){

  if(valueType == "Number"){
    int number = atoi(value.c_str());
    NumericCard cardC(number,Shape::Club);
    NumericCard cardD(number,Shape::Diamond);
    NumericCard cardH(number,Shape::Heart);
    NumericCard cardS(number,Shape::Spade);
    removeCard(cardC,"Hand");
    removeCard(cardD,"Hand");
    removeCard(cardH,"Hand");
    removeCard(cardS,"Hand");
    return true;
  }else{
    Figure figure;
    if(value == "J")figure = Figure::Jack;
    if(value == "Q")figure = Figure::Queen;
    if(value == "K")figure = Figure::King;
    if(value == "A")figure = Figure::Ace;

    FigureCard cardC(figure,Shape::Club);
    FigureCard cardD(figure,Shape::Diamond);
    FigureCard cardH(figure,Shape::Heart);
    FigureCard cardS(figure,Shape::Spade);
    removeCard(cardC,"Hand");
    removeCard(cardD,"Hand");
    removeCard(cardH,"Hand");
    removeCard(cardS,"Hand");
    return true;
  }

}
bool Hand::removeCard(Card &card,string reason){
 vector<Card*>::iterator it;

 for(it=hand.begin();it!=hand.end();++it){

  if((*it)->toString() == card.toString()){
    deleteCard(card,reason);
    hand.erase(it);//this makes the problem


    return true;
  }
 }
 return false;
 }

int Hand::getNumberOfCards(){
  return hand.size();
}

string Hand::toString(){//CHECK CORRECTION & SORT
  string str;
  for(int j=0;j<numberOfCards;++j){
  for(int i=0;i<4;++i){
      if(Game::cardsFullMap[i][j] == playerName)
      str.append(getFullCardName(i,j));
    }
  }

  return str;
}
string Hand::printCardsFromVector(){
  string str;
  for(int i=0;i<getNumberOfCards();i++){
    str.append(hand[i]->toString());
    str.append(" ");
  }
  return str;
}
 Hand* Hand::getHand(){
  return this;
}

string Hand::getFullCardName(int i , int j){
  string str;
  if(j>=0 && j<JACK){
  str.append(to_string(j+2));
}else{
  if(j == JACK)
    str.append("J");

  if(j == QUEEN)
    str.append("Q");


  if(j == KING)
    str.append("K");

  if(j == ACE)
    str.append("A");

}

  if(i == Shape::Club)
  str.append("C ");

 if(i == Shape::Diamond)
 str.append("D ");

 if(i == Shape::Heart)
 str.append("H ");

 if(i == Shape::Spade)
 str.append("S ");

 return str;
}

void Hand::deleteCard(Card& card,string reason){
  if(card.getValue() == "Number"){
    NumericCard& numericCard = (NumericCard&)card;
    int number = numericCard.getNumber();
    Shape shape = numericCard.getShape();

    if(Game::cardsFullMap[shape][number-2] == playerName){
      Game::cardsFullMap[shape][number-2] = reason;
    }
  }

  if(card.getValue() == "Figure"){
    FigureCard& figureCard = (FigureCard&)card;
    Figure figure = figureCard.getFigure();
    Shape shape = figureCard.getShape();
    int figureIdx;
    if(figure == Figure::Jack)figureIdx = JACK;
    if(figure == Figure::Queen)figureIdx = QUEEN;
    if(figure == Figure::King)figureIdx = KING;
    if(figure == Figure::Ace)figureIdx = ACE;

    if(Game::cardsFullMap[shape][figureIdx] == playerName){
      Game::cardsFullMap[shape][figureIdx] = reason;
    }

  }

}
Hand& Hand::operator=( Hand &anotherHand){
return *this;
}
Hand::~Hand(){
  //
  // int count = hand.size();
  // cout<<count<<endl;
  // for(int i=0;i<count;i++){
  //   if(hand[i]!=nullptr){
  //     delete hand[i];
  //     hand[i]=nullptr;
  //   }
  // }
  // hand.clear();
}
