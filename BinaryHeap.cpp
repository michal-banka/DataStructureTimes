#include "BinaryHeap.h"



BinaryHeap::BinaryHeap()
{
	this->size = 0;
	this->heap = new int[0];
}


BinaryHeap::~BinaryHeap()
{
}

int* BinaryHeap::getHeap()
{
	return this->heap;
}

int BinaryHeap::getSize()
{
	return this->size;
}

int BinaryHeap::getParentIdx(int idxSon)
{
	return (idxSon - 1) / 2;
}

int BinaryHeap::getLeftSonIdx(int idxParent)
{
	return 2 * idxParent + 1;
}

int BinaryHeap::getRightSonIdx(int idxParent)
{
	return 2 * idxParent + 2;
}

void BinaryHeap::swapElementsInHeap(int idx1, int idx2)
{
	int tempVal = heap[idx1];
	heap[idx1] = heap[idx2];
	heap[idx2] = tempVal;
}

void BinaryHeap::addToHeap()
{
	int val = 0;
	std::cout << "Insert value of new element: ";
	std::cin >> val;
	std::cin.get();

	addToHeap(val);
}

void BinaryHeap::addToHeap(int value)
{
	//temporary heap
	int* temp = new int[size + 1];

	//fill temp with previous values
	for (int i = 0; i < size; i++)
	{
		temp[i] = heap[i];
	}

	//put new value on last position
	temp[size] = value;

	//save temp to heap
	delete heap;
	heap = temp;

	//move value while it's not on correct place
	int idx1 = size;
	int idx2 = getParentIdx(size);

	while(heap[idx1] > heap[idx2])
	{
		swapElementsInHeap(idx1,idx2);
		idx1 = idx2;
		idx2 = getParentIdx(idx2);
	}

	size++;
}

void BinaryHeap::showHeap()
{
	std::string width = "    ";
	int sizeTemp = size;
	int p = 0;

	//check how many levels are in heap
	//lessful now but may be useful later
	/*while (sizeTemp > 0)
	{
		sizeTemp -= pow(2, p);
		p++;
	}*/


	if (size != 0)
	{
		std::cout << "====HEAP====" << std::endl;
		for (int i = 0, l = 1; i < size; i++)
		{
			if (i == pow(2,l) - 1)
			{
				std::cout << std::endl;
				l++;
			}
			std::cout << heap[i] << "[" << i << "]" << "\t";
		}
		std::cout << std::endl << "============" << std::endl;
	}
	else
	{
		std::cout << "Heap is empty. Nothing to show." << std::endl;
	}
}

int BinaryHeap::findValueInHeap()
{
	int val = 0;
	std::cout << "Insert value of element to find: ";
	std::cin >> val;
	std::cin.get();

	return findValueInHeap(val);
}

int BinaryHeap::findValueInHeap(int value)
{
	for (int i = 0 ; i < size; i++)
	{
		if (heap[i] == value)
		{
			return i;
		}
	}
	return -1;
}

void BinaryHeap::deleteRoot()
{
	if (size != 0)
	{
		int position = 0;
		int* temp;
		heap[position] = heap[size - 1];

		while (heap[position] < heap[getLeftSonIdx(position)] || heap[position] < heap[getRightSonIdx(position)])
		{
			if (heap[position] < heap[getLeftSonIdx(position)])
			{
				swapElementsInHeap(position, getLeftSonIdx(position));
				position = getLeftSonIdx(position);
			}
			else if (heap[position] < heap[getRightSonIdx(position)])
			{
				swapElementsInHeap(position, getRightSonIdx(position));
				position = getRightSonIdx(position);
			}
		}

		temp = new int[size - 1];
		for (int i = 0; i < size - 1; i++)
		{
			temp[i] = heap[i];
		}

		delete heap;
		heap = temp;

		size--;
		std::cout << "[INFO]Root has been deleted." << std::endl;
	}
	else
	{
		std::cout << "[INFO]Heap is empty. Root has NOT been deleted." << std::endl;
	}
}

