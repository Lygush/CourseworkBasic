#pragma once

#include <string>
#ifndef LANDVEHICLE_API
#define LANDVEHICLE_API __declspec(dllexport)
#else 
#define LANDVEHICLE_API __declspec(dllimport)
#endif // !LANDVEHICLE_API

class LandVehicle {
private:
	double speed{};
	double beforeRest{};
	std::string name{};
public:
	LandVehicle() {};
	LandVehicle(double, double, std::string);

	double GetSpeed();
	double GetBeforeRest();
	LANDVEHICLE_API std::string GetName();

	virtual double Time(double) = 0;
};
