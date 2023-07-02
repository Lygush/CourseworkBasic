#include "Race.h"

Race::Race(int countOfPlayers, double distance) {
	this->distance = distance;
	players = new RaceResult[countOfPlayers];
}

Race::~Race() {
	delete[] players;
}

 int Race::GetNOP()
{
	return  this->numberOfPlayer;
}

  RaceResult* Race::GetPlayers()
 {
	 return this->players;
 }

void Race::Add(LandVehicle* player) {
	players[numberOfPlayer].SetName(player->GetName());
	players[numberOfPlayer].SetTime(player->Time(distance));
	numberOfPlayer++;
}

void Race::Add(AirVehicle* player) {
	players[numberOfPlayer].SetName(player->GetName());
	players[numberOfPlayer].SetTime(player->Time(distance));
	numberOfPlayer++;
}

void Race::Result() {
	for (int i{}; i < numberOfPlayer; ++i) {
		for (int j{}; j < numberOfPlayer - 1; ++j) {
			if (players[j].GetTime() > players[j + 1].GetTime()) {
				RaceResult temp;
				temp.SetName(players[j].GetName());
				temp.SetTime(players[j].GetTime());
				players[j].SetName(players[j + 1].GetName());
				players[j].SetTime(players[j + 1].GetTime());
				players[j + 1].SetName(temp.GetName());
				players[j + 1].SetTime(temp.GetTime());
			}
		}
	}
}

 std::ostream& operator<<(std::ostream& out, const Race& resultsOut) {
	for (int i{}; i < resultsOut.numberOfPlayer; ++i) {
		out << (i + 1) << ". " << resultsOut.players[i].GetName() << " " << resultsOut.players[i].GetTime() << "\n";
	}
	return out;
}
