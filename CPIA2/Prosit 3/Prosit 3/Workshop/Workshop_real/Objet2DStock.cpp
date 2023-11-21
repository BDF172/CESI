#include "mainHeader.h"

using namespace std;

Objet2DStock::Objet2DStock(int size) : m_size(size), objectAllocTable(new bool[size]), m_Objet2DTab(new Objet2D*[size]) {
	for (int i = 0; i < size; i++) {
		objectAllocTable[i] = false;
	}
}

Objet2DStock::~Objet2DStock() {
	delete m_Objet2DTab;
	delete objectAllocTable;
}

bool Objet2DStock::ajouterObjet(Objet2D& toAdd, int index) {
	if (index >= 0 && index < m_size)
		if (!objectAllocTable[index]) {
			m_Objet2DTab[index] = &toAdd;
			objectAllocTable[index] = true;
			return true;
		}
	return false;
}

bool Objet2DStock::ajouterObjet(Objet2D& toAdd) {
	for (int i = 0; i < m_size; i++) {
		if (ajouterObjet(toAdd, i)) return true;
	}
	return false;
}

void Objet2DStock::suppObjet(int index) {
	if (index >= 0 && index < m_size) objectAllocTable[index] = false;
}

void Objet2DStock::afficherInfos() {
	for (int i = 0; i < m_size; i++) {
		if (objectAllocTable[i]) {
			cout << m_Objet2DTab[i]->afficheInfo() << " a l'emplacement " << i+1 << " :" << endl;
			cout << "\tAire : " << m_Objet2DTab[i]->getAire() << endl;
			cout << "\tPerimetre : " << m_Objet2DTab[i]->getPerimetre() << endl;
		}
	}
}