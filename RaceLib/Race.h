#pragma once
#include "RaceResult.h"
#include "LandVehicle.h"
#include "AirVehicle.h"
#include <iostream>

#ifndef RACE_API
#define RACE_API __declspec(dllexport)
#else 
#define RACE_API __declspec(dllimport)
#endif // !RACE_API

class Race {
private:
	RaceResult* players{};
	double distance{};
	int numberOfPlayer{};
public:
	RACE_API Race(int, double);
	RACE_API ~Race();
	RACE_API int GetNOP();
	RACE_API RaceResult* GetPlayers();
	RACE_API virtual void Add(LandVehicle*);
	RACE_API virtual void Add(AirVehicle*);

	RACE_API void Result();

	RACE_API friend std::ostream& operator<<(std::ostream&, const Race&);

};