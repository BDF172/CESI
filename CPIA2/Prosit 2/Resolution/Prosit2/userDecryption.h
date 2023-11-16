#pragma once

class userDecryption {
public:
	userDecryption();
	userDecryption(std::string pathToFile);
	userDecryption(const userDecryption& toCopy);

	void askWhereFile();
	bool askDecryptMessage();

	std::string getMessage();
	int getEncryptionLevel() const;

	static bool doesPathExist(const std::string& fileName);

private:
	void obj_ini(std::string path);
	Encrypt obj;
};