#pragma once
#include "Libraries.h"
#include "Table.h"
#include "BidirectionalList.h"
#include "BidirectionalListManagement.h"
#include "BinaryHeap.h"

class Menu
{
private:

	Table table;
	BidirectionalListManagement listMng;
	BinaryHeap heap;
public:
	Menu();
	~Menu();

	void menuPanel();
	void tableMethods();
	void listMethods();
	void heapMethods();
};

