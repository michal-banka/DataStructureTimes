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
	void addNewElementBegin(int value);
	void addNewElementEnd(int value);
	void addNewElementAnyWhere(int value, int position);
	void addNewElement();
	double addNewElement(int value, int position);

	void showList();

	void deleteElementBegin();
	void deleteElementEnd();
	void deleteElementAnywhere(int position);
	void deleteElement();
	double deleteElement(int position);

	int findElementPos();
	int findElementPos(int value);
	
	//function add elements from file to existing list
	void fillFromFile();
	void fillFromFile(std::string filename);
	void saveToFile();
	void saveToFile(std::string filename);
	void appendDoubleToTextFile(std::string filename, double dataToAppend);

	//functions which return time of operations
	double addNRandomElementsToList();
	double addNRandomElementsToList(int position, int n, int rangeDown, int rangeUp);

	double deleteAll();
	double deleteAll(int position);

	double findElementTime();
	double findElementTime(int value);
};

