#include "StdAfx.h"
#include "Onp.h"

using namespace std;

/** Konstruktor bezparametrowy - nic nie robi.
*/
COnp::COnp(void)
{
}

/**
* Konstruktor , ustawia wyra¿enie infiksowe w klasie.
* @param wyrazenie_infix wyra¿enie w postaci infiksowej.
*/
COnp::COnp(string wyrazenie_infix)
{
	this->ustawWyrazenieInfix(wyrazenie_infix);
}

COnp::~COnp(void)
{
}

/**
* Zwraca pojemnik ³añcuchów wyra¿enia w ONP
* @return pojemnik klasy string, zawieraj¹cy elementy ONP
*/
vector <string> COnp::pobierzWyrazenieONP() const
{
	return this->wyrazenieONP;
}

/**
* Zwraca wyra¿enie w postaci infiksowej.
* @return ³añcuch wyra¿enia w postaci infiksowej
*/
string COnp::pobierzWyrazenieInfix() const
{
	return this->wyrazenieInfix;
}

/**
* Ustawia wyra¿enie ONP w klasie.
* @param wyrazenie_onp pojemnik zawieraj¹cy elementy klasy string wyra¿enia w ONP.
*/
void COnp::ustawWyrazenieONP(vector <string> wyrazenie_onp)
{
	this->wyrazenieONP = wyrazenie_onp;
}

/**
* Ustawia wyra¿enie w notacji infiksowej w klasie.
* @param wyrazenie_infix ³añcuch wyra¿enia w notcji infiksowej.
*/
void COnp::ustawWyrazenieInfix(string wyrazenie_infix)
{
	this->wyrazenieInfix = wyrazenie_infix;
}
/**
* Zwraca priorytet operatora w argumencie.
* @param oper ³añcuch zawieraj¹cy symbol operatora.
* @return liczba typu int, bêd¹ca priorytetem operatora
*/
unsigned short COnp::pobierzPriorytetOperatora(const std::string &oper) const
{
	if(oper == "log" || oper == "exp" || oper == "sin" || oper == "cos" || oper == "tan"
		|| oper == "ctg" || oper == "ln")
		return 5;
	else if(oper == "^")
		return 4;
	else if(oper == "*" || oper == "/")
		return 3;
	else if(oper == "+" || oper == "-")
		return 2;
	else if(oper == "=")
		return 1;

	return 0;
}
/**
* Sprawdza czy podany symbol jest ogranicznikiem.
* @param element symbol do sprawdzenia
* @return true, jeœli symbol jest ogranicznikiem, false - jeœli nie jest
*/
bool COnp::jestOgranicznikiem(const string &element) const
{
	if(element.empty())
		return false;

	int i = 0;

	while(ograniczniki[i] != "NULL")
	{
		if( element == ograniczniki[i] )
			return true;
		i++;
	}

	return false;
}

/**
* Sprawdza czy podany symbol jest operatorem.
* @param element symbol do sprawdzenia
* @return true, jeœli symbol jest operatorem, false - jeœli nie jest
*/
bool COnp::jestOperatorem(const string &element) const
{
	if(element.empty())
		return false;

	int i = 0;

	while(operatory[i] != "NULL")
	{
		if( element == operatory[i] )
			return true;
		i++;
	}

	return false;
}
/**
* Sprawdza czy podany znak jest operatorem.
* @param element znak do sprawdzenia
* @return true, jeœli znak jest operatorem, false - jeœli nie jest
*/
bool COnp::jestOperatorem(const char element) const
{
	string s;
	s += element;
	return this->jestOperatorem(s);
}

