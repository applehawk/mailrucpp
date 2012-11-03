#ifndef _AccountsOwner_hh_
#define _AccountsOwner_hh_

#include <vector>

class AccountsOwner {

  protected:
    std::vector <Account*> accounts;


  public:
    void get_money(Account* account, MoneyAmount money_amount);
    void put_money(Account account, MoneyAmount money_amount);
    void show_accounts();


};

#endif /* _AccountsOwner_hh_ */

