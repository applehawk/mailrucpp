#include "MoneyAmount.h"


MoneyAmount::MoneyAmount( Currency *currency, const Decimal amount ) {
	m_amount = amount;
	m_currency = currency;
}


 MoneyAmount::MoneyAmount( const MoneyAmount& src ) {
 	m_amount = src.m_amount;
	m_currency = src.m_currency;
 }


MoneyAmount::operator std::string() {
  std::stringstream res;
  res<< m_amount << m_currency->getSign();
	return res.str();
}


 void MoneyAmount::convertCurrencyTo( Currency *new_currency ) {
 	//*1000000 Временный костыль для точности перевода типа Decimal(long long )
 	m_amount *= new_currency->getValue() * 1000000 / m_currency->getValue() / 1000000;
 	m_currency = new_currency;

 }



MoneyAmount& MoneyAmount::operator+=( const MoneyAmount& money_amount ) {
	//*this = *this + money_amount;  не оптимальная конструкция (вызывается конструктор MoneyAmount)
	//*1000000 - Временный костыль для точности перевода типа Decimal(long long )
	//Decimal пока не поддерживает дробные значения, из за чего происходит ошибка в тесте

	if( *m_currency == *( money_amount.m_currency ) ) {
		m_amount += money_amount.getAmount();
	} else {
    	m_amount += ( money_amount.m_amount * 1000000 * m_currency->getValue() / money_amount.m_currency->getValue() / 1000000 ) ;
	}

	return *this;
}


MoneyAmount& MoneyAmount::operator-=( const MoneyAmount& money_amount ) {
  	//*this = *this - money_amount;	не оптимальная конструкция (вызывается конструктор MoneyAmount)
	//*1000000 -  Временный костыль для точности перевода типа Decimal(long long )
	//Decimal пока не поддерживает дробные значения, из за чего происходит ошибка в тесте

	if( *m_currency == *( money_amount.m_currency ) ) {
		m_amount -= money_amount.m_amount;
	} else {
    	m_amount -= ( money_amount.m_amount * 1000000 * m_currency->getValue() / money_amount.m_currency->getValue() / 1000000 ) ;
	}

	return *this;
}


MoneyAmount& MoneyAmount::operator=( const MoneyAmount& money_amount ) {
    //проверка на самоприсваивание
    if ( this == &money_amount ) {
        return *this;
    }

    m_amount = money_amount.m_amount;
    m_currency = money_amount.m_currency;

    return *this;
}



//Global binary operation for class============================================

const bool operator==( const MoneyAmount &first_ma, const MoneyAmount &second_ma ) {
	return ( ( *(first_ma.getCurrency()) == *(second_ma.getCurrency()) ) &&
			 ( first_ma.getAmount() == second_ma.getAmount() ) );
}


const MoneyAmount operator+( const MoneyAmount &first_ma, const MoneyAmount &second_ma ) {
	if ( *(first_ma.getCurrency()) == *(second_ma.getCurrency()) ) {
		return MoneyAmount( first_ma.getCurrency(), first_ma.getAmount() + second_ma.getAmount() );
	} else {
		//Exeption or conver of currency;
    	throw CurrExcp("operator +");
  }
}


const MoneyAmount operator-(const MoneyAmount &first_ma, const MoneyAmount &second_ma ) {
	if ( *(first_ma.getCurrency()) == *(second_ma.getCurrency()) ) {
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
