#ifndef _MoneyAmount_hh_
#define _MoneyAmount_hh_

#include <string>
#include "Currency.h"

typedef unsigned long long Decimal;

class MoneyAmount {

public:
  Currency currency;
  Decimal amount;

   MoneyAmount( const Currency&, const Decimal );
  
  Decimal getAmount();
  
  const Currency& getAmount();

  const MoneyAmount& operator+();

  const MoneyAmount operator-();

  const std::string operator string();

  friend const MoneyAmount operator+(const MoneyAmount&, const MoneyAmount&);

  friend const MoneyAmount operator-(const MoneyAmount&, const MoneyAmount&);

  friend const MoneyAmount operator*(const MoneyAmount&, double);

  friend const MoneyAmount operator*(double, const MoneyAmount&);

  friend const MoneyAmount operator/(const MoneyAmount&, double);

  friend MoneyAmount& operator+=(const MoneyAmount&, const MoneyAmount&);

  friend MoneyAmount& operator-=(const MoneyAmount&, const MoneyAmount&);

  friend const bool operator==(const MoneyAmount&, const MoneyAmount&);

};

#endif /* _MoneyAmount_hh_ */

