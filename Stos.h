#pragma once
#include <vector>
#include <string>
using namespace std;
 
/** Klasa zawierająca metody i pola obsługi stosu łańcuchów tekstowych. 
*
*/


class CStos
{
public:
	CStos(void);
	~CStos(void);

	int pobierzLiczbeElementow();
	void poloz(string element);
	string zdejmij();
	bool jestPusty();
	string podgladnij();

private:
	std::vector <std::string> stos; ///< pojemnik elementów klasy string
};
