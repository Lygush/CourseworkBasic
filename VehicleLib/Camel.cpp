#include "LandVehicle.h"
#include "Camel.h"

#define SPEED 10
#define BEFORE_REST 30
#define FIRST_REST 5
#define SECOND_REST 8
#define NAME "Верблюд"

Camel::Camel() : LandVehicle(SPEED, BEFORE_REST, NAME) {
	this->firstRest = FIRST_REST;
	this->secondRest = SECOND_REST;
}

Camel::Camel(double speed, double beforeRest, double firstRest, double secondRest, std::string name) : LandVehicle(speed, beforeRest, name) {
	this->firstRest = firstRest;
	this->secondRest = secondRest;
}

double Camel::Time(double distance) {
	double time { distance / GetSpeed() };
	if (time <= GetBeforeRest()) {
		return time;
	}
	else if ((time > GetBeforeRest()) && (time <= GetBeforeRest() * 2)) {
		return time + firstRest;
	}
	else {
		int countOfRest{ (static_cast<int>(time / GetBeforeRest())) - 1 };
		if (static_cast<int>(time) % static_cast<int>(GetBeforeRest()) == 0) {
			countOfRest--;
		}
		return time + firstRest + countOfRest * secondRest;
	}
}

double Camel::GetFirstRest() {
	return this->firstRest;
}

double Camel::GetSecondRest() {
	return this->secondRest;
}