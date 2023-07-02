#include "Check.h"

bool Check::TrueSymbol(std::string test) {
	try {
		for (int i{}; i < test.length(); ++i) {
			if (test[i] < 48 || test[i] > 57) {
				throw InvalidArgument("Ответ содержит недопустимый символ. Введите цифру выбранного варианта.");
			}
		}
	}
	catch (InvalidArgument error) {
		system("cls");
		std::cout << error.what() << std::endl;
		return false;
	}
	return true;
}

bool Check::Range(std::string test, int min, int max) {
	try {
		if (std::stoi(test) < min || std::stoi(test) > max) {
			throw InvalidArgument("Такого варианта нет. Введите цифру выбранного варианта.");
		}
	}
	catch (InvalidArgument error) {
		system("cls");
		std::cout << error.what() << std::endl;
		return false;
	}
	return true;
}

bool Check::TrueSymbolDistance(std::string test) {
	try {
		if (test[0] == '-') {
			for (int i{1}; i < test.length(); ++i) {
				if (test[i] < 46 || test[i] > 57) {
					throw InvalidArgument("Ответ содержит недопустимый символ. Если число не целое, используйте точку для разделения целой и дробной части.");
				}
			}
			throw NegativeValue("Значение должно быть положительно!");
		}
		for (int i{}; i < test.length(); ++i) {
			if (test[i] < 46 || test[i] > 57 || test[i] == 47) {
				throw InvalidArgument("Ответ содержит недопустимый символ. Если число не целое, используйте точку для разделения целой и дробной части.");
			}
		}
	}
	catch (NegativeValue error) {
		system("cls");
		std::cout << error.what() << std::endl;
		return false;
	}
	catch (InvalidArgument error) {
		system("cls");
		std::cout << error.what() << std::endl;
		return false;
	}
	return true;
}

bool Check::WrongVehicle(LandVehicle*, std::string forbiddenVehicle)  {
	try {
		if (typeid(LandVehicle).name() == forbiddenVehicle) {
			throw WrongVehicleError("Попытка зарегестрировать неправильный тип транспортного средства!");
		}
	}
	catch (WrongVehicleError error) {
		system("cls");
		std::cout << error.what() << std::endl;
		return false;
	}
	return true;
}

bool Check::WrongVehicle(AirVehicle*, std::string forbiddenVehicle) {
	try {
		if (typeid(AirVehicle).name() == forbiddenVehicle) {
			throw WrongVehicleError("Попытка зарегестрировать неправильный тип транспортного средства!");
		}
	}
	catch (WrongVehicleError error) {
		system("cls");
		std::cout << error.what() << std::endl;
		return false;
	}
	return true;
}

bool Check::DoubleVehicle(LandVehicle* vehicle, Race* race) {
	try {
		for (int i{}; i < race->GetNOP(); ++i) {
			if (race->GetPlayers()[i].GetName() == vehicle->GetName()) {
				throw DoubleVehicleError("уже зарегестрированно!");
			}
		}
	}
	catch (DoubleVehicleError error) {
		system("cls");
		std::cout << "Транспортное средство \"" << vehicle->GetName() << "\" " << error.what() << std::endl;
		return false;
	}
	return true;
}

bool Check::DoubleVehicle(AirVehicle* vehicle, Race* race) {
	try {
		for (int i{}; i < race->GetNOP(); ++i) {
			if (race->GetPlayers()[i].GetName() == vehicle->GetName()) {
				throw DoubleVehicleError("уже зарегестрированно!");
			}
		}
	}
	catch (DoubleVehicleError error) {
		system("cls");
		std::cout << "Транспортное средство \"" << vehicle->GetName() << "\" " << error.what() << std::endl;
		return false;
	}
	return true;
}
