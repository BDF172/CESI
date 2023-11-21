#include "mainHeader.h"

using namespace std;

typedef void(*methodePtr)(void);
methodePtr methode;

class B {
public:
	B() {
		methode = &B::m;
	}
	static void m(void) {
		cout << "Methode m Classe B" << endl;
	}
};

class A {
public:
	void m(void) {
		cout << "Methode m Classe A" << endl;
		methode();
	}
};

int mainExo5() {
	A objetA;
	B objetB;

	objetA.m();

	return 0;
}