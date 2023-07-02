#include "AirVehicle.h"

AirVehicle::AirVehicle(double speed, std::string name) {
	this->speed = speed;
	this->name = name;
}

double AirVehicle::GetSpeed() {
	return this->speed;
}

std::string AirVehicle::GetName() {
	return this->name;
}