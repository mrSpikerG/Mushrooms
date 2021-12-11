#include <iostream>
#include <Windows.h>
#include "c_Plantation.cpp"
using namespace std;
int main()
{
	setlocale(LC_ALL, "");
	c_plantation *MyPlantation = new c_plantation(150);

	int check;
	do {
		cout << "\nMoney: "<<MyPlantation->getMoney();
		cout << "\n\tMenu";
		cout << "\n1 - Список грибов на плантации";
		cout << "\n2 - Посадить гриб";
		cout << "\n3 - Собрать гриб";
		cout << "\n0 - Выйти";

		cout << "\nВаш выбор: ";
		cin >> check;
		cin.ignore();
		switch (check)
		{
		case 1:
			MyPlantation->showMushrooms2();
			system("pause");
			system("cls");
			break;
		case 2:
			

			MyPlantation->plantMushroom();

			system("cls");
			break;
		case 3:
			char name2[100];
			cout << "\nВведите название: "; 
			gets_s(name2, 100);

			MyPlantation->claimMushrooms(1);
;
			system("cls");
			break;
		}

	} while(check!=0);

}
