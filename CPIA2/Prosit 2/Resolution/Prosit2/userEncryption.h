#pragma once

class userEncryption {
public:
	userEncryption();
	userEncryption(std::string messageToSet);
	userEncryption(const userEncryption& toCopy);

	void setMessage(std::string messageToSet);
	std::string getMessage() const;
	void encryptMessage(int mode, std::string xorKey, int distCesar);
	int getEncryptionLevel() const;

	void askToInputMessage();
	void askEncryptionChoice();
	void askWhereToSave();
	void getUserChoice(std::string& choix);

	static void getXORKey(std::string& xorKey);
	static void getUserCesarNumber(std::string& distCesar);

private:
	void obj_ini(std::string messageToSet, int level);
	Encrypt obj;
};