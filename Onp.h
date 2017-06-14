#pragma once
#include <string>
#include <vector> 
#include <math.h>
#include "Stos.h"
#include <stdlib.h>
#include <sstream>

using namespace std;

static const string ograniczniki[] = { "(" , ")", "NULL" };
static const string operatory[] = { "exp" , "sin", "cos" , "tan" , "ctg" , "log",
									"ln" , "sqrt" , "+" , "-", "*" , "/" , "^", "NULL" };


/** 
* @author
* @version 1.0
* Zawiera pola i metody do przekszta³cania wyra¿enia do postaci ONP oraz do
* oszacowania wyniku wyra¿enia. Korzysta z klasy CStos.
*/

class COnp
{
public:
	COnp(void);
	COnp(string wyrazenie_infix);
	~COnp(void);

	vector <string> pobierzWyrazenieONP() const;
	string pobierzWyrazenieInfix() const;
	void ustawWyrazenieONP(vector <string> wyrazenie_onp);
	void ustawWyrazenieInfix(string wyrazenie_infix);
	void stworzWyrazenieOnp(const string &wyrazenie_infix = "");
	double obliczWyrazenie(const string &wyrazenie = "");
	
private:

	unsigned short pobierzPriorytetOperatora(const string &oper) const;
	bool jestOgranicznikiem(const string &element) const;
	bool jestOperatorem(const string &element) const;
	bool jestOgranicznikiem(const char element) const;
	bool jestOperatorem(const char element) const;
	string pobierzElement(const string &wyrazenie, int &pozycja) const;
	double obliczOperator(const double &l1, const double &l2,const string &oper) const;
	bool czyDouble(string liczba);

	vector <string> wyrazenieONP;///< pojemnik ³añcuchów tworz¹cych wyra¿enie w ONP
	string wyrazenieInfix;///< ³añcuch wyra¿enia w postaci infiksowej

};
