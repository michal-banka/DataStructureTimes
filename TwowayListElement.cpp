#include "TwowayListElement.h"


TwowayListElement::TwowayListElement(TwowayListElement * prev, TwowayListElement * next, int value)
{
	this->value = value;
	this->next = next;
	this->prev = prev;
}

TwowayListElement::~TwowayListElement()
{
	delete[]prev;
	delete[]next;
}

TwowayListElement * TwowayListElement::getPrev()
{
	return this->prev;
}

TwowayListElement * TwowayListElement::getNext()
{
	return this->next;
}

int TwowayListElement::getValue()
{
	return this->value;
}

void TwowayListElement::setPrev(TwowayListElement * prev)
{
	this->prev = prev;
}

void TwowayListElement::setNext(TwowayListElement * next)
{
	this->next = next;
}

void TwowayListElement::setValue(int value)
{
	this->value = value;
}


