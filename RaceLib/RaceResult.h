#pragma once
#include <string>

#ifndef RACERESULT_API
#define RACERESULT_API __declspec(dllexport)
#else 
#define RACERESULT_API __declspec(dllimport)
#endif // !RACERESULT_API

class RaceResult {
private:
	std::string name{};
	double time{};
public:
	void SetName(std::string);
	void SetTime(double);
	RACERESULT_API std::string GetName();
	double GetTime();
};
