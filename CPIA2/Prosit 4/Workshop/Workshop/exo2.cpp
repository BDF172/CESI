#include "linker.h"

using namespace std;

Objet2DChaine::Objet2DChaine(void) : head(nullptr) {}
Objet2DChaine::Objet2DChaine(Objet2D *tete) : head(tete) {}
Objet2DChaine::~Objet2DChaine(void) { deleteChaine(head); }

void Objet2DChaine::deleteChaine(Objet2D* tete) {
	if (tete->getSuivant() != nullptr) deleteChaine(tete->getSuivant());
	delete tete;
}

int Objet2DChaine::getNbObjets() {
	int nb = 0;
	Objet2D* temp = head;
	while (temp != nullptr) {
		temp = temp->getSuivant();
		nb++;
	}
	return nb;
}

void Objet2DChaine::addMaillonAtTail(Objet2D* toAdd) {
	if (head == nullptr) {
		head = toAdd;
		return;
	}
	Objet2D* temp = head;
	while (temp->getSuivant() != nullptr) temp = temp->getSuivant();
	temp->setObjetSuivant(toAdd);
}

void Objet2DChaine::addMaillonAtHead(Objet2D* toAdd) {
	if (head == nullptr) {
		head = toAdd;
		return;
	}
	toAdd->setObjetSuivant(head);
	head = toAdd;
}

void Objet2DChaine::addMaillonAtIndex(Objet2D* toAdd, int index) {
	if (index < 0 || index > getNbObjets()) throw runtime_error("Demande d'ajout a un indice indexistant");
	if (index == 0) {
		addMaillonAtHead(toAdd);
		return;
	}
	Objet2D* temp = head;
	while (index > 1) {
		temp = temp->getSuivant();
		index--;
	}
	toAdd->setObjetSuivant(temp->getSuivant());
	temp->setObjetSuivant(toAdd);
	
}

void Objet2DChaine::afficherInfos(void) {
	Objet2D* temp = head;
	while (true) {
		cout << temp->afficheInfo() <<
			" : Aire = " << temp->getAire() <<
			" | Perimetre : " << temp->getPerimetre() << endl;
		if (temp->getSuivant() == nullptr) break;
		temp = temp->getSuivant();
	} 
}

int mainExo2(void) {
	Objet2DChaine *maChaine = new Objet2DChaine;
	maChaine->addMaillonAtTail(new Rectangle(4,5));
	maChaine->addMaillonAtHead(new Carre(6));
	maChaine->addMaillonAtIndex(new Rectangle(10, 10), 1);

	maChaine->afficherInfos();
	delete maChaine;

	return 0;
}