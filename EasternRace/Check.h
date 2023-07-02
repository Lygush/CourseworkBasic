#pragma once
#include <iostream>
#include <string>
#include "Error.h"
#include "Race.h"
#include "LandVehicle.h"
#include "AirVehicle.h"

class Check {
public:
	bool TrueSymbol(std::string);
	bool Range(std::string, int, int);
	bool TrueSymbolDistance(std::string);
	virtual bool WrongVehicle(LandVehicle*, std::string);
	virtual bool WrongVehicle(AirVehicle*, std::string);
	virtual bool DoubleVehicle(LandVehicle*, Race*);
	virtual bool DoubleVehicle(AirVehicle*, Race*);
};
