#pragma once
#include "AirVehicle.h"

class Broom : public AirVehicle {
public:
	AIRVEHICLE_API Broom();

	double Time(double) override;
};