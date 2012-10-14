#ifndef _MoneyAmount_hh_
#define _MoneyAmount_hh_

#include <sstream>
#include <string>

#include "Currency.h"

typedef unsigned long long Decimal;


class MoneyAmount {

public:

  MoneyAmount( Currency&, const Decimal );
  MoneyAmount( const MoneyAmount& );
  
  Decimal getAmount() const { return m_amount; }
  Currency& getCurrency() const { return *m_currency; }

  operator std::string();

  void convertCurrencyTo( Currency& );


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

  MoneyAmount();
};

#endif /* _MoneyAmount_hh_ */

