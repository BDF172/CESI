  #include "Corbeille_1.h"

using namespace std;

listData::listData() {
	tab = (int*)NULL;
	tabSize = 0; 
}

listData::listData(int premier) {
	tab = new int;
	*tab = premier;
	tabSize = 1;
}

listData::~listData() {
	delete tab;
}

void listData::ajouter(int valeur) {
	int* tempPtr = new int[static_cast<int64_t>(tabSize) + 1];
	for (int i = 0; i < tabSize; i++) {
		tempPtr[i] = tab[i];
	}
	tempPtr[tabSize++] = valeur;
	if(tabSize != 0)delete[] tab;
	tab = tempPtr;
}

int listData::maxValue() {
	int maximum = tab[0];
	for (int i = 0; i < tabSize; i++) {
		if (maximum < tab[i]) maximum = tab[i];
	}
	return maximum;
}

int listData::minValue() {
	int minimum = tab[0];
	for (int i = 0; i < tabSize; i++) {
		if (minimum > tab[i]) minimum = tab[i];
	}
	return minimum;
}

int listData::somme() {
	int somme = 0;
	for (int i = 0; i < tabSize; i++) {
		somme += tab[i];
	}
	return somme;
}

double listData::moyenne() {
	return (double)somme() / tabSize;
}

int listData::variationMax() {
	return maxValue() - minValue();
}
