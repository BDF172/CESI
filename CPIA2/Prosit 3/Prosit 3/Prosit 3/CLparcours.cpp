#include "pch.h"

using namespace std;

CLparcours::CLparcours(int size) : m_size(size), nbVal(0), pointTab(new CLpoint*[size]) {}

long double CLparcours::calculDistance() const {
	long double distance = 0;
	for (int i = 1; i < nbVal; i++) {
		distance += pointTab[i - 1]->getDistance(*pointTab[i]);
	}
	return distance;
}

void CLparcours2D::ajouterPoint(CLpoint* point) {
	if (point->getDimension() != 2) throw runtime_error("Impossible d'ajouter un point qui n'est pas de 2 dimensions");
	pointTab[nbVal++] = point;
} 

void CLparcours2D::afficherMessage() {
	cout << "Calcul dans un repere a deux dimensions" << endl;
}

void CLparcours3D::ajouterPoint(CLpoint* point) {
	if (point->getDimension() != 3) throw runtime_error("Impossible d'ajouter un point qui n'est pas de 3 dimensions");
		pointTab[nbVal++] = point;
}

void CLparcours3D::afficherMessage() {
	cout << "Calcul dans un repere a trois dimensions" << endl;
}