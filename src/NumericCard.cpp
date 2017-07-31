#include "../include/Card.h"
#include<string>

using namespace std;


NumericCard::NumericCard(int num,Shape shape):Card::Card(shape,"Number"),number(num){

      }
NumericCard::NumericCard(NumericCard& card):Card::Card(card.getShape(),"Number"),number(card.getNumber()){}
  string NumericCard::toString(){

    return to_string(number).append(getShapeStr());
    }

    int NumericCard::getNumber(){return number;}

    NumericCard& NumericCard::operator=( NumericCard &anotherNumericCard){
      if(this==&anotherNumericCard){
        return *this;
      }
      number = anotherNumericCard.number;
      return *this;
    }
