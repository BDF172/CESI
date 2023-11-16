#pragma once



class Encrypt {
public:
	Encrypt(void);
	Encrypt(std::string messageToSet);
	Encrypt(std::string messageToSet, int encryptMethod);
	Encrypt(const Encrypt& toCopy);

	std::string getMsg() const;
	void setMsg(std::string toSet);
	
	void level1(int niveau);
	void level2(std::string cle);
	void level3(int niveau, std::string cle);

	void level1Decrypt(int niveau);
	void level2Decrypt(std::string cle);
	void level3Decrypt(int niveau, std::string cle);

	bool writeToFile(std::string fileName);
	bool readFromFile(std::string fileName);

	int getEncryptionLevel() const;
	void setEncryptionLevel(int level);
 
	void encryptDecryptXOR(std::string& messageToEncrypt, const std::string& key);

private:
	void obj_ini(std::string messageToSet, int level);
	std::string m_msg;
	
	bool level1Bool, level2Bool, level3Bool;
};