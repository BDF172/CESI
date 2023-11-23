#pragma once

typedef void (*fonctionCallback)(std::string, int from);

class Emetter {
public:
	Emetter(void);
	void diffuserMessage(std::string message, fonctionCallback antenne);
private:
	int m_ID;
	static size_t nbObj;
	static std::mutex objLock;
};