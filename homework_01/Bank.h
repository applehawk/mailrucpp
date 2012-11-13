/* 
   
 */

#ifndef _Bank_hh_
#define _Bank_hh_

#include <map>
#include <string>

class Account;

#include "AccountsOwner.h"

#include "Client.h"
#include "Currency.h"
#include "Account.h"



class Bank: public AccountsOwner {
public:
	Bank();

	int createClient( const std::string&, const std::string&, const std::string& );
	Client* getClientById( const int ) const;
	Currency* getCurrencyByName( const std::string& ) const;
	int generateAccountId() const;

	void addCurrency( Currency* );



 protected:
    std::map <int, Client*> m_clients;
    std::map <int, Account*> m_accounts;
    std::map<std::string, Currency*> m_currencies;
    //static std::map <Employee*> m_employees; //TODO



};

#endif /* _Bank_hh_ */

