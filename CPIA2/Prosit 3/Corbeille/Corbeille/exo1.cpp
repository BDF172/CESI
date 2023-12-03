#include "pch.h"

using namespace std;

int Voiture::nbObj = 0;
int VoitureSport::nbObjSpo = 0;

void Voiture::obj_ini(int vitesseMax, int acceleration) {
	m_vitesse = 0; 
	m_vitesseMax = vitesseMax; 
	m_acceleration = acceleration;
}

Voiture::Voiture() {
	obj_ini(1, 1);
	nbObj++;
}

Voiture::Voiture(int vitesseMax, int acceleration) {
	if ((vitesseMax < 0 || vitesseMax > 100) || (acceleration < 1 || acceleration > 3)) throw runtime_error("Vitesse ou acceleration fournie invalide");
	obj_ini(vitesseMax, acceleration);
	nbObj++;
}

Voiture::~Voiture() {
	nbObj--;
}

bool Voiture::acceleration() {
	if (m_vitesse == m_vitesseMax) {
		cout << "La vitesse max a deja ete atteinte" << endl;
		return true;
	}
	else if (m_vitesse + m_acceleration > m_vitesseMax) {
		cout << "La vitesse max vient d'etre atteinte" << endl;
		m_vitesse = m_vitesseMax;
		return true;
	}
	else {
		cout << "Vitesse : " << m_vitesse << endl;
		m_vitesse += m_acceleration;
		return false;
	}
}

void Voiture::setAcceleration(int acceleration) {
	if (acceleration > 3 || acceleration < 1) throw runtime_error("Acceleration fournie invalidde");
	m_acceleration = acceleration;
}

void Voiture::setVitesseMax(int vitesseMax) {
	if (vitesseMax > 100 || vitesseMax < 0) throw runtime_error("Vitesse maximum fournie invalidde");
	m_vitesseMax = vitesseMax;
}

int Voiture::getAcceleration() const {
	return m_acceleration;
}

int Voiture::getVitesse() const {
	return m_vitesse;
}

int Voiture::getVitesseMax() const {
	return m_vitesseMax;
}

int Voiture::getNbVoitures() {
	return nbObj;
}

VoitureSport::VoitureSport() : Voiture() {}

VoitureSport::VoitureSport(int vitesseMax, int acceleration) {
	if (vitesseMax < 0 || vitesseMax > 200) throw runtime_error("Vitesse max invalide pour la voiture de sport");
	if (acceleration < 1 || acceleration > 8) throw runtime_error("Acceleration fournie invalide pour la voiture de sport");
	obj_ini(vitesseMax, acceleration);
	nbObjSpo++;
}

VoitureSport::~VoitureSport() {
	nbObjSpo--;
}

void VoitureSport::setAcceleration(int acceleration) {
	if (acceleration < 1 || acceleration > 8) throw runtime_error("Acceleration fournie invalide pour la voiture de sport");
	m_acceleration = acceleration;
}

int VoitureSport::getNbVoitures() {
	return nbObjSpo;
}

void VoitureSport::setVitesseMax(int vitesseMax) {
	if (vitesseMax < 0 || vitesseMax > 200) throw runtime_error("Acceleration fournie invalide pour la voiture de sport");
	m_vitesseMax = vitesseMax;
}

int mainExo1(void) {
	Voiture voiture1(100,3);
	Voiture* voiture2 = new Voiture(100, 3);
	VoitureSport voitureS1(200, 8);
	Voiture* voitureS2 = new VoitureSport(200, 8);

	while (voiture1.acceleration() && voiture2->acceleration() && voitureS1.acceleration() && voitureS2->acceleration());
	cout << endl << "Nombre de voitures : " << Voiture::getNbVoitures() << endl;
	cout << "Nombre de voitures de sports : " << VoitureSport::getNbVoitures() << endl;
	delete voitureS2;
	cout << "Nombre de voitures de sports : " << VoitureSport::getNbVoitures() << endl;
	delete voiture2;
	return 0;
}