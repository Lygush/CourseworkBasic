#include "Eagle.h"

#define SPEED 8
#define NAME "Îð¸ë"

Eagle::Eagle() : AirVehicle(SPEED, NAME) {}

double Eagle::Time(double distance) {
	return (distance * 0.94) / GetSpeed();
}