#include "Corbeille_1.h"

using namespace std;

void CLvoiture::ini_obj(int vitesseMax, int acceleration) {
	m_vitesseMax = vitesseMax;
	m_acceleration = acceleration;
	m_vitesse = 0;
	m_idV = generateID();
}

CLvoiture::CLvoiture() {
	ini_obj(0, 0);
	m_idVoiture = 0; // Nous pourrions ajouter un ID vers une BDD à l'avenir.
}

CLvoiture::CLvoiture(int vitesseMax, int acceleration) {
	ini_obj(vitesseMax, acceleration);
	m_idVoiture = 0; // Nous pourrions ajouter un ID vers une BDD à l'avenir.
}

CLvoiture::CLvoiture(const CLvoiture& toCopy) {
	ini_obj(toCopy.getVitesseMax(), toCopy.getAcceleration());
	m_idVoiture = 0; // Nous pourrions ajouter un ID vers une BDD à l'avenir.
}

int CLvoiture::getAcceleration() const {
	return m_acceleration;
}

int CLvoiture::getVitesseMax() const {
	return m_vitesseMax;
}

int CLvoiture::generateID(){
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<int> distribution(0, 10000);
	return distribution(generator);
}

int CLvoiture::getID() const {
	return m_idV;
}

void CLvoiture::setAcceleration(int acceleration) {
	m_acceleration = acceleration;
}

void CLvoiture::setVitesseMax(int vitesseMax) {
	m_vitesseMax = vitesseMax;
}

bool CLvoiture::accelerer() {
	if (m_vitesseMax - m_vitesse < m_acceleration) {
		cout << "La voiture " << m_idV << " a atteint sa vitesse maximum : " << m_vitesseMax << endl;
		return false;
	}
	m_vitesse += m_acceleration;
	cout << "Vitesse voiture " << m_idV << " : " << m_vitesse << endl;
	return true;
}