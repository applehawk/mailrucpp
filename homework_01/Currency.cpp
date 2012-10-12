#include "Currency.h"


Currency::Currency( std::string _name, double _value ) {
	name = _name;
	value = _value;
}


std::string Currency::getName() {
	return name;
}


double Currency::getValue() {
	return value;
}