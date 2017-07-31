#include "../include/Game.h"
#include "../include/Deck.h"
#include<fstream>
#include <sstream>

#include <iostream>

using namespace std;
int Game::N;
string **Game::cardsFullMap;
string Game::currentMove;
string Game::initState;
Deck* Game::deckMain ;


Game::Game( const Game &anotherGame):players(),verbal(anotherGame.verbal),cardsNum(anotherGame.cardsNum),count(1),numberOfTurns(anotherGame.numberOfTurns),cardsNames(anotherGame.cardsNames),currentState(anotherGame.currentState),playersNames(anotherGame.playersNames),winners(""),cards(),deck(){
  int n2=anotherGame.cards.size();
  for(int i=0;i<n2;i++){
    if(anotherGame.cards[i]->getValue() == "Number"){
   cards.push_back(new NumericCard(*((NumericCard*)(anotherGame.cards[i]))));
 }else{
   cards.push_back(new FigureCard(*((FigureCard*)(anotherGame.cards[i]))));
 }
 }

 int n=anotherGame.players.size();
 for(int i=0;i<n;i++){
   if(anotherGame.players[i]->getType()=="PlayerType1"){
    players.push_back(new PlayerType1(*((PlayerType1*)anotherGame.players[i])));
  }
  if(anotherGame.players[i]->getType()=="PlayerType2"){
   players.push_back(new PlayerType2(*((PlayerType2*)anotherGame.players[i])));
 }
 if(anotherGame.players[i]->getType()=="PlayerType3"){
  players.push_back(new PlayerType3(*((PlayerType3*)anotherGame.players[i])));
}
if(anotherGame.players[i]->getType()=="PlayerType4"){
 players.push_back(new PlayerType4(*((PlayerType4*)anotherGame.players[i])));
}
 }


}
Game::Game(char* configurationFile):players(),verbal(0),cardsNum(0),count(0),numberOfTurns(0),cardsNames(""),currentState(""),playersNames(""),winners(""),cards(),deck(){
  deckMain = new Deck();
 parseFile(configurationFile);
 }

void Game::init(){
  initCardsFullMap();
  setCardsToMainDeck(cardsNum,cardsNames);
 setPlayers(playersNames,deckMain);



}
void Game::initCardsFullMap(){
  cardsFullMap=new string*[4];
    for(int i=0;i<4;++i){
      cardsFullMap[i] = new string[N+3];
    }
  for(int i=0;i<4;++i){
      for(int j=0;j<N+3;++j){
        cardsFullMap[i][j] = "Deck";
      }
    }
  }
void Game::parseFile(char* fileName){
  ifstream inFile;
  inFile.open(fileName);
  int linesNumber=0;
  string line,str,strLine,strWithoutAstrix;
  ////////////////////////////put file into string
  for(;getline( inFile, line );){
  str.append(line);
  str.append("\n");
  linesNumber++;
   }
   linesNumber++;

  /////////////////////////////////remove astrix
  istringstream strStream(str);
  int i=0;
  getline(strStream,strLine);
  while(i<=linesNumber){
  if(strLine[0]!='#' && strLine.size()>0){
  strWithoutAstrix.append(strLine);
  strWithoutAstrix.append("\n");
  }
  getline(strStream,strLine);
  i++;

  }

  /////////////////////////////

  /////////////////////////////////////
  string lineStr;
  istringstream strStream2(strWithoutAstrix);
  getline(strStream2,lineStr);
  verbal = stoi(lineStr.c_str());
  getline(strStream2,lineStr);
  cardsNum = stoi(lineStr.c_str());

  getline(strStream2,lineStr);
  cardsNames = lineStr;


  string nameLine;
  getline(strStream2,nameLine);
  while(nameLine.size()>0){
  playersNames.append(nameLine);
  playersNames.append("\n");
  getline(strStream2,nameLine);
  }
   N =cardsNum;
  }

void Game::setCurrentState(int turnNumber){
  vector<Player*>::iterator it;
  currentState.append("Deck:" + deckMain->toString()+"\n");
    for(it=players.begin();it!=players.end();++it){
      currentState.append((*it)->getName()+":"+(*it)->getCards()+"\n");
    }
    if(turnNumber==1)initState=currentState;

}
void Game::play(){

  vector<Player*>::iterator it;
 for(it=players.begin();it!=players.end();++it){
 (*it)->takeFromDeck(7);
}
int i=0;
while(!checkWinner()  ){

 for(it=players.begin();it!=players.end();++it){
  i++;
  //currentState.append(("Turn: " + to_string(i))+"\n");
setCurrentState(i);
 (*it)->Play(players);
 if(verbal){
  cout<<"Turn: "<<i<<endl;
 cout<<currentState;
 cout<<currentMove<<endl;
 cout<<endl;
 }
 if(checkWinner())break;

 currentState.clear();
 }
 numberOfTurns=i;
 //checkWinner();
}
currentState.clear();
setCurrentState(i);

}

void Game::pringPlayers(vector<Player*>players,Deck*deck2){
    vector<Player*>::iterator it;

        for(it=players.begin();it!=players.end();++it){
          cout<<(*it)->getCards()<<endl;
        }
  }
