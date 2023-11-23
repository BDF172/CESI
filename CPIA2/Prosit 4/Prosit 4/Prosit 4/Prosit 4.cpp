#include "linker.h"

using namespace std;

int main(void) {
	fonctionCallback antenne = &Receiver::receiveMessage;
	Emetter radios[3];

	thread myThreads[5];
	for (int i = 0; i < 5; i++) {
		myThreads[i] = thread(createRadioStation, 3);
		myThreads[i].detach();
	}

	connectToRadio(radios, 3, antenne);
	Receiver::turnOffAntenna();

	return 0;
}