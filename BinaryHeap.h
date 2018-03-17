#pragma once
#include "Libraries.h"
#include "cmath"
class BinaryHeap
{
private:
	int* heap;
	int size;
public:
	BinaryHeap();
	~BinaryHeap();

	int* getHeap();
	int getSize();
	int getParentIdx(int idxSon);
	int getLeftSonIdx(int idxParent);
	int getRightSonIdx(int idxParent);
	void swapElementsInHeap(int idx1, int idx2);

	void addToHeap();
	void addToHeap(int value);
	void showHeap();
	int findValueInHeap();
	int findValueInHeap(int value);
	void deleteRoot();
	void deleteElement();
	void deleteElement(int position);
	void addNRandomNumbers();
	void addNRandomNumbers(int n, int rangeDown, int rangeUp);
	//function add elements from file to existing list
	void fillFromFile();
	void fillFromFile(std::string filename);
	void saveToFile();
	void saveToFile(std::string filename);
};

