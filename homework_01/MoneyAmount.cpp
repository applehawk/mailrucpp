#include "MoneyAmount.h"

#include <sstream>

MoneyAmount::MoneyAmount( Currency& _currency, const Decimal _amount ) : currency(_currency) {
	amount = _amount;
}


MoneyAmount::operator std::string() {
  std::stringstream res;
  res<< amount << " " << currency.getName();
	return res.str();
}


MoneyAmount& MoneyAmount::operator+=( const MoneyAmount& money_amount ) {
	*this = *this + money_amount;
  //amount += money_amount.getAmount();
	//currency += money_amount.getCurrency();

	return *this;
}


MoneyAmount& MoneyAmount::operator-=( const MoneyAmount& money_amount ) {
//	amount -= money_amount.getAmount();
//	currency -= money_amount.getCurrency();
  *this = *this - money_amount;
	return *this;
}


MoneyAmount& MoneyAmount::operator=( const MoneyAmount& money_amount ) {
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
			 ( first_ma.getAmount() == second_ma.getAmount() ) );
}


const MoneyAmount operator+( const MoneyAmount &first_ma, const MoneyAmount &second_ma ) {
	if ( first_ma.getCurrency() == second_ma.getCurrency() ) {
		return MoneyAmount( first_ma.getCurrency(), first_ma.getAmount() + second_ma.getAmount() );
	} else {
		//Exeption or conver of currency;
    throw CurrExcp("operator +");
  }
}


const MoneyAmount operator-(const MoneyAmount &first_ma, const MoneyAmount &second_ma ) {
	if ( first_ma.getCurrency() == second_ma.getCurrency() ) {
	return MoneyAmount( first_ma.getCurrency(), first_ma.getAmount() - second_ma.getAmount() );
  } else {
		//Exeption or conver of currency;
    throw CurrExcp("operator -");
  }
}


const MoneyAmount operator*(const MoneyAmount& money_amount, double factor ) {
	return MoneyAmount( money_amount.getCurrency(), factor * money_amount.getAmount()  );
}


const MoneyAmount operator*( double factor, const MoneyAmount& money_amount ) {
	return money_amount * factor;
}


const MoneyAmount operator/(const MoneyAmount& money_amount, double divider ) {
	return MoneyAmount(  money_amount.getCurrency(), money_amount.getAmount() / divider );
}
