#include "linker.h"

using namespace std;

int main(void) {
	fonctionCallback antenne = &Receiver::receiveMessage;
	Emetter radio1(1);
	Emetter radio2(2);

	thread myThreads[5];
	for (int i = 0; i < 5; i++) {
		myThreads[i] = thread(createRadioStation);
		myThreads[i].detach();
	}

	connectToRadio(&radio1, antenne);
	Receiver::turnOffAntenna();

	return 0;
}