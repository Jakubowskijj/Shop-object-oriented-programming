#pragma once
class alkohole
{
public:
	int ilosc = 0;
};

class piwo :public alkohole {
public:
	float cena;
	piwo(float = 3);
};

class whisky :public alkohole {
public:
	float cena;
	whisky(float = 60);
};

class wodka :public alkohole {
public:
	float cena;
	wodka(float = 20);
};