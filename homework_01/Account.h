/* 
   
 */

#ifndef _Account_hh_
#define _Account_hh_

class Account {

  protected:
    MoneyAmount money_amount;
    Vector <Transaction*> transactions;
    std::time_t created;


  public:
    MoneyAmount get_saldo(long time_delta, time_t final_time);
    MoneyAmount get_saldo(long time_delta);
    void get_money(MoneyAmount money_amount);
    void put_money(MoneyAmount money_amount);


};

#endif /* _Account_hh_ */

