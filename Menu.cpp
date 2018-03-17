#include "Menu.h"


Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::menuPanel()
{
	int choice = 0;
	do
	{
		bool finish = false;
		std::cout << "What type of data structure do you want to create?\n";
		std::cout << "1. Table..." << std::endl;
		std::cout << "2. List..." << std::endl;
		std::cout << "3. Heap..." << std::endl;
		std::cout << "4. Quit" << std::endl;
		do
		{
			std::cout << "Your choice: ";
			std::cin >> choice;
			std::cin.get();
			if (choice > 4 || choice <= 0)
			{
				std::cout << "Incorrect choice, try again.\n";
			}
		} while (choice > 4 || choice <= 0);
		std::cout << "\n";

		switch (choice)
		{
		case 1:
			tableMethods();
			break;
		case 2:
			listMethods();
			break;
		case 3:
			heapMethods();
		default:
			break;
		}
	} while (choice != 4);
}

void Menu::tableMethods()
{
	int choices = 10;
	int choice = 0;
	int element = 0;
	int position = 0;
	double time = 0.0;
	std::string filename = "";

	do
	{
		//->Table...
		std::cout << "What do you want to do with table?" << std::endl;
		std::cout << "1. Show actual table" << std::endl;
		std::cout << "2. Add new element..." << std::endl;
		std::cout << "3. Delete element..." << std::endl;
		std::cout << "4. Find element..." << std::endl;
		std::cout << "5. Fill table from file..." << std::endl;
		std::cout << "6. Save to file" << std::endl << std::endl;
		std::cout << "VVV Functions which return time of operations. VVV" << std::endl;
		std::cout << "7. Add N random elements..." << std::endl;
		std::cout << "8. Delete all elements..." << std::endl;
		std::cout << "9. Find element by value..." << std::endl;
		std::cout << choices << ". Back" << std::endl;

		do
		{
			std::cout << "Your choice: ";
			std::cin >> choice;
			std::cin.get();
			if (choice > choices || choice <= 0)
			{
				std::cout << "Incorrect choice, try again." << std::endl;
			}
		} while (choice > choices || choice <= 0);
		std::cout << std::endl;

		switch (choice)
		{
		case 1:
			table.showTable();
			break;
		case 2:
			table.addElementToTable();
			break;
		case 3:
			table.deleteElementFromTable();
			break;
		case 4:
			
			std::cout << "Find first occurence of value: ";
			std::cin >> element;
			std::cin.get();

			position = table.findElementInTablePos(element);
			//-1 is default, it just means it isn't real position
			if (position == -1)
			{
				std::cout << "Value was not found in this table." << std::endl << std::endl;
			}
			else if (position >= 0)
			{
				std::cout << "Index of found element is: " << position << std::endl << std::endl;
			}
			break;

		case 5:
			std::cout << "Insert file's name (without extension): ";
			std::cin >> filename;
			std::cin.get();

			table.fillFromFile(filename);
			break;
		case 6:
			std::cout << "Insert file's name (without extension): ";
			std::cin >> filename;
			std::cin.get();

			table.saveToFile(filename);
			break;
		case 7:
			time = table.addNRandomElementsToTable();
			std::cout << "Time of adding was: " << time << " ms." << std::endl;
			break;
		case 8:
			time = table.deleteAll();
			std::cout << "Time of deleting was: " << time << " ms." << std::endl;
			break;
		case 9:
			time = table.findElementInTableTime();
			std::cout << "Time of finding was: " << time * 1000 << "mikroseconds." << std::endl << std::endl;
		default:
			break;
		}
	} while (choice != choices);
	
}

