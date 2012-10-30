/* 
   
 */

#ifndef _Account_hh_
#define _Account_hh_

#include <vector>
#include <time.h>

class Transaction;

#include "MoneyAmount.h"
#include "Transaction.h"


class Account {
	friend class Transaction;

public:
	Account(){};
	Account( const MoneyAmount& );
	MoneyAmount getSaldo( long, time_t ) const;
	MoneyAmount getSaldo( long ) const;

    MoneyAmount getMoneyAmount() const;
    void setMoneyAmount( const MoneyAmount& );

    void initTransactionTo( Account*, MoneyAmount& );


protected:
    MoneyAmount m_money_amount;
    std::vector <Transaction*> m_transactions;
    //std::time_t m_created; //TODO

};

#endif /* _Account_hh_ */

