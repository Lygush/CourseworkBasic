#include "RaceResult.h"

void RaceResult::SetName(std::string name) {
	this->name = name;
}

void RaceResult::SetTime(double time) {
	this->time = time;
}

std::string RaceResult::GetName() {
	return this->name;
}

double RaceResult::GetTime() {
	return this->time;
}