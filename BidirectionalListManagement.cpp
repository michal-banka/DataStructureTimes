#include "BidirectionalListManagement.h"



BidirectionalListManagement::BidirectionalListManagement()
{
	this->head = nullptr;
	this->tail = nullptr;
	this->count = 0;
}


BidirectionalListManagement::~BidirectionalListManagement()
{
	delete head;
	delete tail;
}

BidirectionalList * BidirectionalListManagement::getHead()
{
	return this->head;
}

BidirectionalList * BidirectionalListManagement::getTail()
{
	return this->tail;
}

int BidirectionalListManagement::getCount()
{
	return this->count;
}

void BidirectionalListManagement::setHead(BidirectionalList * head)
{
	this->head = head;
}

void BidirectionalListManagement::setTail(BidirectionalList * tail)
{
	this->tail = tail;
}

void BidirectionalListManagement::setCount(int count)
{
	this->count = count;
}


void BidirectionalListManagement::addNewElementBegin(int value)
{
	BidirectionalList* newElem = new BidirectionalList();
	newElem->setValue(value);
	//if list is empty
	if (head == nullptr)
	{
		head = newElem;
		tail = newElem;
	}
	else
	{
		newElem->setNext(head);
		head = newElem;
		head->getNext()->setPrev(newElem);
	}
	std::cout << "[INFO] New element added to the beggining." << std::endl;
}


void BidirectionalListManagement::addNewElementEnd(int value)
{
	BidirectionalList* newElem = new BidirectionalList();
	newElem->setValue(value);

	//if list is empty (never occur)
	if (!head)
	{
		newElem->setPrev(nullptr);
		newElem->setNext(nullptr);
		head = newElem;
		tail = newElem;
	}
	else
	{
		newElem->setPrev(tail);
		tail->setNext(newElem);
		tail = newElem;
	}
	std::cout << "[INFO] New element added to end." << std::endl;
}

//this is main function to add new element
//rest are only for faster adding to list with different algorithm
void BidirectionalListManagement::addNewElement()
{
	int val = 0;
	int pos = 0;

	std::cout << "Value of new element: ";
	std::cin >> val;
	std::cin.get();

	do
	{
		std::cout << "Position of new element (0 - " << count << "):";
		std::cin >> pos;
		std::cin.get();
	} while (pos < 0 || pos > count);

	addNewElement(val, pos);
}

//same as upper method but with arguments
void BidirectionalListManagement::addNewElement(int value, int position)
{
	BidirectionalList* newElem;
	BidirectionalList* pointer;
	// "index" of new element, count is index of one after last so it will be new end
	if (position >=0 && position <= count)
	{
		//usage of different methods
		if (position == 0)
		{
			addNewElementBegin(value);
		}
		else if (position == count)
		{
			addNewElementEnd(value);
		}
		else
		{
			newElem = new BidirectionalList;
			pointer = getHead();
			for (int i = 0; i < position; i++)
			{
				pointer = pointer->getNext();
			}
			newElem->setNext(pointer);
			newElem->setPrev(pointer->getPrev());
			newElem->setValue(value);
			pointer->getPrev()->setNext(newElem);
			pointer->setPrev(newElem);
		}
		count++;
	}
	else
	{
		std::cout << "[INFO] Position is out of list. Element has NOT been added." << std::endl << std::endl;
	}
}

void BidirectionalListManagement::showList()
{
	if (head)
	{
		BidirectionalList* headTemp = getHead();

		std::cout << "====LIST====" << std::endl;
		int i = 0;
		while (headTemp)
		{
			std::cout << "List[" << i << "] = " << headTemp->getValue() << std::endl;
			headTemp = headTemp->getNext();
			i++;
		}
		std::cout << "============" << std::endl;
	}
	else
	{
		std::cout << "List is empty." << std::endl;
	}
}

