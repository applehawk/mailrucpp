
#ifndef _Transaction_hh_
#define _Transaction_hh_

class Account;

#include "Account.h"
#include "Error.h"
#include "MoneyAmount.h"


class ErrorTransactionNotCommited: public Error {};


class Transaction {

	friend class Account;

  public:
	Transaction( Account *src, Account *dst, const MoneyAmount &money_amount );

	void commit();
	time_t getCommitTime() const throw( ErrorTransactionNotCommited );
	bool isCommited() const throw();

  protected:
    Account* m_source_account;
    Account* m_destination_account;
    MoneyAmount m_money_amount;

    time_t m_commited;
    const static time_t not_commited_time = 0;


};

#endif /* _Transaction_hh_ */

