#include "RoverBoots.h"

#define SPEED 6
#define BEFORE_REST 60
#define FIRST_REST 10
#define SECOND_REST 5
#define NAME "Ботинки-вездеходы"

RoverBoots::RoverBoots() : Camel(SPEED, BEFORE_REST, FIRST_REST, SECOND_REST, NAME) {}

double RoverBoots::Time(double distance) {
	return Camel::Time(distance);
}