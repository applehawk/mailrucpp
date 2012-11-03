/* 
   
 */

#ifndef _Account_hh_
#define _Account_hh_

#include <vector>
#include <ctime>

class Transaction;

#include "Bank.h"
#include "MoneyAmount.h"
#include "Transaction.h"
#include "Currency.h"


class Account {
	friend class Transaction;

public:
	Account();
	Account( Bank* );
	Account( const MoneyAmount&, Bank* );
	Account( Currency*, Bank* );
	MoneyAmount getSaldo( long, time_t ) const;
	MoneyAmount getSaldo( long ) const;

    MoneyAmount getMoneyAmount() const;
    void setMoneyAmount( const MoneyAmount& );

    void initTransactionTo( Account*, const MoneyAmount& );
    void initTransactionToById( int, const MoneyAmount&  );


protected:
    MoneyAmount m_money_amount;
    std::vector <Transaction*> m_transactions;
    Bank *m_bank;
    time_t m_created;

};

#endif /* _Account_hh_ */

