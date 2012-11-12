#include "Account.h"
#include "MoneyAmount.h"
#include "Currency.h"

#include <string>

int test_Transaction(){
  try {
    std::cout<<"Transaction tests began:" << std::endl;
    Currency usd( "USD", "$", 1.0 );
    MoneyAmount money_amount_begin( &usd, 100.0 );
    MoneyAmount money_amount_send( &usd, 50.0 );

    Account account_src;
    Account account_dst;
    account_src.setMoneyAmount( money_amount_begin );

    std::cout << "test_Transaction: " << std::endl;
    std::cout << "ACC_SRC = " << std::string( account_src.getMoneyAmount() )
    << " ACC_DST = "  << std::string( account_dst.getMoneyAmount() ) << std::endl;

    Account account_dst_backup = account_dst;
    Account account_src_backup = account_src;

    account_src.initTransactionTo( &account_dst, money_amount_send );

    std::cout << "Transaction (" << std::string( money_amount_send )
    << "): ACC_SRC -> ACC_DST " << std::endl;

    std::cout << "ACC_SRC = " << std::string( account_src.getMoneyAmount() )
        << " ACC_DST = "  << std::string( account_dst.getMoneyAmount() ) << "\t";

    std::cout <<
    ( ( ( account_dst.getMoneyAmount() == ( account_dst_backup.getMoneyAmount() + money_amount_send ) )  &&
    	( account_src.getMoneyAmount() == ( account_src_backup.getMoneyAmount() - money_amount_send ) )) ? "OK" : "FAIL" );

  } catch(...) {
    std::cout << "Exception: test_Transaction";
  }
  std::cout<< std::endl << "Transaction tests finished" << std::endl << std::endl << std::endl;
  return 0;
};
