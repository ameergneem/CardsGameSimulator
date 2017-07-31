#include "../include/Card.h"
#include <string>

Card::Card(Shape shape,string value):shape(shape),shapeStr(""),value(value),deleted(false){
  switch(shape){
  case Shape::Club:
    shapeStr = "C";
    break;

  case Shape::Diamond:
          shapeStr = "D";
          break;

  case Shape::Heart:
          shapeStr = "H";
          break;

  case Shape::Spade:
          shapeStr = "S";
          break;
   default:
      shapeStr = " ";
  }

}



    string Card::toString(){

      return shapeStr;
      }

      Card::~Card(){}

      string Card::getShapeStr(){
        return shapeStr;
      }

Shape Card::getShape(){
  return shape;
}

void Card::setShape(Shape shapeToSet){
  shape = shapeToSet;
}

string Card::getValue(){
  return value;
}
void Card::setValue(string value){
  this->value = value;
}
Card& Card::operator=(Card& otherCard){
  shape = otherCard.shape;
  shapeStr = otherCard.shapeStr;
  value=otherCard.value;
  return *this;
}
