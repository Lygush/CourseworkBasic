#pragma once
#include "AirVehicle.h"

class MagicCarpet : public AirVehicle {
public:
	AIRVEHICLE_API MagicCarpet();

	double Time(double) override;
};