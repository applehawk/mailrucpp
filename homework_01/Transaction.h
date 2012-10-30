/* 
   
 */

#ifndef _Transaction_hh_
#define _Transaction_hh_

class Transaction {

  protected:
    Account* source_account;
    Account* destination_account;
    MoneyAmount amount;
    time_t time;



};

#endif /* _Transaction_hh_ */

