#include <iostream>
#include <time.h>
class c_mushroom {

private:
	char* name;
	int growedAge;
	float birthday;
public:

	c_mushroom(char* name) {
		this->birthday = clock()/1000;
		this->growedAge = 10;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1,name);

	}

	bool isGrowed() {
		if ((clock() / 1000 - birthday) >= growedAge) {
			return true;
		}
		return false;
	}

	char* getName() {
		return name;
	}
	int getAge() {
		return  growedAge - (clock() / 1000 - birthday);
	}
};