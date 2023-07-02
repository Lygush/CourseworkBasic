#include "LandVehicle.h"

LandVehicle::LandVehicle(double speed, double beforeRest, std::string name) {
	this->speed = speed;
	this->beforeRest = beforeRest;
	this->name = name;
}

double LandVehicle::GetSpeed() {
	return this->speed;
}

double LandVehicle::GetBeforeRest() {
	return this->beforeRest;
}

std::string LandVehicle::GetName() {
	return this->name;
}
