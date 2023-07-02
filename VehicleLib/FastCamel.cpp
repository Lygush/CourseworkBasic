#include "FastCamel.h"

#define SPEED 40
#define BEFORE_REST 10
#define FIRST_REST 5
#define SECOND_REST 6.5
#define THERD_REST 8
#define NAME "Верблюд-быстроход"


FastCamel::FastCamel() : Camel(SPEED, BEFORE_REST, FIRST_REST, SECOND_REST, NAME) {
	this->thirdRest = THERD_REST;
}

double FastCamel::Time(double distance) {
	double time{ distance / GetSpeed() };
	if (time <= GetBeforeRest()) {
		return time;
	}
	else if ((time > GetBeforeRest()) && (time <= GetBeforeRest() * 2)) {
		return time + GetFirstRest();
	}
	else if ((time > GetBeforeRest() * 2) && (time <= GetBeforeRest() * 3)) {
		return time + GetFirstRest() + GetSecondRest();
	}
	else {
		int countOfRest{ (static_cast<int>(time / GetBeforeRest())) - 2 };
		if (static_cast<int>(time) % static_cast<int>(GetBeforeRest()) == 0) {
			countOfRest--;
		}
		return time + GetFirstRest() + GetSecondRest() + countOfRest * thirdRest;
	}
}