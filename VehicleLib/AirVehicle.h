#pragma once
#include <string>

#ifndef AIRVEHICLE_API
#define AIRVEHICLE_API __declspec(dllexport)
#else 
#define AIRVEHICLE_API __declspec(dllimport)
#endif // !AIRVEHICLE_API

class AirVehicle {
private:
	double speed{};
	std::string name{};
public:
	AirVehicle(double, std::string name);

	double GetSpeed();
	AIRVEHICLE_API std::string GetName();

	virtual double Time(double) = 0;
};