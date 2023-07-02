#include "Error.h"

InvalidArgument::InvalidArgument(const char* error) : std::invalid_argument(error) {}

NegativeValue::NegativeValue(const char* error) : std::invalid_argument(error) {};

WrongVehicleError::WrongVehicleError(const char* error) : std::logic_error(error) {};

DoubleVehicleError::DoubleVehicleError(const char* error) : std::logic_error(error) {};
