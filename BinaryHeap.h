#pragma once
#include "Libraries.h"
#include <cmath>
#include "TimeCounter.h"

class BinaryHeap
{
private:
	TimeCounter counter;
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
	double deleteElement(int position);
	//function add elements from file to existing list
	void fillFromFile();
	void fillFromFile(std::string filename);
	void saveToFile();
	void saveToFile(std::string filename);
	void appendDoubleToTextFile(std::string filename, double dataToAppend);

	//functions used to count time
	double addNRandomNumbers();
	double addNRandomNumbers(int n, int rangeDown, int rangeUp);
	
	double deleteAll();
	double deleteAll(int position);

	double findElementGetTime();
	double findElementGetTime(int value);
};

