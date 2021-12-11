#include <iostream>
#include "c_Mushroom.cpp";
using namespace std;
class c_plantation {

private:
	c_mushroom** plantation;
	int size;
	int money;
	int cost;
public:
	
	int getMoney() {
		return money;
	}
	
	c_plantation(int cost) {
		this->money = 1000;
		this->cost = cost;
		size = 0;
	}

	int plantMushroom(){
		if (money >= cost) {

			plantation = (c_mushroom**)realloc(plantation, (size + 1) * sizeof(c_mushroom*));
			
			/*c_mushroom **TEMP = new c_mushroom*[size + 1];
			for (int i = 0; i < size; i++) {
				TEMP[i] = plantation[i];
			}*/
			
			plantation[size] = new c_mushroom();
			size++;
			
			//plantation = TEMP;
			money -= cost;
		}
		return -1;
	}

	void claimMushrooms(int id) {
		for (int i = 0; i < size; i++) {

			//поиск нужного гриба
			if (id ==i+1) {
				
				//проверка на зрелость
				if (this->plantation[i]->isGrowed()) {
					for (int j = i; j < size-1; j++) {
						

						this->plantation[j] = this->plantation[j + 1];
				

					}
					delete this->plantation[size - 1];

					//не знаю можно ли было использовать методы С, но вот
					this->plantation = (c_mushroom**)realloc(plantation, (size - 1)*sizeof(c_mushroom*));
					size--;

					//типо продали гриб 
					this->money += cost * 2;
				}
			}
		}
		

	}
	void showMushrooms2() {
		for (int i = 0; i < size; i++) {

				cout << "\nId: " <<i+1;


			if (this->plantation[i]->getAge() < 0) {
				cout << "\nMatured";
			}
			else {
				cout << "\nTime to mature: " << this->plantation[i]->getAge();
			}
			cout << "\n";
		}
	}
	

	~c_plantation() {
		for (int i = 0; i < size; i++) {
			delete plantation[i];
		}
		delete plantation;
	}
};