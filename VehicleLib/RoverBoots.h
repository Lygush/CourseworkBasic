#pragma once
#include "Camel.h"

class RoverBoots : public Camel {
public:
	LANDVEHICLE_API RoverBoots();

	double Time(double) override;
};
