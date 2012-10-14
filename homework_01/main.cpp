#include <string>
#include <iostream>

//using namespace std; - not recomended (please, use std:: construction)


#include "MoneyAmount.h"
#include "Currency.h"

#include "MoneyAmountTests.h"

typedef long int Date;


int main(int argc, char* argv[]) {
  test_Add2MoneyAmounts_EqualCurrency();
  test_Add2MoneyAmounts_NotEqualCurrency();
  test_MultMoneyAmounts();
  test_ConvertCurrency();
  test_AddSubWithAssign_NotEqualCurrency();

  return 0;
}
