include "TwowayList.h"



TwowayList::TwowayList()
{
	this->front = nullptr;
	this->back = nullptr;
	this->counter = 0;
}


TwowayList::~TwowayList()
{
	delete[]front;
	delete[]back;
}
