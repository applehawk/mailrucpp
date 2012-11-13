#ifndef _AccountsOwner_hh_
#define _AccountsOwner_hh_

//#include "Account.h"

class Account;

#include <map>

class AccountsOwner {

  protected:
    std::map <int, Account*> m_accounts;
    int max_id;


  public:
    void addAccount( int, Account* );
    Account* getAccountById( int ) const;
    Account* getMainAccount() const;
    bool hasAccountById( int ) const;
    void removeAccountById( int );
    int getMaxId() const;
    int size() const;


};

#endif /* _AccountsOwner_hh_ */

