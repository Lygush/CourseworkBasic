#pragma once
#include <stdexcept>

class InvalidArgument : public std::invalid_argument {
public:
	InvalidArgument(const char*);
};

class NegativeValue : public std::invalid_argument {
public:
	NegativeValue(const char*);
};

class WrongVehicleError : public std::logic_error {
public:
	WrongVehicleError(const char*);
};

class DoubleVehicleError : public std::logic_error {
public:
	DoubleVehicleError(const char*);
};
