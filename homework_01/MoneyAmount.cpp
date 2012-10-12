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


MoneyAmount& operator+=( const MoneyAmount& money_amount ) {
	amount += money_amount.getAmount();
	currency += money_amount.getCurrency();

	return *this;
}


MoneyAmount& operator-=( const MoneyAmount& money_amount ) {
	amount -= money_amount.getAmount();
	currency -= money_amount.getCurrency();

	return *this;
}


MoneyAmount& operator=( const MoneyAmount& money_amount ) {
    //проверка на самоприсваивание
    if ( this == &money_amount ) {
        return *this;
    }

    amount = money_amount.getAmount();
    currency = money_amount.getCurrency();

    return *this;
}



//Global binary operation for class============================================

const bool operator==( const MoneyAmount &first_ma, const MoneyAmount &second_ma ) {
	return ( ( first_ma.getCurrency() == second_ma.getCurrency() ) &&
			 ( firs_ma.getAmount() == second_ma.getAmount() ) );
}


const MoneyAmount operator+( const MoneyAmount &first_ma, const MoneyAmount &second_ma ) {
	if ( first_ma.getCurrency() == second_ma.getCurrency() ) {
		return MoneyAmount( first_ma.getAmount() + second_ma.getAmount(), first_ma.getCurrency() );
	} else {
		//Exeption or conver of currency;
		return MoneyAmount();
	}
}


const MoneyAmount operator-(const MoneyAmount &first_ma, const MoneyAmount &second_ma ) {
	if ( first_ma.getCurrency() == second_ma.getCurrency() ) {
		return MoneyAmount( first_ma.getAmount() - second_ma.getAmount(), first_ma.getCurrency() );
	} else {
		//Exeption or conver of currency;
		return MoneyAmount();
	}
}


const MoneyAmount operator*(const MoneyAmount& money_amount, double factor ) {
	return MoneyAmount( factor * money_amount.getAmount(), money_amount.getCurrency() );
}


const MoneyAmount operator*( double factor, const MoneyAmount& money_amount ) {
	return money_amount * factor;
}


const MoneyAmount operator/(const MoneyAmount& money_amount, double divider ) {
	return MoneyAmount( money_amount.getAmount() / divider, money_amount.getCurrency() );
}