#include "pch.h"

using namespace std;

int CLcalcul::cpteObj = 0;

CLcalcul::CLcalcul() {
	ini(0);
	cpteObj++;
}

CLcalcul::CLcalcul(int val) {
	ini(val);
}

void CLcalcul::ini(int val) {
	n = val;
}

int CLcalcul::cbnObj() {
	return cpteObj;
}

void CLcalcul::carre() {
	cout << n * n << endl;
}

void CLcalcul::setN(int val) {
	if (val < 0) val = 0;
	else n = val;
}

int CLcalcul::getN() {
	return n;
}