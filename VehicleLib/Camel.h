#pragma once
#include "LandVehicle.h"

class Camel : public LandVehicle {
private:
	double firstRest{};
	double secondRest{};
public:
	LANDVEHICLE_API Camel();

	Camel(double, double, double, double, std::string);

	double Time(double) override;

	double GetFirstRest();
	double GetSecondRest();
};