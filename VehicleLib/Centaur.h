#pragma once
#include "LandVehicle.h"

class Centaur : public LandVehicle {
private:
	double rest{};
public:
	LANDVEHICLE_API Centaur();

	double Time(double) override;
};