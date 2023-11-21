#include "mainHeader.h"

using namespace std;

void fonctionExo1(void) {
	cout << "Message de la fonction" << endl;
}

typedef void (*evt)(void);
evt e;

int mainExo1(void) {
	e = &fonctionExo1;
	e();

	return 0;
}