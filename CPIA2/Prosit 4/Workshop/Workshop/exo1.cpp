#include "linker.h"

using namespace std;

int mainExo1(void) {
	int tabStatic[3] = { 1,2,3 };
	cout << "Contenu du tableau statique : " << endl;
	for (int i : tabStatic) {
		cout << "\t" << i << endl;
	}

	int *tabDynam = new int[3];
	tabDynam[0] = 1; tabDynam[1] = 2; tabDynam[2] = 3;
	cout << endl << "Contenu du tableau dynamique : " << endl;
	for (int i = 0; i < 3; i++) {
		cout << "\t" << tabDynam[i] << endl;
	}
	delete[] tabDynam;

	return 0;
}