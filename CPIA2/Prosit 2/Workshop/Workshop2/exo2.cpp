#include "pch.h"

using namespace std;

void composant1::msg() {
	cout << "Message composant 1" << endl;
}

void composant2::msg() {
	cout << "Message composant 2" << endl;
}

void composant3::msg() {
	cout << "Message composant 3" << endl;
}

void gp2::gpcs2s1() {
	c1.msg();
	c3.msg();
}

void gp1::gpcs1s1() {
	c1.msg();
	c2.msg();
}

void gp1::gpcs1s2() {
	c3.msg();
}