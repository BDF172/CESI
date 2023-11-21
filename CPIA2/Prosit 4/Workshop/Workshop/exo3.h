#pragma once

typedef void (*methode)(int sender, std::string message);

class A {
public:
	A(int ID) : m_ID(ID) {}
	void emettre(std::string message, methode callback);

private:
	int m_ID;
};

class B {
public:
	B(int ID) : m_ID(ID) {}
	void follow(int toSub);
	void lireMessages(void);

	static void receiveMessage(int sender, std::string message);

private:
	static int m_sender;
	static std::string m_message;
	int m_ID;
	std::vector<int> toListen;
};

int mainExo3(void);