#ifndef CARD_H_
#define CARD_H_

#include <iostream>
using namespace std;

enum Shape {
	Club,
	Diamond,
	Heart,
	Spade
};

enum Figure {
	Jack,
	Queen,
	King,
	Ace
};

class Card {
private:
  Shape shape;
	string shapeStr;
	string value;
	bool deleted;


public:
  virtual string toString() = 0; //Returns the string representation of the card "<value><shape>" exp: "12S" or "QD"
	Card(Shape shape,string value);
  virtual ~Card();
	string getShapeStr();
	Shape getShape();
	void setShape(Shape shapeToSet);
	string getValue();
	void setValue(string value);
	Card& operator=(Card& otherCard);
	bool isDeleted(){return deleted;};
	void setDeleted(bool deleteIt){deleted=deleteIt;};



};

class FigureCard : public Card {
private:
	Figure figure;
	string figureStr;


public:
	FigureCard(Figure figure,Shape shape);
	FigureCard(FigureCard& card);
	Figure getFigure();
	string getFigureStr();
	virtual string toString() override;
	FigureCard& operator=( FigureCard &anotherFigureCard);


};

class NumericCard : public Card {
private:
	int number;

public:
	NumericCard(int num,Shape shape);
	NumericCard(NumericCard& card);
	int getNumber();
	virtual string toString() override;
	NumericCard& operator=( NumericCard &anotherNumericCard);





};

#endif
