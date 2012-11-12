#include "MoneyAmount.h"
#include "Currency.h"


int test_Add2MoneyAmounts_EqualCurrency()
{
  try {
    Currency usd( "USD", "$", 1.0 );
    MoneyAmount money_amount1( &usd, 100.0 );
    MoneyAmount money_amount2( &usd, 35.0 );
    
    MoneyAmount result = money_amount1 + money_amount2;
    
    std::cout << "test_Add2MoneyAmounts_EqualAmounts: 100 $ + 35 $ = " << std::string(result)
    << "\t" << ( ( result == MoneyAmount( &usd, 135.0 ) ) ? "OK" : "ERROR" ) << std::endl;
  } catch(...) {
    std::cout << "Exception: test_Add2MoneyAmounts_EqualAmounts ";
  }
  return 0;
};



int test_Add2MoneyAmounts_NotEqualCurrency()
{

  try {
    Currency usd( "USD", "$", 1.0 );
    Currency eur( "EUR", " €", 3.0 );
    MoneyAmount money_amount1( &usd, 100.0 );
    MoneyAmount money_amount2( &eur, 35.0 );

    MoneyAmount result = money_amount1 + money_amount2;

    std::cout << "test_Add2MoneyAmounts_NotEqualCurrency: " << std::string(result)
    << "\t ERROR" << std::endl;
  } catch (CurrExcp& excp) {
    std::cout << "Exception: test_Add2MoneyAmounts_NotEqualCurrency " << excp.errstr
    <<"\t OK" << std::endl;
  }
  return 0;
};


int test_MultMoneyAmounts(){
  try {
    Currency usd( "USD", "$", 1.0 );
    MoneyAmount money_amount( &usd, 100.0 );

    MoneyAmount result = 0.5 * money_amount;

    std::cout << "test_MultMoneyAmout: 0.5 * 100 $ = " << std::string(result)
    << "\t" << ( ( result == MoneyAmount( &usd, 50.0 ) ) ? "OK" : "ERROR" ) << std::endl;
  } catch(CurrExcp& excp) {
    std::cout << "Exception: test_MultMoneyAmounts " << excp.errstr << std::endl;
  }
   return 0;
}


int test_ConvertCurrency(){
  try {
    Currency usd( "USD", "$", 1.0 );
    Currency eur( "EUR", " €", 1.4 );

    MoneyAmount money_amount( &usd, 100.0 );
    money_amount.convertCurrencyTo( &eur );


    std::cout << "test_ConvertCurrency: 100 $ = " << std::string(money_amount)
    << "\t" << ( ( money_amount == MoneyAmount( &eur, 140.0 ) ) ? "OK" : "ERROR" ) << std::endl;
  } catch(...) {
    std::cout << "Exception: test_ConvertCurrency " << std::endl;
  }
   return 0;
}


int test_AddSubWithAssign_NotEqualCurrency(){
  try {
    Currency usd( "USD", "$", 1.0 );
    Currency eur( "EUR", "€", 1.4 );

    MoneyAmount money_amount_usd( &usd, 100.0 );
    MoneyAmount money_amount_eur1( &eur, 30.0 );
    MoneyAmount money_amount_eur2( &eur, 30.0 );

    money_amount_usd += money_amount_eur1;
    money_amount_usd -= money_amount_eur2;

    std::cout << "test_AddSubWithAssign_NotEqualCurrency: A = 100 $; A += 30  €; A -= 30  €; A = " << std::string(money_amount_usd)
    << "\t" << ( ( money_amount_usd == MoneyAmount( &usd, 100.0 ) ) ? "OK" : "ERROR" ) << std::endl;
  } catch(...) {
    std::cout << "Exception: test_AddSubWithAssign_NotEqualCurrency " << std::endl;
  }
   return 0;
}

int test_MoneyAmount(){
	std::cout<<"MoneyAmount tests began:" << std::endl;
	test_Add2MoneyAmounts_EqualCurrency();
	test_Add2MoneyAmounts_NotEqualCurrency();
	test_MultMoneyAmounts();
	test_ConvertCurrency();
	test_AddSubWithAssign_NotEqualCurrency();
	std::cout<<"MoneyAmount tests finished" << std::endl << std::endl << std::endl;
	return 0;
}
