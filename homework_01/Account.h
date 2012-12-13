/* 
   
 */

#ifndef _Account_hh_
#define _Account_hh_

#include <vector>
#include <ctime>

class Transaction;
class Client;

#include "Bank.h"
#include "MoneyAmount.h"
#include "Transaction.h"
#include "Currency.h"
#include "Client.h"


class Account {
	friend class Transaction;

public:
	Account( int, Client* );
	Account( const MoneyAmount&, int, Client* );
	Account( Currency*, int, Client* );
	int getId() const;
	MoneyAmount getSaldo( long, time_t ) const;
	MoneyAmount getSaldo( long ) const;

    MoneyAmount getMoneyAmount() const;
    void setMoneyAmount( const MoneyAmount& );

    void initTransactionTo( Account*, const MoneyAmount& );
    void initTransactionToById( int, const MoneyAmount&  );
    void initTransactionTo( Account*, const MoneyAmount&, time_t time );
    void initTransactionToById( int, const MoneyAmount&, time_t time );

    ~Account();


protected:
    MoneyAmount m_money_amount;
    std::vector <Transaction*> m_transactions;
    Bank *m_bank;
    time_t m_created;
    int m_id;
    Client* m_owner;

private:
    Account();
};

#endif /* _Account_hh_ */

