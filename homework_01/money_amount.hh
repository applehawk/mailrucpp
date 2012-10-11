#ifndef _MoneyAmount_hh_
#define _MoneyAmount_hh_

class MoneyAmount {

  public:
    Currency currency;
    Decimal amount;

	friend const MoneyAmount & operator + (const MoneyAmount &);

	friend const MoneyAmount & operator - (const MoneyAmount &);

	friend const MoneyAmount operator + (const MoneyAmount &, const MoneyAmount &);

	friend const MoneyAmount operator - (const MoneyAmount &, const MoneyAmount &);

	friend MoneyAmount & operator += (const MoneyAmount &, const MoneyAmount &);

	friend MoneyAmount & operator -= (const MoneyAmount &, const MoneyAmount &);

	friend bool operator == (const MoneyAmount &, const MoneyAmount &);

};

#endif /* _MoneyAmount_hh_ */

