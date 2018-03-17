#pragma once
#include "Libraries.h"

class TwowayListElement
{
private:
	//pointers for next and previous element of this element
	TwowayListElement* prev;
	TwowayListElement* next;
	int value;
public:
	TwowayListElement(TwowayListElement* prev, TwowayListElement* next, int value);
	~TwowayListElement();

	TwowayListElement* getPrev();
	TwowayListElement* getNext();
	int getValue();
	void setPrev(TwowayListElement* prev);
	void setNext(TwowayListElement* next);
	void setValue(int value);
};

