#include "linker.h"

using namespace std;

int B::m_sender;
std::string B::m_message;

void A::emettre(string message, methode callback) {
	callback(m_ID, message);
}

void B::follow(int toSub) {
	toListen.push_back(toSub);
}

void B::lireMessages(void) {
	for (int i : toListen) {
		if (m_sender == i) {
			cout << "Poste " << m_ID
				<< ", Radio : " << m_sender <<
				", Message : " << m_message << endl;;
		}
	}
}

void B::receiveMessage(int sender, string message) {
	m_sender = sender;
	m_message = message;

}

int mainExo3(void) {
	methode toCallback = &B::receiveMessage;

	A radio1(1), radio2(2);
	B poste1(1), poste2(2), poste3(3);
	poste1.follow(1);
	poste2.follow(1), poste2.follow(2);
	poste3.follow(2);

	radio1.emettre("Premier message", toCallback);
	poste1.lireMessages(); poste2.lireMessages(); poste3.lireMessages();

	radio2.emettre("Deuxieme message", toCallback);
	poste1.lireMessages(); poste2.lireMessages(); poste3.lireMessages();

	return 0;
}