/**
* Sprawdza czy podany znak jest ogranicznikiem.
* @param element znak do sprawdzenia
* @return true, jeœli znak jest ogranicznikiem, false - jeœli nie jest
*/
bool COnp::jestOgranicznikiem(const char element) const
{
	string s;
	s += element;
	return this->jestOgranicznikiem(s);
}
/**
* Pobiera element z wyra¿enia od zadanej pozycji
* @param wyrazenie wyra¿enie, z którego pobraæ element
* @param pozycja pozycja, od której zacz¹æ pobieranie
* @return pobrany element
*/
string COnp::pobierzElement(const std::string &wyrazenie, int &pozycja) const
{
	string element;

	if(pozycja > wyrazenie.length())
		return "";

	while(wyrazenie.length() > pozycja)
	{
		element += wyrazenie[pozycja];
		if(
			this->jestOperatorem(wyrazenie[pozycja]) ||
			this->jestOperatorem(wyrazenie[pozycja + 1]) ||
			this->jestOgranicznikiem(wyrazenie[pozycja]) ||
			this->jestOgranicznikiem(wyrazenie[pozycja + 1])
		)
		{
			pozycja++;
			break;
		}
		else
		{
			pozycja++;
		}
	}

	return element;
}
/** Sprawdza czy podany ci¹g znaków reprezentuje liczbê rzeczywist¹
* @param liczba  badany ci¹g znaków
* @return true - jeœli ci¹g jest liczb¹ rzeczywist¹, false - je¿eli nie jest
*/
bool COnp::czyDouble(string liczba) 
{
	if(!liczba.length()) return false; // pusty ciag ;/
	
	int kropek=0; // ilosc kropek 

	if(liczba[0] == '+' || liczba[0] == '-') // jezeli na oczatku stoi znak '-' lub '+'
		liczba = liczba.substr(1,liczba.length()-1); // to pozbywamy sie go
	if(liczba == "")
		return false;
	for(unsigned int i=0; i < liczba.length(); i++) // przejdz po calym ciagu znakow
		if((liczba[i] >= '0' && liczba[i] <='9') || liczba[i] == '.') // jezeli znaki sa od 0 -9 lub kropka 
		{
			if(liczba[i] == '.') kropek++; // jezeli znak jest kropka zwieksz liczbe kropek
			else ;
		}
		else return false; // jezeli znak nie jest cyfra ani kropka zwroc false - ciag niepoprawny
	if(kropek > 1) return false; // jezeli jest wiecej niz jedna kropka ciag niepoprawny zwroc false
	return true;

}
/**
* Tworzy wyra¿enie w ONP dla wyra¿enia w postaci infiksowej.
* @param wyrazenie_infix wyra¿enie w postaci infiksowej, dla którego ma utworzyæ ONP
*/
void COnp::stworzWyrazenieOnp(const std::string &wyrazenie_infix)
{
	bool ok;
	int i = 0;
	string element;
	CStos stos;
	if(!wyrazenie_infix.empty())
		this->ustawWyrazenieInfix(wyrazenie_infix);

	if(this->pobierzWyrazenieInfix().empty())
		return ;

	this->wyrazenieONP.clear();

	// analizuje po kolei cale wyrazenie...
	for(i = 0; i < this->wyrazenieInfix.length();)
	{
		if((element = this->pobierzElement(this->pobierzWyrazenieInfix(),i)).empty())
			break;
		else
		{
			if(this->czyDouble(element)) // jesli liczba...
				this->wyrazenieONP.push_back(element);
			else
			{
				if(this->jestOperatorem(element))
				{ // jezeli stos jest pusty, albo badany operator ma wiekszy priorytet od tego na szyczycie stosu
					if(stos.jestPusty() || this->pobierzPriorytetOperatora(element) > this->pobierzPriorytetOperatora(stos.podgladnij()))
					{
						stos.poloz(element);
					}
					else
					{ // na szczycie znajduje sie operator o priorytecie wyzszyb badz rownym przetwarzanemu
						// to odczytuje wszystkie operatory ze stosu az trafie na operator, ktorego priorytet jest nizszy od przetwarzanego
						while(!stos.jestPusty() && this->pobierzPriorytetOperatora(stos.podgladnij()))
						{
							this->wyrazenieONP.push_back(stos.zdejmij());
						}
						stos.poloz(element);
					}
				}
				else if(this->jestOgranicznikiem(element))
				{
					if(element == "(") 	// jezeli jest nawiasem. otwierajacym..
					{
						stos.poloz(element);
					}
					else
					{ // nawias zamykacjacy, to sciagam wszystko az trafie na nawias otwierajacy...
						while(!stos.jestPusty() && stos.podgladnij() != "(")
						{
							this->wyrazenieONP.push_back(stos.zdejmij());
						}

						stos.zdejmij(); // usuwam nawias
					}
				}
			}
		}
	}
	if(!stos.jestPusty()) // na koncu jezeli mialem jakies operatory do dopisuje je do wyjscia...
	{
		while(!stos.jestPusty())
		{
			if(stos.podgladnij() != "(" && stos.podgladnij() != ")")
			{
				this->wyrazenieONP.push_back(stos.zdejmij());
			}
			else
			{
				stos.zdejmij();
			}
			if(stos.jestPusty())
				break;
		}
	}
}
/**
* Oblicza wartoœæ dzia³ania operatora dla podanych argumentów.
* @param l1 parametr pierwszy
* @param l2 parametr drugi
* @param oper operator
* @return liczba rzeczywista - wynik dzia³ania operatora dla podanych argumentów
*/
double COnp::obliczOperator(const double &l1, const double &l2, const std::string &oper) const
{
	if(oper == "+")
		return l1+l2;
	else if(oper == "-")
		return l2-l1;
	else if(oper == "*")
		return l1*l2;
	else if(oper == "/")
		return l2 / l1;
	else if(oper == "sin")
		return sin(l1);
	else if(oper == "cos")
		return cos(l1);
	else if(oper == "tan")
		return tan(l1);
	else if(oper == "exp")
		return exp(l1);
	else if(oper == "ctg")
		return (1/tan(l1));
	else if(oper == "^")
		return pow(l2,l1);
	else if(oper == "log")
		return log10(l1);
	else if(oper == "ln")
		return log(l1);
	else if(oper == "sqrt")
		return sqrt(l1);

	return 0.0f;
}
/** Oblicza wartoœæ podanego wyra¿enia infiksowego.
* @param wyrazenie wyra¿enie w notacji infiksowej.
* @return wartoœæ wyra¿enia
*/
double COnp::obliczWyrazenie(const std::string &wyrazenie)
{
	int i = 0;
	double a1,a2;
	CStos stos;
	ostringstream strumien;

	this->stworzWyrazenieOnp(wyrazenie); // tworzymy ONP z infix

	for(i = 0; i < this->wyrazenieONP.size(); i++) // przechodzimy po wszystkich elementach wyrazenia ONP
	{
		if(this->jestOperatorem(this->wyrazenieONP[i])) // jezeli operator
		{
			if(!stos.jestPusty()) // i stos nie jest pusty
			{
				a1 = atof(stos.zdejmij().c_str()); // zdejmujemy element

				if( // jezeli jest on jedna z ponizszych funkcji
					this->wyrazenieONP[i] == "log" ||
					this->wyrazenieONP[i] == "ln" ||
					this->wyrazenieONP[i] == "sin" ||
					this->wyrazenieONP[i] == "cos" ||
					this->wyrazenieONP[i] == "tan" ||
					this->wyrazenieONP[i] == "ctg" ||
					this->wyrazenieONP[i] == "sqrt"
					)
				{
					a2 = 0.0f; // to drugi argument = 0
				}
				else // a jesli nie jest jedna z powyzszych funkcji
				{
					if(!stos.jestPusty()) // to drugi parametr
					{
						a2 = atof(stos.zdejmij().c_str()); // sciagamy ze stosu
					}
				} // konwersja double to string za pomoca sstream
				strumien << this->obliczOperator(a1,a2,this->wyrazenieONP[i]); // liczymy wynik operatora i dwoch parametrow
				stos.poloz(strumien.str()); // kladziemy na stos obliczony wynik
				strumien.str(""); // czyscimy strumien do nastepnej iteracji
			}
		}
		else // jezeli element nie jest operatorem
		{
			if(this->czyDouble(this->wyrazenieONP[i])) // to sprawdzamy czy jest poprawna liczba double
				stos.poloz(this->wyrazenieONP[i]); // jak jest kladziemy go na stos
			else
			{
				throw(string("Bledne wyrazenie")); // a jezeli nie rzucamy wyjatek
			}
		}
	}
	return atof(stos.zdejmij().c_str()); // zwracamy wynik jako ostatni skladnik na stosie
}

			









