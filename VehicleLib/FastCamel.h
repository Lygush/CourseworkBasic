#pragma once
#include "Camel.h"

class FastCamel : public Camel {
private:
	double thirdRest{};
public:
	LANDVEHICLE_API FastCamel();
	LANDVEHICLE_API double Time(double) override;
};
