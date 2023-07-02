#pragma once
#include "AirVehicle.h"

class Eagle : public AirVehicle {
public:
	AIRVEHICLE_API Eagle();

	double Time(double) override;
};