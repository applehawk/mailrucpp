/* 
   
 */

#ifndef _AccountsOwner_hh_
#define _AccountsOwner_hh_

class AccountsOwner {

  protected:
    Vector <Account*> accounts;


  public:
    void get_money(Account* account, MoneyAmount money_amount);

    /*
     * 			
     * @account
     * @money_amount
     */

    void put_money(Account account, MoneyAmount money_amount);
    void show_accounts();


};

#endif /* _AccountsOwner_hh_ */

