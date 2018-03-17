#pragma once
#include "Libraries.h"
#include "BidirectionalList.h"
#include "TimeCounter.h"

class BidirectionalListManagement
{
private:
	TimeCounter counter;
	BidirectionalList* head;
	BidirectionalList* tail;
	int count = 0;

	void addNewElementBegin(int value);
	void addNewElementEnd(int value);
public:
	BidirectionalListManagement();
	~BidirectionalListManagement();

	//getters and setters
	BidirectionalList* getHead();
	BidirectionalList* getTail();
	int getCount();
	void setHead(BidirectionalList* head);
	void setTail(BidirectionalList* tail);
	void setCount(int count);

	//functions, all with argument and without
	void addNewElement();
	void addNewElement(int value, int position);
	void showList();
	void deleteElement();
	void deleteElement(int position);
	int findElementPos();
	int findElementPos(int value);
	void addNRandomElementsToList();
	void addNRandomElementsToList(int n, int rangeDown, int rangeUp);
	//function add elements from file to existing list
	void fillFromFile();
	void fillFromFile(std::string filename);
	void saveToFile();
	void saveToFile(std::string filename);

	//zrobic funkjce mierzace czas dodawanie, usuwanie, szukanie
};

