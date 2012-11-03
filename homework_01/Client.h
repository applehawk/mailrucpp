

#ifndef _Client_hh_
#define _Client_hh_

#include <string>
#include <vector>

class Account;
class Bank;

#include "Bank.h"
#include "Person.h"
#include "Account.h"
#include "Currency.h"
#include "MoneyAmount.h"

class Client: public Person {
public:
	Client( const std::string&, const std::string&, const std::string&, Bank* );
	int getMainAccountId() const;
	Account* getMainAccount() const;
	int createAccount();
	int createAccount( Currency* );
	int createAccount( const MoneyAmount& );


protected:
    //bool m_operable;

private:
    Bank *m_bank;
    std::vector<int> m_accounts_id;



};

#endif /* _Client_hh_ */

