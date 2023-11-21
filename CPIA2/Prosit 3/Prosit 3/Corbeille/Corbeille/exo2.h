#pragma once

class Instrument {
public:
	virtual void playInstrument(void) = 0;
};

class Piano : public Instrument {
public:
	void playInstrument(void);
};

class Saxo : public Instrument {
public:
	void playInstrument(void);
};