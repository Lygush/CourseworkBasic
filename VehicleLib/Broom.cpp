#include "Broom.h"

#define SPEED 20
#define NAME "Метла"

Broom::Broom() : AirVehicle(SPEED, NAME) {}

double Broom::Time(double distance) {
	if (distance < 1000) {
		return distance / GetSpeed();
	}
	else {
		return (distance * (1 - 0.01 * static_cast<int>(distance / 1000))) / GetSpeed();
	}
}