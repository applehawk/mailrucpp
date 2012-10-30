
#ifndef _Transaction_hh_
#define _Transaction_hh_

class Account;

#include "Account.h"
#include "MoneyAmount.h"


class Transaction {

	friend class Account;

  public:
	Transaction( Account *src, Account *dst, const MoneyAmount &money_amount );

	void commit();

  protected:
	bool is_commited;
    Account* m_source_account;
    Account* m_destination_account;
    MoneyAmount m_money_amount;
   // time_t time; //TODO

};

#endif /* _Transaction_hh_ */

