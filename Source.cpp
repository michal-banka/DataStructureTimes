#include "Libraries.h"
#include "Menu.h"
//using namespace std;

int main()
{
	srand((unsigned)time(nullptr));
	Menu menu;
	menu.menuPanel();

	std::cin.get();
	return 0;
}