#include "pch.h"

using namespace std;

void Encrypt::setEncryptionLevel(int level) {
	encryptionLevel = level;
}

void Encrypt::obj_ini(string messageToSet, int level) {
	m_msg = messageToSet;
	setEncryptionLevel(level);
}

Encrypt::Encrypt() {
	obj_ini("", 0);
}

Encrypt::Encrypt(string messageToSet) {
	obj_ini(messageToSet, 0);
}

Encrypt::Encrypt(string messageToSet, int encryptMethod) {
	obj_ini(messageToSet, encryptMethod);
}

Encrypt::Encrypt(const Encrypt& toCopy) {
	obj_ini(toCopy.getMsg(), toCopy.getEncryptionLevel());
}

string Encrypt::getMsg() const {
	return m_msg;
}

void Encrypt::setMsg(std::string toSet) {
	if (encryptionLevel > 0)throw runtime_error("Vous essayez de changer le contenu du message pourtant encrypte");
	m_msg = "#" + toSet + "#";
}

void Encrypt::level1(int niveau) {
	if (encryptionLevel == 1) throw runtime_error("Le message a deja ete encrypte par cesar");
	for (; niveau > 0; niveau--) {
		for (int i = 0; i < m_msg.size(); i++) {
			m_msg[i] = (m_msg[i]) >= 126 ? 32 : m_msg[i] + 1;
		}
	}
	encryptionLevel = 1;
}

void Encrypt::level1Decrypt(int niveau) {
	if (!encryptionLevel == 1) throw runtime_error("Le message n'est pas encrypte en cesar");
	if (encryptionLevel > 1) throw runtime_error("Le message ne peut pas etre decrypte en cesar sans etre decrypte du XOR");
	for (; niveau > 0; niveau--) {
		for (int i = 0; i < m_msg.size(); i++) {
			m_msg[i] = (m_msg[i] <= 32) ? 126 : m_msg[i] - 1;
		}
	}
	encryptionLevel = 0;
}

void Encrypt::encryptDecryptXOR(string& message, const string& key) {
	for (size_t i = 0; i < message.length(); ++i) {
		message[i] = ((message[i]) ^ (key[i % key.length()]));
	}
}


void Encrypt::level2(string cle) {
	if (encryptionLevel == 2) throw runtime_error("Le message est deja encrypte xor");
	encryptDecryptXOR(m_msg, cle);
	encryptionLevel = 2;
}

void Encrypt::level2Decrypt(string cle) {
	if (!encryptionLevel > 1) throw runtime_error("Le message n'est pas encrypte xor");
	encryptDecryptXOR(m_msg, cle);
	encryptionLevel = (encryptionLevel == 3);
}

void Encrypt::level3(int niveau, string cle) {
	level1(niveau);
	level2(cle);
	encryptionLevel = 3;
}

void Encrypt::level3Decrypt(int niveau, std::string cle) {
	level2Decrypt(cle);
	level1Decrypt(niveau);
}

bool Encrypt::writeToFile(string fileName) {
	ofstream file;
	file.open(fileName.c_str(), ios::binary);
	if (!file) {
		cout << "Impossible d'ouvrir le ficihier" << endl;
		return false;
	}
	string encryption = to_string(encryptionLevel);
	file << encryption;
	for (char i : getMsg()) {
		file << static_cast<BYTE>(i);
	}
	return true;
}

bool Encrypt::readFromFile(std::string fileName) {
	ifstream file;
	file.open(fileName.c_str(), ios::binary);
	if (!file) {
		return false;
	}
	string message((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
	int encryption = atoi(message.substr(0, 1).c_str());
	message = message.substr(1, message.size());
	obj_ini(message, encryption);
	return true;
}

int Encrypt::getEncryptionLevel() const {
	return encryptionLevel;
}