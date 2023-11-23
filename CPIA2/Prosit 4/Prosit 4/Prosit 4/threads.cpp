#include "linker.h"

using namespace std;

void createRadioStation(int nbRadios) {
	Receiver poste;
	poste.sAbonner(1);
	poste.update();
	while (Receiver::getAntennaState()) {
		if (poste.messageAvailable()) poste.listen();
		Sleep(10);
	}
}