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

// ����� ������������� �������� ��� ������� ����������
// ��� ������� �������� ��������� ��������� ����� ����� �����

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool game{ true };
	Check check;
	std::string choice{};

	std::cout << "����� ���������� � �������� ���������!" << std::endl;
	do {
		do {
			std::cout << "1. ����� ��� ��������� ����������" << std::endl;
			std::cout << "2. ����� ��� ���������� ����������" << std::endl;
			std::cout << "3. ����� ��� ��������� � ���������� ����������" << std::endl;
			std::cout << "�������� ��� �����: ";
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
			std::cout << "������� ����� ��������� � ���������� (������ ���� ������������): ";
			std::cin >> distanceTest;
		} while (!(check.TrueSymbolDistance(distanceTest)));
		distance = std::stod(distanceTest);

		system("cls");

		Race race(ALL_VEHICLE, distance);
		std::string typeNDist{};
		switch (raceType)
		{
		case 1:
			typeNDist = "����� ��� ��������� ����������. ����������: " + distanceTest + " ��";
			break;
		case 2:
			typeNDist = "����� ��� ���������� ����������. ����������: " + distanceTest + " ��";
			break;
		case 3:
			typeNDist = "����� ��� ��������� � ���������� ����������. ����������: " + distanceTest + " ��";
			break;
		}

		int max{ 1 };
		bool mainMenu{ true };
		do {
			do {
				if (std::stoi(choice) == 0) {
					system("cls");
				}
				// ���� �� ����������������� 2 �� �������� �������������� � ����������� ������� 2-� ��
				if (race.GetNOP() < 2) {
					std::cout << "������ ���� ����������������� ������� 2 ������������ ��������" << std::endl;
				}
				if (race.GetNOP() > 0) {
					std::cout << "��������� �����: ";
					for (int i{}; i < race.GetNOP(); ++i) {
						std::cout << race.GetPlayers()[i].GetName();
						if (race.GetNOP() > i + 1) {
							std::cout << ", ";
						}
					}
					std::cout << std::endl;
				}
				// 1. ���������������� ���������
				std::cout << "1. ���������������� ���������" << std::endl;
				// 2. ������ �����
				if (race.GetNOP() >= 2) {
					std::cout << "2. ������ �����" << std::endl;
					max = 2;
				}
				// �������� ��������
				std::cout << "�������� ��������: ";
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
								std::cout << "������������������ ������������ ��������: ";
								for (int i{}; i < race.GetNOP(); ++i) {
									std::cout << race.GetPlayers()[i].GetName();
									if (race.GetNOP() > i + 1) {
										std::cout << ", ";
									}
								}
								std::cout << std::endl;
							}
							// ������� ���� ��
							std::cout << "1. " << "�������-���������" << std::endl;
							std::cout << "2. " << "�����" << std::endl;
							std::cout << "3. " << "�������" << std::endl;
							std::cout << "4. " << "�������" << std::endl;
							std::cout << "5. " << "���" << std::endl;
							std::cout << "6. " << "�������-���������" << std::endl;
							std::cout << "7. " << "����-������" << std::endl;
							std::cout << "0. " << "��������� �����������" << std::endl;
							std::cout << "�������� ��������� ��� \"0\" ��� ���������� �����������: ";
							std::cin >> choice;
						} while (!(check.TrueSymbol(choice) && check.Range(choice, 0, 7))); //���� �� ������ ���������� ����� ��������
						switch (std::stoi(choice))
						{
						case 0:
							break;
						case 1: {
							RoverBoots RB;
							if (check.WrongVehicle(&RB, forbiddenVehicle) && (check.DoubleVehicle(&RB, &race))) {
								race.Add(&RB);
								system("cls");
								std::cout << "�������-��������� ������� ����������������!" << std::endl;
							}
							break;
						}
						case 2: {
							Broom B;
							if (check.WrongVehicle(&B, forbiddenVehicle) && (check.DoubleVehicle(&B, &race))) {
								race.Add(&B);
								system("cls");
								std::cout << "����� ������� ����������������!" << std::endl;
							}
							break;
						}
						case 3: {
							Camel C;
							if (check.WrongVehicle(&C, forbiddenVehicle) && (check.DoubleVehicle(&C, &race))) {
								race.Add(&C);
								system("cls");
								std::cout << "������� ������� ����������������!" << std::endl;
							}
							break;
						}
						case 4: {
							Centaur cent;
							if (check.WrongVehicle(&cent, forbiddenVehicle) && (check.DoubleVehicle(&cent, &race))) {
								race.Add(&cent);
								system("cls");
								std::cout << "������� ������� ���������������!" << std::endl;
							}
							break;
						}
						case 5: {
							Eagle E;
							if (check.WrongVehicle(&E, forbiddenVehicle) && (check.DoubleVehicle(&E, &race))) {
								race.Add(&E);
								system("cls");
								std::cout << "��� ������� ���������������!" << std::endl;
							}
							break;
						}
						case 6: {
							FastCamel FC;
							if (check.WrongVehicle(&FC, forbiddenVehicle) && (check.DoubleVehicle(&FC, &race))) {
								race.Add(&FC);
								system("cls");
								std::cout << "�������-��������� ������� ���������������!" << std::endl;
							}
							break;
						}
						case 7: {
							MagicCarpet MC;
							if (check.WrongVehicle(&MC, forbiddenVehicle) && (check.DoubleVehicle(&MC, &race))) {
								race.Add(&MC);
								system("cls");
								std::cout << "����-������ ������� ���������������!" << std::endl;
							}
							break;
						}
						}
					} while (std::stoi(choice) != 0); // ���� �� ������ 0
					break;
				}
				case 2:
				{
					race.Result();
					std::cout << "���������� �����: \n" << race << std::endl;

					do {
						std::cout << "1. �������� ��� �����" << std::endl;
						std::cout << "2. �����" << std::endl;
						std::cout << "�������� ��������: ";
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
			} while (!(check.TrueSymbol(choice) && check.Range(choice, 1, max))); // ���������� ����� ������ ����
		} while (mainMenu);
		
	} while (game);
}