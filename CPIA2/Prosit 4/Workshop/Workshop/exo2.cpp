#include "linker.h"

using namespace std;

//Objet2DChaine::Objet2DChaine(void) {
//	head.maillon = nullptr;
//	head.maillonSuivant = nullptr;
//}
//
//Objet2DChaine::Objet2DChaine(Objet2D* premierMaillon) {
//	head.maillon = premierMaillon;
//	head.maillonSuivant = nullptr;
//}
//
//void Objet2DChaine::addMaillon(Objet2D* toAdd) {
//	if (head.maillon == nullptr) {
//		head.maillon = toAdd;
//		return;
//	}
//	objetChaine *tempPtr = &head;
//	while (tempPtr->maillonSuivant != nullptr) tempPtr = tempPtr->maillonSuivant;
//	tempPtr->maillonSuivant = new objetChaine{ toAdd, nullptr };
//}
//
//void Objet2DChaine::afficherInfos(void) {
//	objetChaine *temp = &head;
//	while (true) {
//		cout << temp->maillon->afficheInfo() << endl;
//		if (temp->maillonSuivant == nullptr) break;
//		temp = temp->maillonSuivant;
//	}
//}

Objet2DChaine::Objet2DChaine(void) : head(nullptr) {}
Objet2DChaine::Objet2DChaine(Objet2D *first) : head(first) {}

void Objet2DChaine::addMaillon(Objet2D* toAdd) {
	if (head == nullptr) {
		head = toAdd;
		return;
	}
	Objet2D* temp = head;
	while (temp->getSuivant() != nullptr) temp = temp->getSuivant();
	temp->setObjetSuivant(toAdd);
}

void Objet2DChaine::afficherInfos(void) {
	Objet2D* temp = head;
	while (true) {
		cout << temp->afficheInfo() << endl;
		if (temp->getSuivant() == nullptr) break;
		temp = temp->getSuivant();
	} 
}

int mainExo2(void) {
	Carre carre(4);
	Rectangle rectangle(4, 5);

	Objet2DChaine maChaine;
	maChaine.addMaillon(&carre);
	maChaine.addMaillon(&rectangle);

	maChaine.afficherInfos();

	return 0;
}