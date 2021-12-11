#include <time.h>
class c_mushroom {

private:
	int growedAge;
	float birthday;
public:

	c_mushroom() {
		this->birthday = clock()/1000;
		this->growedAge = 10;
	}

	bool isGrowed() {
		if ((clock() / 1000 - birthday) >= growedAge) {
			return true;
		}
		return false;
	}

	int getAge() {
		return  growedAge - (clock() / 1000 - birthday);
	}
};