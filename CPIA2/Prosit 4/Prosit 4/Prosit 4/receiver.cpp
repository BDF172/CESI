#include "linker.h"

using namespace std;

size_t Receiver::messageID = 0;
vector<int> Receiver::messageFrom;
vector <std::string> Receiver::messageContent;
size_t Receiver::nbObjets = 0;
mutex Receiver::mutexNbObjets;
mutex Receiver::mutexIncomingMessage;
bool Receiver::antennaState = true;

Receiver::Receiver(void) {
	cout << "~~~~~~Nouvel objet~~~~~~\n";
	lastMessage = 0;
	m_ID = ++nbObjets;
}

void Receiver::update(void) {
	while (lastMessage < messageID) {
		lastMessage++;
		for (int i : liste) {
			if (i == messageFrom[lastMessage - 1]) {
				cout << "Poste " + to_string(this->getID()) + " :\n"
					+ messageContent[lastMessage - 1] + "\n----------------\n";
			}
		}
	}
}

bool Receiver::messageAvailable(void) {
	lock_guard<mutex> lock(mutexIncomingMessage);
	return lastMessage != messageID;
}

void Receiver::listen() {
	lastMessage = messageID;
	for (int i : liste) {
		if (i == messageFrom[lastMessage - 1]) {
			cout << "Poste " + to_string(this->getID()) + " :\n"
			+ messageContent[messageID-1] + "\n----------------\n";
		}
	}
}

void Receiver::receiveMessage(std::string message, int from) {
	lock_guard<mutex> lock(mutexIncomingMessage);
	//if (messageContent.size() > 4) {
	//	messageContent.pop_back();
	//	messageFrom.pop_back();
	//}
	messageContent.push_back(message);
	messageFrom.push_back(from);
	messageID++;
}

void Receiver::sAbonner(int toSub) {
	liste.push_back(toSub);
}

void Receiver::turnOffAntenna(void) {
	antennaState = false;
}