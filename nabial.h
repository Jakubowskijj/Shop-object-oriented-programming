#pragma once
class nabial
{
public:
	int ilosc = 0;
};

class jajka :public nabial {
public:
	float cena = 6.50;
	friend void przyjaciel(jajka j);
};


class jogurt :public nabial {
public:
	float cena = 1.90;
};

class mleko :public nabial {
public:
	float cena = 3;
};