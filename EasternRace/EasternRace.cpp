#include <iostream>
#include <Windows.h>
#include "LandVehicle.h"
#include "Camel.h"
#include "FastCamel.h"
#include "Centaur.h"
#include "RoverBoots.h"
#include "MagicCarpet.h"
#include "Eagle.h"
#include "Broom.h"
#include "Race.h"
#include "Error.h"
#include "Check.h"

#define ALL_VEHICLE 7

// Метла отрицательное значение при большом расстоянии
// При задании значения дистанции запретить минус после числа

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool game{ true };
	Check check;
	std::string choice{};

	std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
	do {
		do {
			std::cout << "1. Гонка для наземного транспорта" << std::endl;
			std::cout << "2. Гонка для воздушного транспорта" << std::endl;
			std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;
			std::cout << "Выберите тип гонки: ";
			std::cin >> choice;
		} while (!(check.TrueSymbol(choice) && check.Range(choice, 1, 3)));
		std::string forbiddenVehicle{};
		int raceType{ std::stoi(choice) };
		switch (std::stoi(choice))
		{
		case 1:
			forbiddenVehicle = "class AirVehicle";
			break;
		case 2:
			forbiddenVehicle = "class LandVehicle";
			break;
		case 3:
			forbiddenVehicle = "All vehicle";
			break;
		}
		system("cls");

		std::string distanceTest{};
		double distance{};
		do {
			std::cout << "Укажите длину дистанции в километрах (должна быть положительна): ";
			std::cin >> distanceTest;
		} while (!(check.TrueSymbolDistance(distanceTest)));
		distance = std::stod(distanceTest);

		system("cls");

		Race race(ALL_VEHICLE, distance);
		std::string typeNDist{};
		switch (raceType)
		{
		case 1:
			typeNDist = "Гонка для наземного транспорта. Расстояние: " + distanceTest + " км";
			break;
		case 2:
			typeNDist = "Гонка для воздушного транспорта. Расстояние: " + distanceTest + " км";
			break;
		case 3:
			typeNDist = "Гонка для наземного и воздушного транспорта. Расстояние: " + distanceTest + " км";
			break;
		}

		int max{ 1 };
		bool mainMenu{ true };
		do {
			do {
				if (std::stoi(choice) == 0) {
					system("cls");
				}
				// Пока не зарегестрированно 2 ТС выводить предупреждение о регистрации минимум 2-х ТС
				if (race.GetNOP() < 2) {
					std::cout << "Должно быть зарегестрированно минимум 2 транспортных средства" << std::endl;
				}
				if (race.GetNOP() > 0) {
					std::cout << "Участники гонки: ";
					for (int i{}; i < race.GetNOP(); ++i) {
						std::cout << race.GetPlayers()[i].GetName();
						if (race.GetNOP() > i + 1) {
							std::cout << ", ";
						}
					}
					std::cout << std::endl;
				}
				// 1. Зарегестрировать транспорт
				std::cout << "1. Зарегестрировать транспорт" << std::endl;
				// 2. Начать гонку
				if (race.GetNOP() >= 2) {
					std::cout << "2. Начать гонку" << std::endl;
					max = 2;
				}
				// Выберите действие
				std::cout << "Выберите действие: ";
				std::cin >> choice;
				if (!(check.TrueSymbol(choice) && check.Range(choice, 1, max))) {
					choice = '6';
					break;
				}
				system("cls");
				switch (std::stoi(choice))
				{
				case 1:
				{
					do {
						do {
							std::cout << typeNDist << std::endl;
							if (race.GetNOP() > 0) {
								std::cout << "Зарегестрированные транспортные средства: ";
								for (int i{}; i < race.GetNOP(); ++i) {
									std::cout << race.GetPlayers()[i].GetName();
									if (race.GetNOP() > i + 1) {
										std::cout << ", ";
									}
								}
								std::cout << std::endl;
							}
							// Вывовод всех ТС
							std::cout << "1. " << "Ботинки-вездеходы" << std::endl;
							std::cout << "2. " << "Метла" << std::endl;
							std::cout << "3. " << "Верблюд" << std::endl;
							std::cout << "4. " << "Кентавр" << std::endl;
							std::cout << "5. " << "Орёл" << std::endl;
							std::cout << "6. " << "Верблюд-быстроход" << std::endl;
							std::cout << "7. " << "Ковёр-самолёт" << std::endl;
							std::cout << "0. " << "Закончить регестрацию" << std::endl;
							std::cout << "Выберите транспорт или \"0\" для завершения регестрации: ";
							std::cin >> choice;
						} while (!(check.TrueSymbol(choice) && check.Range(choice, 0, 7))); //Пока не выбран правильный номер варианта
						switch (std::stoi(choice))
						{
						case 0:
							break;
						case 1: {
							RoverBoots RB;
							if (check.WrongVehicle(&RB, forbiddenVehicle) && (check.DoubleVehicle(&RB, &race))) {
								race.Add(&RB);
								system("cls");
								std::cout << "Ботинки-вездеходы успешно зарегестрированы!" << std::endl;
							}
							break;
						}
						case 2: {
							Broom B;
							if (check.WrongVehicle(&B, forbiddenVehicle) && (check.DoubleVehicle(&B, &race))) {
								race.Add(&B);
								system("cls");
								std::cout << "Метла успешно зарегестрирована!" << std::endl;
							}
							break;
						}
						case 3: {
							Camel C;
							if (check.WrongVehicle(&C, forbiddenVehicle) && (check.DoubleVehicle(&C, &race))) {
								race.Add(&C);
								system("cls");
								std::cout << "Верблюд успешно зарегестрированн!" << std::endl;
							}
							break;
						}
						case 4: {
							Centaur cent;
							if (check.WrongVehicle(&cent, forbiddenVehicle) && (check.DoubleVehicle(&cent, &race))) {
								race.Add(&cent);
								system("cls");
								std::cout << "Кентавр успешно зарегестрирован!" << std::endl;
							}
							break;
						}
						case 5: {
							Eagle E;
							if (check.WrongVehicle(&E, forbiddenVehicle) && (check.DoubleVehicle(&E, &race))) {
								race.Add(&E);
								system("cls");
								std::cout << "Орёл успешно зарегестрирован!" << std::endl;
							}
							break;
						}
						case 6: {
							FastCamel FC;
							if (check.WrongVehicle(&FC, forbiddenVehicle) && (check.DoubleVehicle(&FC, &race))) {
								race.Add(&FC);
								system("cls");
								std::cout << "Верблюд-быстроход успешно зарегестрирован!" << std::endl;
							}
							break;
						}
						case 7: {
							MagicCarpet MC;
							if (check.WrongVehicle(&MC, forbiddenVehicle) && (check.DoubleVehicle(&MC, &race))) {
								race.Add(&MC);
								system("cls");
								std::cout << "Ковёр-самолёт успешно зарегестрирован!" << std::endl;
							}
							break;
						}
						}
					} while (std::stoi(choice) != 0); // Пока не выбран 0
					break;
				}
				case 2:
				{
					race.Result();
					std::cout << "Результаты гонки: \n" << race << std::endl;

					do {
						std::cout << "1. Провести ещё гонку" << std::endl;
						std::cout << "2. Выйти" << std::endl;
						std::cout << "Выберите действие: ";
						std::cin >> choice;
						switch (std::stoi(choice))
						{
						case 1:
							system("cls");
							mainMenu = false;
							break;
						case 2:
							game = false;
							mainMenu = false;
							break;
						}
					} while ((!(check.TrueSymbol(choice) && check.Range(choice, 1, 2))));
				}
				}
			} while (!(check.TrueSymbol(choice) && check.Range(choice, 1, max))); // Правильный выбор пункта меню
		} while (mainMenu);
		
	} while (game);
}