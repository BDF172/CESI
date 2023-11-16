#include "pch.h"

using namespace std;

void Encrypt::setEncryptionLevel(int level) {
	level1Bool = (level == 1 || level == 3);
	level2Bool = (level == 2 || level == 3);
	level3Bool = (level == 3);
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
	if (level1Bool || level2Bool)throw runtime_error("Vous essayez de changer le contenu du message pourtant encrypte");
	m_msg = "#" + toSet + "#";
}

void Encrypt::level1(int niveau) {
	if (level1Bool) throw runtime_error("Le message a deja ete encrypte par cesar");
	for (; niveau > 0; niveau--) {
		for (int i = 0; i < m_msg.size(); i++) {
			m_msg[i] = (m_msg[i]) >= 126 ? 32 : m_msg[i] + 1;
		}
	}
	level1Bool = true;
}

void Encrypt::level1Decrypt(int niveau) {
	if (!level1Bool) throw runtime_error("Le message n'est pas encrypte en cesar");
	if (level2Bool) throw runtime_error("Le message ne peut pas etre decrypte en cesar sans etre decrypte du XOR");
	for (; niveau > 0; niveau--) {
		for (int i = 0; i < m_msg.size(); i++) {
			m_msg[i] = (m_msg[i] <= 32) ? 126 : m_msg[i] - 1;
		}
	}
	level1Bool = false;
}

void Encrypt::encryptDecryptXOR(string& message, const string& key) {
	for (size_t i = 0; i < message.length(); ++i) {
		message[i] = ((message[i]) ^ (key[i % key.length()]));
	}
}


void Encrypt::level2(string cle) {
	if (level2Bool) throw runtime_error("Le message est deja encrypte xor");
	encryptDecryptXOR(m_msg, cle);
	level2Bool = true;
}

void Encrypt::level2Decrypt(string cle) {
	if (!level2Bool) throw runtime_error("Le message n'est pas encrypte xor");
	encryptDecryptXOR(m_msg, cle);
	level2Bool = false;
}

void Encrypt::level3(int niveau, string cle) {
	level1(niveau);
	level2(cle);
	level3Bool = true;
}

void Encrypt::level3Decrypt(int niveau, std::string cle) {
	level2Decrypt(cle);
	level1Decrypt(niveau);
	level3Bool = false;
}

bool Encrypt::writeToFile(string fileName) {
	ofstream file;
	file.open(fileName.c_str(), ios::binary);
	if (!file) {
		cout << "Impossible d'ouvrir le ficihier" << endl;
		return false;
	}
	string encryption;
	if (getEncryptionLevel() == 3) encryption = "3";
	else if (getEncryptionLevel() == 1) encryption = "1";
	else if (getEncryptionLevel() == 2) encryption = "2";
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
	if (level3Bool) return 3;
	if (level2Bool) return 2;
	if (level1Bool) return 1;
	return 0;
}