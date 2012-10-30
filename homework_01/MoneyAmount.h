#ifndef _MoneyAmount_hh_
#define _MoneyAmount_hh_

#include <sstream>
#include <string>

#include "Currency.h"
#include "DefaultCurrency.h"

typedef unsigned long long Decimal;


class MoneyAmount {



public:
  static Currency default_currency; //TODO

  MoneyAmount();
  MoneyAmount( Currency*, const Decimal );
  MoneyAmount( const MoneyAmount& );
  
  Currency* getCurrency() const { return m_currency; }
  Decimal getAmount() const { return m_amount; }

  Decimal getAmountInCurrency( Currency* ) const;

  operator std::string();

 void convertCurrencyTo( Currency* );


  MoneyAmount& operator+=( const MoneyAmount& );
  MoneyAmount& operator-=( const MoneyAmount& );
  MoneyAmount& operator=( const MoneyAmount& );

  friend const MoneyAmount operator+(const MoneyAmount&, const MoneyAmount&);
  friend const MoneyAmount operator-(const MoneyAmount&, const MoneyAmount&);
  friend const MoneyAmount operator*(const MoneyAmount&, double);
  friend const MoneyAmount operator*(double, const MoneyAmount&);
  friend const MoneyAmount operator/(const MoneyAmount&, double);
  friend const bool operator==(const MoneyAmount&, const MoneyAmount&);


private:
  Currency *m_currency;
  Decimal m_amount;


};


#endif /* _MoneyAmount_hh_ */

