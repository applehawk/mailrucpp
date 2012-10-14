#ifndef _MoneyAmount_hh_
#define _MoneyAmount_hh_

#include <string>
#include <sstream>
#include "Currency.h"

typedef unsigned long long Decimal;

class MoneyAmount {

public:

  MoneyAmount( Currency&, const Decimal );
  
  Decimal getAmount() const { return amount; }
  Currency& getCurrency() const { return currency; }

  operator std::string();


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
  Currency& currency;
  Decimal amount;

  MoneyAmount();
};

#endif /* _MoneyAmount_hh_ */

