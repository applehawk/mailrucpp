#include <string>
#include <iostream>

using namespace std;

//typedef long int Date;

#include "MoneyAmount.h"
#include "Currency.h"


int test_Add2MoneyAmounts_EqualAmounts()
{
  try {
    Currency usd( "USD", "$", 1.0 );
    MoneyAmount money_amount1( usd, 100.0 );
    MoneyAmount money_amount2( usd, 35.0 );
    
    MoneyAmount result = money_amount1 + money_amount2;
    
    std::cout << "Add2MoneyAmounts_EqualAmounts: " << std::string(result) << std::endl;
  } catch(...) {
    std::cout << "Exception: test_Add2MoneyAmounts_EqualAmounts";
  }
  return 0;
};

int test_Add2MoneyAmounts_NotEqualAmounts()
{
  try {
    Currency usd( "USD", "$", 1.0 );
    MoneyAmount money_amount1( usd, 100.0 );
    MoneyAmount money_amount2( usd, 35.0 );

    MoneyAmount result = money_amount1 + money_amount2;

    std::cout << "Add2MoneyAmounts_NotEqualAmounts: " << std::string(result) << std::endl;
  } catch(...) {
    std::cout << "test_Add2MoneyAmounts_NotEqualAmounts";
  }
  return 0;
};

int test_Add2MoneyAmounts_NotEqualCurrency()
{

  try {
    Currency usd1( "USD", "$", 1.0 );
    Currency usd2( "USD", "$", 1.4 );
    MoneyAmount money_amount1( usd1, 100.0 );
    MoneyAmount money_amount2( usd2, 35.0 );

    MoneyAmount result = money_amount1 + money_amount2;

    std::cout << "test_Add2MoneyAmounts_NotEqualCurrency: " << std::string(result) << std::endl;
  } catch (CurrExcp& excp) {
    std::cout << "Exception: test_Add2MoneyAmounts_NotEqualCurrency" << excp.errstr << std::endl;
  }
  return 0;
};

int test_MultMoneyAmounts(){
  try {
    Currency usd( "USD", "$", 1.0 );
    MoneyAmount money_amount( usd, 100.0 );

    MoneyAmount result = 0.5 * money_amount;
    std::cout << "test_MultMoneyAmout: " << std::string(result) << std::endl;
  } catch(CurrExcp& excp) {
    std::cout << "Exception: test_MultMoneyAmounts" << excp.errstr << std::endl;
  }
   return 0;
}

int main(int argc, char* argv[])
{
  test_Add2MoneyAmounts_EqualAmounts();
  test_Add2MoneyAmounts_NotEqualAmounts();
  test_Add2MoneyAmounts_NotEqualCurrency();
  test_MultMoneyAmounts();
  return 0;
}
