#pragma once

class Receiver {
public:
	Receiver(void);
	bool messageAvailable(void);
	void listen();
	void sAbonner(int toSub);
	void update(void);
	size_t getID(void) { return m_ID; }

	static void receiveMessage(std::string message, int from);
	static bool getAntennaState(void) { return antennaState; }
	static void turnOffAntenna(void);

private:
	std::vector<int> liste;
	size_t m_ID;
	size_t lastMessage;
	static std::vector<std::string> messageContent;
	static std::vector<int> messageFrom;
	static size_t messageID;
	static size_t nbObjets;
	static std::mutex mutexIncomingMessage;
	static std::mutex mutexNbObjets;
	static bool antennaState;
};