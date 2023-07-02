#include "Centaur.h"

#define SPEED 15
#define BEFORE_REST 8
#define REST 2
#define NAME "Кентавр"

Centaur::Centaur() : LandVehicle(SPEED, BEFORE_REST, NAME) {
	this->rest = REST;
}

double Centaur::Time(double distance) {
	double time{ distance / GetSpeed() };
	int countOfRest{ (static_cast<int>(time / GetBeforeRest()))};
	if (countOfRest == 0) {
		return time;
	}
	if (static_cast<int>(time) % static_cast<int>(GetBeforeRest()) == 0) {
		countOfRest--;
	}
	return time + countOfRest * rest;
}