void Menu::listMethods()
{
	double time = 0;
	int choice = 0;
	//number of possible choices
	int choices = 10;

	do {

		//->List...
		std::cout << "What do you want to do with list?" << std::endl;
		std::cout << "1. Show actual list" << std::endl;
		std::cout << "2. Add new element..." << std::endl;
		std::cout << "3. Delete element..." << std::endl;
		std::cout << "4. Find element (get position)..." << std::endl;
		std::cout << "5. Fill from file..." << std::endl;
		std::cout << "6. Save to file" << std::endl << std::endl;
		std::cout << "VVV Functions which return time of operations. VVV" << std::endl;
		std::cout << "7. Add N random elements..." << std::endl;
		std::cout << "8. Delete all elements..." << std::endl;
		std::cout << "9. Find element..." << std::endl;
		std::cout << choices << ". Back" << std::endl;

		do
		{
			std::cout << "Your choice: ";
			std::cin >> choice;
			std::cin.get();
			if (choice > choices || choice <= 0)
			{
				std::cout << "Incorrect choice, try again." << std::endl;
			}
		} while (choice > choices || choice <= 0);
		std::cout << std::endl;

		int pos = -1;
		switch (choice)
		{
		case 1:
			listMng.showList();
			break;

		case 2:
			listMng.addNewElement();
			break;

		case 3:
			listMng.deleteElement();
			break;

		case 4:
			pos = listMng.findElementPos();
			//-1 is default, it just means it isn't real position
			if (pos != -1)
			{
				std::cout << "Element with this value has been found on place number: " << pos << std::endl;
			}
			else
			{
				std::cout << "Element with this value was not found in list." << std::endl;
			}
			break;

		case 5:
			listMng.fillFromFile();
			break;
		case 6:
			listMng.saveToFile();
			break;
		case 7:
			time = listMng.addNRandomElementsToList();
			std::cout << "Time of adding was: " << time << " ms. " << std:: endl << std::endl;
			break;
		case 8:
			time = listMng.deleteAll();
			std::cout << "Time of deleting was: " << time << "ms. " << std::endl << std::endl;
		case 9:
			time = listMng.findElementTime();
			std::cout << "Time of finding was: " << time * 1000 << "mikroseconds." << std::endl << std::endl;
		default:
			break;
		}
	} while (choice != choices);
}

void Menu::heapMethods()
{
	double time = 0.0;
	int choice = 0;
	//number of possible choices
	int choices = 8;
	int pos = -1;

	do {

		//->List...
		std::cout << std::endl << "What do you want to do with heap?" << std::endl;
		std::cout << "1. Show actual heap" << std::endl;
		std::cout << "2. Add new element..." << std::endl;
		std::cout << "3. Delete element..." << std::endl;
		std::cout << "4. Find element..." << std::endl;
		std::cout << "5. Fill from file..." << std::endl;
		std::cout << "6. Save to file..." << std::endl;
		std::cout << "VVV Functions which return time of operations. VVV" << std::endl;
		std::cout << "7. Add N random elements..." << std::endl;
		std::cout << "8. Delete all elements..." << std::endl;
		std::cout << "9. Find element..." << std::endl;
		std::cout << choices << ". Back" << std::endl;

		do
		{
			std::cout << "Your choice: ";
			std::cin >> choice;
			std::cin.get();
			if (choice > choices || choice <= 0)
			{
				std::cout << "Incorrect choice, try again." << std::endl;
			}
		} while (choice > choices || choice <= 0);
		std::cout << std::endl;

		
		switch (choice)
		{
		case 1:
			heap.showHeap();
			break;

		case 2:
			heap.addToHeap();
			break;

		case 3:
			heap.deleteElement();
			break;

		case 4:
			//pos = listMng.findElement();
			//-1 is default, it just means it isn't real position
			pos = heap.findValueInHeap();
			if (pos != -1)
			{
				std::cout << "Element with this value has been found on place number: " << pos << std::endl;
			}
			else
			{
				std::cout << "Element with this value was not found in heap." << std::endl;
			}
			break;

		case 5:
			heap.fillFromFile();
			break;
		case 6:
			heap.saveToFile();
			break;
		case 7:
			time = heap.addNRandomNumbers();
			std::cout << "Time of adding was: " << time << " ms. " << std::endl << std::endl;
			break;
		case 8:
			time = heap.deleteAll();
			std::cout << "Time of deleting was: " << time << "ms. " << std::endl << std::endl;
			break;
		case 9:
			time = heap.findElementGetTime();
			std::cout << "Time of finding was: " << time << "ms. " << std::endl << std::endl;
			break;
		default:
			break;
		}
	} while (choice != choices);
}


