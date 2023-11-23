#pragma once

typedef void (*fonctionCallback)(std::string, int from);

class Emetter {
public:
	Emetter(int ID);
	void diffuserMessage(std::string message, fonctionCallback antenne);
private:
	int m_ID;
};