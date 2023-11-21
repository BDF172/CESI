#include "pch.h"

using namespace std;

void Vehicule::laver(void) {
	isWashed = true;
	afficherMessage();
}

void Voiture3::afficherMessage(void) {
	cout << "Voiture lavee" << endl;
}

void Moto::afficherMessage(void) {
	cout << "Moto lavee" << endl;
}

void Station::addVehicule(Vehicule* toAdd) {
	toWash.push_back(toAdd);
}

void Station::washAllVehicules() {
	for (Vehicule* i : toWash) {
		i->laver();
	}
}

int mainExo3() {
	Voiture3 voiture1, voiture2;
	Moto moto;
	Station station;
	station.addVehicule(reinterpret_cast<Moto*>(&voiture1));
	station.addVehicule(voiture2);
	station.addVehicule(moto);
	station.washAllVehicules();

	return 0;
}