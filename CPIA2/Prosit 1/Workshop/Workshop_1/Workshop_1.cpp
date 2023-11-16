#include "pch.h"

using namespace std;

int mainExo1() {
	exo1 allocStatique;
	exo1* allocDynamique = new exo1;
	cout << "Statique : ";
	allocStatique.msgMethod();
	cout << "Dynamique : ";
	allocDynamique->msgMethod();
	return 0;
}

int mainExo2() {
	int pause;
	CLcalcul o1;
	CLcalcul o2(2);
	CLcalcul* p1;
	CLcalcul* p2;
	p1 = new CLcalcul();
	p2 = new CLcalcul(3);
	o1.carre(); o2.carre();  cout << o1.getN() << endl;  cout << o2.getN() << endl;
	p1->carre(); p2->carre();  cout << p1->getN() << endl;  cout << p2->getN() << endl;
	cout << "Il y a " << CLcalcul::cbnObj() << " objets";
	cin >> pause;
	return 0;
}

int main(void) {
	return mainExo2();
}
















int mainExo4() {
	fraction frac1(4, 2);
	fraction frac2(1, 2);
	fraction result = (frac1 * frac2);
	cout << result.getNum() << "/" << result.getDen() << endl;
	return 0;
}
