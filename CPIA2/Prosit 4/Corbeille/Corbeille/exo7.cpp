#include "mainHeader.h"

using namespace std;
class A{
private:
	int* t;

public:
	A(int tailleTab){
		t = new int[tailleTab];
	}

	~A() {
		delete[] t;
	}
};
void main(void){
	double i;
	A* p;
	for (i = 0; i < 100000; i++) {
		p = new A(10);
		delete p;  // Supprimer p pour libérer la mémoire prise et appeler son
	}			   // destructeur pour libérer la mémoire de son tableau dynamique
}
