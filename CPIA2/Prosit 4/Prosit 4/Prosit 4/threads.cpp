#include "linker.h"

using namespace std;

void createRadioStation(int nbRadios) {
	Receiver poste;
	poste.sAbonner(1);
	poste.update();
	while (poste.getAntennaState()) {
		poste.waitForNewMessage();
		poste.listen();
	}
}