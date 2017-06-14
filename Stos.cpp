#include "StdAfx.h"
#include "Stos.h"

/** 
* Konstruktor bezparametrowy.
* Rezerwuje wstępnie pamięć na 20 elementów, aby przyspieszyć działanie programu.
*/
CStos::CStos(void)
{
	stos.reserve(20);
}

/**
* Destruktor zwalniający pamięć po klasie
*/
CStos::~CStos(void)
{
	stos.clear();
}

/**
* Zwraca ilość elementów na stosie.
* @return ilość elementów (int)
*/
int CStos::pobierzLiczbeElementow()
{
	return stos.size();
}
/**
* Sprawdza, czy stos jest pusty.
* @return true, jeżeli stos jest pusty oraz zwraca false, gdy zawiera elementy.
*/
bool CStos::jestPusty()
{
	if(!stos.size())
		return true;
	else return false;
}
/**
* Kładzie element na stosie.
* @param element Łańcuch tekstowy string.
*/
void CStos::poloz(string element)
{
	stos.push_back(element);
}
/**
* Zdejmuje element z góry stosu.
* @param obiekt klasy string, do którego zostanie przypisana wartość elementu ze stosu.
* @return true, jeżeli udało się zdjąć element, false - jezeli stos był pusty.
*/
string CStos::zdejmij()
{
	if(this->jestPusty())
		return "";

	string s;
	s = stos[stos.size()-1];
	stos.pop_back();
	return s;

}
/**
* Podgląda element z góry stosu, bez ściągania go.
* @param obiekt klasy string, do którego zostanie przypisana wartość elementu ze stosu.
* @return @return true, jeżeli był element na stosie, false - jezeli stos był pusty.
*/
string CStos::podgladnij()
{
	if(this->jestPusty())
		return "";
	return stos[stos.size()-1];
}



