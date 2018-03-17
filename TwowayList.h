#pragma once
#include "Libraries.h"
#include "TwowayListElement.h"

class TwowayList
{
private:
	//pointer for head - first element
	TwowayListElement* front;
	//pointer for tail of list - last element
	TwowayListElement* back;
	//counter of elements, just for optimilization
	int counter;
public:
	TwowayList();
	~TwowayList();


};

