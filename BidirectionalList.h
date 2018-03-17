#pragma once
#include "Libraries.h"

class BidirectionalList
{
private:
	int value;
	BidirectionalList* next;
	BidirectionalList* prev;
public:
	BidirectionalList();
	BidirectionalList(BidirectionalList* next, BidirectionalList* prev);
	BidirectionalList(BidirectionalList* next, BidirectionalList* prev, int value);
	~BidirectionalList();

	BidirectionalList* getNext();
	BidirectionalList* getPrev();
	int getValue();
	void setNext(BidirectionalList* next);
	void setPrev(BidirectionalList* prev);
	void setValue(int value);
	

};