#include "../include/Card.h"
#include<string>





  FigureCard::FigureCard(Figure figure,Shape shape ):Card::Card(shape,"Figure"),figure(figure),figureStr(""){


    switch(figure){

      case Figure::Jack:
                      figureStr = "J";
                      break;
      case Figure::Queen:
                      figureStr = "Q";
                      break;
      case Figure::King:
                      figureStr = "K";
                      break;
      case Figure::Ace:
                      figureStr = "A";
                      break;
      default:
             figureStr = "";
             break;



          }

  }

FigureCard::FigureCard(FigureCard& card):Card::Card(card.getShape(),"Figure"),figure(card.getFigure()),figureStr(card.getFigureStr()){

}



string FigureCard::toString(){
  string str;
  str.append(figureStr);
  str.append(getShapeStr());
return str;
}
string FigureCard::getFigureStr(){return figureStr;}

Figure FigureCard::getFigure(){return figure;}
FigureCard& FigureCard::operator=( FigureCard &anotherFigureCard){
  if(this==&anotherFigureCard){
    return *this;
  }
  figure = anotherFigureCard.figure;
  figureStr = anotherFigureCard.figureStr;
  return *this;
}
