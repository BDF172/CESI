#pragma once

class stringChaine : public std::string {
public:
	stringChaine(void) : std::string(), suivant(nullptr) {}
	stringChaine(std::string toInsert) : std::string(toInsert), suivant(nullptr) {}
	size_t getRadioID(void);
	std::string getMessage(void);
	stringChaine* getSuivant(void);
	void setSuivant(stringChaine* toSet);

private:
	stringChaine* suivant;
};

class Receiver {
public:
	Receiver(void);
	void listen();
	void sAbonner(int toSub);
	void update(void);
	void waitForNewMessage(void);
	void notify(void);
	static void notifyAll(void);
	size_t getID(void) { return m_ID; }
	static size_t getNbMessages(void);

	Receiver* getSuivant(void) { return suivant; }
	void setSuivant(Receiver* next) { suivant = next; }

	static void receiveMessage(std::string message, int from);
	static bool getAntennaState(void) { return antennaState; }
	static void turnOffAntenna(void);

private:
	std::vector<int> liste;
	size_t m_ID;
	stringChaine* lastMessage;

	bool notified;
	std::mutex mutexThreadPause;
	std::condition_variable cvMsgWait;
	Receiver* suivant;
	static Receiver *headOfReceivers;
	static Receiver* tailOfReceivers;

	static stringChaine* head;
	static stringChaine* tail;
	static size_t nbObjets;
	static std::mutex mutexIncomingMessage;
	static std::mutex mutexNbObjets;
	static bool antennaState;
};