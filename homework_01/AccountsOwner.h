#ifndef _AccountsOwner_hh_
#define _AccountsOwner_hh_

#include "AccountsOwner.h"
#include "MoneyAmount.h"
#include "Account.h"
#include "Bank.h"

class AccountsOwner {

  protected:
    std::vector <Account*> m_accounts;


  public:
    void getMoney(Account account, MoneyAmount money_amount);
    void putMoney(Account account, MoneyAmount money_amount);
    void addAccount(Account&);
    void deleteAccout(const Currency);
    void showAccounts();


};

#endif /* _AccountsOwner_hh_ */

