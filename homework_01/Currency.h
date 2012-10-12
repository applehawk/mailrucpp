#ifndef H_CURRENCY
#define H_CURRENCY

#include <string>

class Currency{
public:
	Currency( std::string _name, double _value );
	std::string getName();
	double getValue();

private:
	std::string name;
	double value;
	Currency(); //Запрещаем конструктор по умолчанию
};


#endif