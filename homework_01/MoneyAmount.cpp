#include "MoneyAmount.h"


MoneyAmount::MoneyAmount( const Currency &_currency, const Decimal _amount ) {
	currency = _currency;
	amount = _amout;
}



Decimal MoneyAmount::getAmount() {
	return amount;
}


const Currency& MoneyAmount::getAmount() {
	return currency;
}


const std::string MoneyAmount::operator string() {
	return std::string( amount ) + " " + currency.getName();
}


friend const MoneyAmount operator+(const MoneyAmount &first_ma, const MoneyAmount &second_ma ) {
	if ( first_ma.getCurrency() == second_ma.getCurrency() ) {
		return MoneyAmount( first_ma.getAmount() + second_ma.getAmount(), first_ma.getCurrency() );
	} else {
		//Exeption or conver of currency;
		return MoneyAmount();
	}
}


friend const MoneyAmount operator-(const MoneyAmount &first_ma, const MoneyAmount &second_ma ) {
	if ( first_ma.getCurrency() == second_ma.getCurrency() ) {
		return MoneyAmount( first_ma.getAmount() - second_ma.getAmount(), first_ma.getCurrency() );
	} else {
		//Exeption or conver of currency;
		return MoneyAmount();
	}
}