void BinaryHeap::deleteElement()
{
	int pos = 0;
	do
	{
	std::cout << "Insert position of element to delete (0 - " << size - 1 << "): ";
	std::cin >> pos;
	std::cin.get();
	} while (pos < 0 || pos > size - 1);
	
	deleteElement(pos);

}

void BinaryHeap::deleteElement(int position)
{
	if (size != 0)
	{
		//for root
		if (position == 0) deleteRoot();
		//for last element
		else if (position == size - 1)
		{
			std::cout << "LAST";
			int* temp = new int[size - 1];
			for (int i = 0; i < size - 1; i++)
			{
				temp[i] = heap[i];
			}
			delete heap;
			heap = temp;
		}
		//delete anything else
		else
		{
			//move last position to deleted element
			heap[position] = heap[size - 1];

			//copy heap to temp but without last element
			int* temp = new int[size - 1];
			for (int i = 0 ; i < size - 1; i++)
			{
				temp[i] = heap[i];
			}
			delete heap;
			heap = temp;

			//if parent is smaller move up
			while (heap[position] > heap[getParentIdx(position)])
			{
				swapElementsInHeap(position, getParentIdx(position));
				position = getParentIdx(position);
			}
			//if son is bigger move down
			while (heap[position] < heap[getLeftSonIdx(position)] || heap[position] < heap[getRightSonIdx(position)])
			{
				//if left son is bigger than parent and it's the biggest son swap with him
				if (heap[position] < heap[getLeftSonIdx(position)] && heap[getLeftSonIdx(position)] >= heap[getRightSonIdx(position)])
				{
					swapElementsInHeap(position, getLeftSonIdx(position));
					position = getLeftSonIdx(position);
				}
				else if (heap[position] < heap[getRightSonIdx(position)] && heap[getLeftSonIdx(position)] < heap[getRightSonIdx(position)])
				{
					swapElementsInHeap(position, getRightSonIdx(position));
					position = getRightSonIdx(position);
				}
			}
		}
		size--;
	}
	else
	{
		std::cout << "[INFO]Heap is empty. Root has NOT been deleted." << std::endl;
	}
}

void BinaryHeap::addNRandomNumbers()
{
	int n = 0;
	int down = 0;
	int up = 0;

	std::cout << "How many elements do you want to add: ";
	std::cin >> n;
	std::cin.get();

	std::cout << "What is bottom range of numbers: ";
	std::cin >> down;
	std::cin.get();

	std::cout << "What is upper range of numbers: ";
	std::cin >> up;
	std::cin.get();


	return addNRandomNumbers(n, down, up);
}

void BinaryHeap::addNRandomNumbers(int n, int rangeDown, int rangeUp)
{
	int val = 0;
	for (int i = 0; i < n; i++)
	{
		val = rand() % rangeUp + rangeDown;
		addToHeap(val);
	}
}


void BinaryHeap::fillFromFile()
{
	std::string name = "";
	std::cout << "Insert file name (without extension): ";
	std::cin >> name;
	std::cin.get();

	fillFromFile(name);
}

void BinaryHeap::fillFromFile(std::string filename)
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
			addToHeap(value);
		}
		std::cout << "[INFO] Filling list finished." << std::endl;
	}
	else
	{
		std::cout << "[INFO] File has NOT been opened. List is not filled." << std::endl;
	}
	read.close();
}

void BinaryHeap::saveToFile()
{
	std::string name = "";
	std::cout << "Insert file name to save (without extension): ";
	std::cin >> name;
	std::cin.get();

	saveToFile(name);
}

void BinaryHeap::saveToFile(std::string filename)
{
	filename += ".txt";
	std::ofstream write;
	write.open(filename);
	if (write.is_open())
	{
		for (int i = 0 ; i < size; i++)
		{
			write << heap[i] << std::endl;
		}
		std::cout << "[INFO] List saved to file." << std::endl;
	}
	else
	{
		std::cout << "[INFO] File could NOT be created/opened. " << std::endl;
	}
}