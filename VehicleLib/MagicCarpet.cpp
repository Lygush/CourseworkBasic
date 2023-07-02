#include "MagicCarpet.h"

#define SPEED 10
#define NAME "Ковёр-самолёт"

MagicCarpet::MagicCarpet() : AirVehicle(SPEED, NAME) {}

double MagicCarpet::Time(double distance) {
	if (distance < 1000) {
		return distance / GetSpeed();
	}
	else if (distance < 5000) {
		return (distance * 0.97) / GetSpeed();
	}
	else if (distance < 10000) {
		return (distance * 0.9) / GetSpeed();
	}
	else {
		return (distance * 0.95) / GetSpeed();
	}
}