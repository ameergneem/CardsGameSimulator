#include "../include/Player.h"
#include "../include/Deck.h"
#include "../include/Game.h"
#include <iostream>


using namespace std;

Player::Player(string name,string type):Hand::Hand(name),name(name),type(type){
  }
 Player::Player(const Player &anotherPlayer):Hand::Hand(anotherPlayer),name(anotherPlayer.name),type(anotherPlayer.type){}

void Player::Play(vector<Player*> &players){
  string valueToRequest = findCardToAskFor();
  request(players,valueToRequest);
  }

vector<Card*> Player::request(vector<Player*> players,string valueToRequest){
  Player* player = findPlayerToAsk(players);
  vector<Card*> cardsToReturn;

   Game::currentMove=getName()+" asked "+player->getName() +" for the value "+valueToRequest;
   cardsToReturn = player->getHand()->getCards(valueToRequest,"Give");
   if(cardsToReturn.size()>0){
   player->takeFromDeck(cardsToReturn.size());
   addCards(cardsToReturn);
 }else{
   takeFromDeck(1);
 }


  return cardsToReturn;
   }


void Player::addCard(Card& card){
  getHand()->addCard(card);
   checkForHand(card);


  }
void Player::addCards(vector<Card*> cards){
   vector<Card*>::iterator it;
  for(it=cards.begin();it!=cards.end();++it){
    addCard(**it);
     }

  }
string Player::getName(){
  return name;
}
string Player::getCards(){
  return getHand()->toString();
}
Player* Player::getPlayer(){
  return this;
}
bool Player::checkForHand(Card& card){
  if(card.getValue() == "Number"){

      NumericCard& numCard = (NumericCard&)card;
      int idx = numCard.getNumber();
      int count=0;
      for(int i=0;i<4;++i){
        if(Game::cardsFullMap[i][idx-2]==getName())count++;
      }
      if(count==4){

        getHand()->removeSet("Number",to_string(idx));
      }
      return count==4;
    }else{

      FigureCard& figCard = (FigureCard&)card;

      int numOfElements = Game::N+3,idx=0,count=0;
      int jack =numOfElements-4,queen=numOfElements-3,king=numOfElements-2,ace=numOfElements-1;
    if(figCard.getFigureStr()=="J")idx=jack;
    if(figCard.getFigureStr()=="Q")idx=queen;
    if(figCard.getFigureStr()=="K")idx=king;
    if(figCard.getFigureStr()=="A")idx=ace;
    for(int i=0;i<4;++i){
      if(Game::cardsFullMap[i][idx]==getName())count++;
    }

    if(count==4){
      getHand()->removeSet("Figure",figCard.getFigureStr());
    }
    return count==4;

    }

}
void Player::takeFromDeck(int num){
  vector<Card*> cards;
  if(Game::deckMain->getNumberOfCards()>=num){

  for(int i=0;i<num;i++){

    cards.push_back(Game::deckMain->fetchCard());
  }
 }else{
  int num = Game::deckMain->getNumberOfCards();
  for(int i=0;i<num;i++){
    cards.push_back(Game::deckMain->fetchCard());

  }

 }
   addCards(cards);
 }
void Player::setType(string type){
  type=type;
}
string Player::getType(){
  return type;
}
/////////////////////////////////////////////////////////////////////////////
PlayerType1::PlayerType1(string name):Player::Player(name,"PlayerType1"){

  }
PlayerType1::PlayerType1(const PlayerType1 &anotherPlayer):Player::Player(anotherPlayer){
}
Player* PlayerType1::findPlayerToAsk(vector<Player*> &players){

    vector<Player*>::iterator it;
    Player* playerToAsk;

    for(it=players.begin();it!=players.end();++it){//init with another player than this
      if((*it)->getName() != getName()){
        playerToAsk = *it;
        break;
      }
    }

    for(it=players.begin();it!=players.end();++it){
      if((*it)->getName() != getName() && (*it)->getHand()->getNumberOfCards() >=  playerToAsk->getHand()->getNumberOfCards()){
        playerToAsk = *it;
      }
    }
    return playerToAsk;
  }
string PlayerType1::findCardToAskFor(){

    int numOfElements = Game::N+3;
    int jack =numOfElements-4,queen=numOfElements-3,king=numOfElements-2,ace=numOfElements-1;
   int countsOfValues[Game::N+3];
   for(int i=0;i<numOfElements;i++){countsOfValues[i]=0;}

     for(int i=0;i<=ace;i++){
       for(int j=0;j<4;j++){

       if(Game::cardsFullMap[j][i]==getName())countsOfValues[i]++;
      }
  }
  int count=0;
  int idx = 0;
  for(int i=ace;i>=0;i--){
    if(countsOfValues[i]>count){
    count = countsOfValues[i];
    idx = i;
    }
  }

 if(idx == jack)return "J";
 if(idx == queen)return "Q";
 if(idx == king)return "K";
 if(idx == ace)return "A";
 return to_string(idx+2);

   }
   void PlayerType1::setType(string type){
     type=type;
   }
   string PlayerType1::getType(){
     return type;
   }