void BidirectionalListManagement::deleteElement()
{
	if (count > 0)
	{
		int pos = 0;
		do
		{
			std::cout << "Position of element to delete (0 - " << count - 1 << "):";
			std::cin >> pos;
			std::cin.get();

			deleteElement(pos);
		} while (pos < 0 || pos >= count);
	}
	else
	{
		std::cout << "[INFO] List is empty, nothing to delete." << std::endl;
	}
}



void BidirectionalListManagement::deleteElement(int position)
{
	if (head)
	{
		//delete first element
		if(position == 0)
		{
			//if that's only element in list
			if (count == 1)
			{
				delete head;
				head = nullptr;
				tail = nullptr;
			}
			else
			{
				head = head->getNext();
				delete head->getPrev();
				head->setPrev(nullptr);
			}
		}
		//delete last element
		else if (position == count - 1)
		{
			tail = tail->getPrev();
			delete tail->getNext();
			tail->setNext(nullptr);
		}
		//delete from inside of list
		else
		{
			BidirectionalList* temp = getHead();
			for (int i = 0 ; i < position; i++)
			{
				temp = temp->getNext();
			}
			temp->getNext()->setPrev(temp->getPrev());
			temp->getPrev()->setNext(temp->getNext());
			delete temp;
		}
		count--;
	}
	else
	{
		std::cout << "[INFO] List is empty, nothing to delete." << std::endl;
	}
}

int BidirectionalListManagement::findElementPos()
{
	int val = 0;
	std::cout << "Value of element to find: ";
	std::cin >> val;
	std::cin.get();


	return findElementPos(val);
}

int BidirectionalListManagement::findElementPos(int value)
{
	BidirectionalList* temp = getHead();
	for (int i = 0; i < count; i++)
	{
		if (temp->getValue() == value)
		{
			return i;
		}
		temp = temp->getNext();
	}
	return -1;
}

void BidirectionalListManagement::addNRandomElementsToList()
{
	int n = 0;
	int down = 0;
	int up = 0;

	do
	{
		std::cout << "How many elements do you want to add: ";
		std::cin >> n;
		std::cin.get();
	} while (n <= 0);
	
	std::cout << "What is bottom range of numbers: ";
	std::cin >> down;
	std::cin.get();

	std::cout << "What is upper range of numbers: ";
	std::cin >> up;
	std::cin.get();


	return addNRandomElementsToList(n,down,up);
}

void BidirectionalListManagement::addNRandomElementsToList(int n, int rangeDown, int rangeUp)
{
	int val = 0;
	for (int i = 0; i < n; i++)
	{
		val = rand() % rangeUp + rangeDown;
		addNewElementEnd(val);
	}
	std::cout << "[INFO] " << n << "elements has been added." << std::endl;
}

void BidirectionalListManagement::fillFromFile()
{
	std::string name = "";
	std::cout << "Insert file name (without extension): ";
	std::cin >> name;
	std::cin.get();

	fillFromFile(name);
}

void BidirectionalListManagement::fillFromFile(std::string filename)
{
	int value = 0;
	filename += ".txt";
	std::ifstream read;

	read.open(filename);
	if (read.is_open())
	{
		std::cout << "[INFO] File has been opened." << std::endl;
		while (!read.eof())
		{
			read >> value;
			addNewElementEnd(value);
		}
		std::cout << "[INFO] Filling list finished." << std::endl;
	}
	else
	{
		std::cout << "[INFO] File has NOT been opened. List is not filled." << std::endl;
	}
	read.close();
}

void BidirectionalListManagement::saveToFile()
{
	std::string name = "";
	std::cout << "Insert file name to save (without extension): ";
	std::cin >> name;
	std::cin.get();

	saveToFile(name);
}

void BidirectionalListManagement::saveToFile(std::string filename)
{
	filename += ".txt";
	std::ofstream write;
	write.open(filename);
	if (write.is_open())
	{
		//weird look but cool work
		for (BidirectionalList* temp = getHead(); temp; temp = temp->getNext())
		{
			write << temp->getValue() << std::endl;
		}
		std::cout << "[INFO] List saved to file." << std::endl;
	}
	else
	{
		std::cout << "[INFO] File could NOT be created/opened. " << std::endl;
	}
}


