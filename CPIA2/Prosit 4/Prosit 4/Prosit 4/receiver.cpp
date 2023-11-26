#include "linker.h"

using namespace std;

stringChaine* Receiver::head = nullptr;
stringChaine* Receiver::tail = nullptr;
size_t Receiver::nbObjets = 0;
mutex Receiver::mutexNbObjets;
mutex Receiver::mutexIncomingMessage;
bool Receiver::antennaState = true;
Receiver* Receiver::headOfReceivers = nullptr;
Receiver* Receiver::tailOfReceivers = nullptr;

size_t stringChaine::getRadioID(void) {
	return atoi(this->substr(0, this->find_first_of('#')).c_str());
}

std::string stringChaine::getMessage(void) {
	return this->substr(this->find_first_of('#')+1, this->size());
}

void stringChaine::setSuivant(stringChaine* toSet) {
	this->suivant = toSet;
}

stringChaine* stringChaine::getSuivant(void) {
	return this->suivant;
}

Receiver::Receiver(void) : lastMessage(head), notified(false), suivant(nullptr) {
	cout << "~~~~~~Nouvel objet~~~~~~\n";
	lock_guard<mutex> lock(mutexNbObjets);
	m_ID = ++nbObjets;
	if (headOfReceivers == nullptr) headOfReceivers = tailOfReceivers = this;
	else {
		tailOfReceivers->setSuivant(this);
		tailOfReceivers = this;
	}
}

void Receiver::waitForNewMessage(void) {
	unique_lock<std::mutex> lock(mutexThreadPause);
	cvMsgWait.wait(lock, [this] {return notified; });
	notified = false;
}

void Receiver::notify(void) {
	{
		lock_guard<mutex> lock(mutexThreadPause);
		notified = true;
	}
	cvMsgWait.notify_one();
}

void Receiver::notifyAll(void) {
	lock_guard<mutex> lock(mutexNbObjets);
	Receiver* temp = headOfReceivers;
	while (temp != nullptr) {
		temp->notify();
		temp = temp->getSuivant();
	}
}

size_t Receiver::getNbMessages(void) {
	size_t toReturn = 0;
	stringChaine *temp = head;
	while (temp != nullptr) {
		temp = temp->getSuivant();
	}
	return toReturn;
}

void Receiver::update(void) {
	if (lastMessage == nullptr) return;
	do {
		for (int i : liste) {
			if (i == lastMessage->getRadioID()) {
				cout << "Poste " + to_string(this->getID()) + " :\n"
					+ lastMessage->getMessage() + "\n----------------\n";
			}
		}
		if (lastMessage->getSuivant() != nullptr) lastMessage = lastMessage->getSuivant();
	} while (lastMessage != nullptr);
}

void Receiver::listen() {
	lastMessage = tail;
	for (int i : liste) {
		if (i == lastMessage->getRadioID()) {
			cout << "Poste " + to_string(this->getID()) + " :\n"
			+ lastMessage->getMessage() + "\n----------------\n";
		}
	}
}

void Receiver::receiveMessage(std::string message, int from) {
	lock_guard<mutex> lock(mutexIncomingMessage);
	stringChaine* toAdd = new stringChaine;
	toAdd->append(to_string(from) + "#" +message);
	if (head != nullptr) {
		tail->setSuivant(toAdd);
		tail = toAdd;
	}
	else {
		head = tail = toAdd;
		if (getNbMessages() > 10) {
			toAdd = head;
			head = head->getSuivant();
			delete toAdd;
		}
	}
	notifyAll();
}

void Receiver::sAbonner(int toSub) {
	liste.push_back(toSub);
}

void Receiver::turnOffAntenna(void) {
	antennaState = false;
}