void Game::setCardsToMainDeck(int N,string cardsOrder){

     Deck helpDeck = Deck();
    cards.push_back(new FigureCard(Figure::Jack,Shape::Spade));
    cards.push_back(new FigureCard(Figure::Jack,Shape::Diamond));
    cards.push_back(new FigureCard(Figure::Jack,Shape::Club));
    cards.push_back(new FigureCard(Figure::Jack,Shape::Heart));

    cards.push_back(new FigureCard(Figure::King,Shape::Spade));
    cards.push_back(new FigureCard(Figure::King,Shape::Diamond));
    cards.push_back(new FigureCard(Figure::King,Shape::Club));
    cards.push_back(new FigureCard(Figure::King,Shape::Heart));

    cards.push_back(new FigureCard(Figure::Queen,Shape::Spade));
    cards.push_back(new FigureCard(Figure::Queen,Shape::Diamond));
    cards.push_back(new FigureCard(Figure::Queen,Shape::Club));
    cards.push_back(new FigureCard(Figure::Queen,Shape::Heart));

    cards.push_back(new FigureCard(Figure::Ace,Shape::Spade));
    cards.push_back(new FigureCard(Figure::Ace,Shape::Diamond));
    cards.push_back(new FigureCard(Figure::Ace,Shape::Club));
    cards.push_back(new FigureCard(Figure::Ace,Shape::Heart));


    for(int i=2;i<=N;i++){

      //NumericCard* card = new NumericCard(i,Shape::Spade);
      cards.push_back(new NumericCard(i,Shape::Spade));
      //NumericCard* card2 = new NumericCard(i,Shape::Diamond);
      cards.push_back(new NumericCard(i,Shape::Diamond));
      //NumericCard* card3 = new NumericCard(i,Shape::Club);
      cards.push_back(new NumericCard(i,Shape::Club));
      //NumericCard* card4 = new NumericCard(i,Shape::Heart);
      cards.push_back(new NumericCard(i,Shape::Heart));
    }

   int count = 4*(N+3);
   istringstream stream(cardsOrder);
   vector<Card*>::iterator it;
   string str,str2;
   stream>>str;
  while(count!=0){
   for(it=cards.begin();it!=cards.end();++it){
     if((*it)->toString() == str){
       helpDeck.addCard(**it);
       break;
     }
   }
    stream>>str;
    count--;
  }
  int helpDeckCount = helpDeck.getNumberOfCards();
   for(int i=0;i<helpDeckCount;i++){
     deckMain->addCard(*(helpDeck.fetchCard()));
    }
  }

void Game::setPlayers(string names,Deck* deck){
 istringstream strStream(names);
 string name;
 vector<Player*> playersV;
 getline(strStream,name);
 while(name.size()>0){
  int i=0;
  string onlyName;
  while(name[i]!=' '){
  onlyName+=name[i];
  i++;
  }
  i++;
  int onlyNumber = name[i]-'0';
  if(onlyNumber==1){
    Player* player = new PlayerType1(onlyName);
    playersV.push_back(player);
      getline(strStream,name);
  }
  if(onlyNumber==2){
  Player*  player = new PlayerType2(onlyName);
  playersV.push_back(player);
    getline(strStream,name);
  }
  if(onlyNumber==3){
  Player*  player = new PlayerType3(onlyName);
  playersV.push_back(player);
    getline(strStream,name);
  }
  if(onlyNumber==4){
  Player*  player = new PlayerType4(onlyName);
  playersV.push_back(player);
    getline(strStream,name);
  }

 }
   vector<Player*>::iterator it;
      for(it=playersV.begin();it!=playersV.end();++it){
   players.push_back(*it);
   }
}

bool Game::checkWinner(){
  int count = 0;
  string winner1,winner2;
  vector<Player*>::iterator it;
  for(it=players.begin();it!=players.end();++it){
    if((*it)->getHand()->getNumberOfCards() == 0){
      if(count==0){
        winner1 = (*it)->getName();

      }else{
        winner2 = (*it)->getName();
      }
      count++;
    }
  }
  if(count==1){
    winners="***** The Winner is: "+winner1+" *****";
    return true;
  }else{
    if(count==2){
      winners = "***** The Winners are: "+winner1 + " and "+winner2+" *****";
      return true;
    }
  }
  return false;
}
void Game::printWinner(){
  cout<<winners<<endl;
}
void Game::printNumberOfTurns(){
  cout<<"Number of turns: "<<numberOfTurns<<endl;
}
void Game::printState(){
  if(count==0)
  cout<<currentState<<endl;
  else
  cout<<initState<<endl;
}



Game::~Game(){
  int n1=cards.size();
  for(int i=0;i<n1;i++){
    delete cards[i];
  }
  cards.clear();

  delete deckMain;
  deckMain =NULL;

if(cardsFullMap!= nullptr){
  for(int i = 0; i < 4; i++){
    if(cardsFullMap[i] !=nullptr){
    delete [] cardsFullMap[i];
    cardsFullMap[i] =nullptr;
    }
  }

  delete [] cardsFullMap;
cardsFullMap =nullptr;
}



  int n=players.size();
  for(int i=0;i<n;i++){
    if(players[i]!=nullptr){
    delete players[i];
    players[i] =nullptr;
  }
  }



}


Game& Game::operator=( Game &anotherGame){
  if(this==&anotherGame){
    return *this;
  }
  players = anotherGame.players;
   deckMain=anotherGame.deckMain;
    verbal=anotherGame.verbal;
    cardsNum = anotherGame.cardsNum;
    cardsNames=anotherGame.cardsNames;
    currentState=anotherGame.currentState;
    playersNames=anotherGame.playersNames;
   cards=anotherGame.cards;
    deck=anotherGame.deck;
    return *this;
}