//////////////////////////////////////////////////////////////
PlayerType2::PlayerType2(string name):Player::Player(name,"PlayerType2") {
  }
  PlayerType2::PlayerType2(const PlayerType2 &anotherPlayer):Player::Player(anotherPlayer){
  }
string PlayerType2::findCardToAskFor(){

    int numOfElements = Game::N+3;
    int jack =numOfElements-4,queen=numOfElements-3,king=numOfElements-2,ace=numOfElements-1;
   int countsOfValues[Game::N+3];
   for(int i=0;i<numOfElements;i++){countsOfValues[i]=0;}

     for(int i=0;i<=ace;i++){
       for(int j=0;j<4;j++){

       if(Game::cardsFullMap[j][i]==getName())countsOfValues[i]+=1;
      }
  }


  int count=0,j=0;
  while(countsOfValues[j]==0)j++;
  count=countsOfValues[j];
  int idx = j;
  for(int i=0;i<numOfElements;i++){
    if(countsOfValues[i]<count&&countsOfValues[i]!=0){
    count = countsOfValues[i];
    idx = i;
    }
  }

 if(idx == jack)return "J";
 if(idx == queen)return "Q";
 if(idx == king)return "K";
 if(idx == ace)return "A";
 return to_string(idx+2);

   }
Player* PlayerType2::findPlayerToAsk(vector<Player*> &players){

    vector<Player*>::iterator it;
    Player* playerToAsk;

    for(it=players.begin();it!=players.end();++it){//init with another player than this
      if((*it)->getName() != getName()){
        playerToAsk = *it;
        break;
      }
    }

    for(it=players.begin();it!=players.end();++it){
      if((*it)->getName() != getName() && (*it)->getHand()->getNumberOfCards() >=  playerToAsk->getHand()->getNumberOfCards()){
        playerToAsk = *it;
      }
    }
    return playerToAsk;
  }
  void PlayerType2::setType(string type){
    type=type;
  }
  string PlayerType2::getType(){
    return type;
  }
///////////////////////////////////////////////////////////////
PlayerType3::PlayerType3(string name):Player::Player(name,"PlayerType3") {
  }
  PlayerType3::PlayerType3(const PlayerType3 &anotherPlayer):Player::Player(anotherPlayer){
  }
string PlayerType3::findCardToAskFor(){

      int numOfElements = Game::N+3,idx=0,i=0,j=0;
      int jack =numOfElements-4,queen=numOfElements-3,king=numOfElements-2,ace=numOfElements-1;
      bool found = false;
       for(i=ace;i>=0;i--){
         for(j=0;j<4;j++){
        if(!found){
         if(Game::cardsFullMap[j][i]==getName()){idx=i;found=true;}
       }
        }

    }

   if(idx == jack)return "J";
   if(idx == queen)return "Q";
   if(idx == king)return "K";
   if(idx == ace)return "A";

   return to_string(idx+2);

     }
Player* PlayerType3::findPlayerToAsk(vector<Player*> &players){
  //cout<<currentIdx<<endl;
   if(players[currentIdx]->getName() ==getName()){
   currentIdx = (currentIdx+1)%((int)players.size());
 }
   Player* playerToReturn = players[currentIdx];
   currentIdx = (currentIdx+1)%((int)players.size());

    return playerToReturn;
  }
  void PlayerType3::setType(string type){
    type=type;
  }
  string PlayerType3::getType(){
    return type;
  }
/////////////////////////////////////////////////////////////////////
PlayerType4::PlayerType4(string name):Player::Player(name,"PlayerType4") {
 }
 PlayerType4::PlayerType4(const PlayerType4 &anotherPlayer):Player::Player(anotherPlayer){
 }
string PlayerType4::findCardToAskFor(){


      int numOfElements = Game::N+3,jack =numOfElements-4,queen=numOfElements-3,king=numOfElements-2,ace=numOfElements-1;
      int idx=0,i=ace,j=0;
      bool found = false;


       for(i=0;i<=ace;i++){

         for(j=0;j<4;j++){
           if(!found){
         if(Game::cardsFullMap[j][i]==getName()){idx=i;found=true;}
       }
        }

    }

   if(idx == jack)return "J";
   if(idx == queen)return "Q";
   if(idx == king)return "K";
   if(idx == ace)return "A";

   return to_string(idx+2);

     }
Player* PlayerType4::findPlayerToAsk(vector<Player*> &players){

   if(players[currentIdx]->getName() ==getName()){
   currentIdx = (currentIdx+1)%((int)players.size());
 }
   Player* playerToReturn = players[currentIdx];
   currentIdx = (currentIdx+1)%((int)players.size());

    return playerToReturn;
  }
  void PlayerType4::setType(string type){
    type=type;
  }
  string PlayerType4::getType(){
    return type;
  }
