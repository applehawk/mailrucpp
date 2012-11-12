#include <string>
#include <iostream>

//using namespace std; - not recomended (please, use std:: construction)


#include "MoneyAmount.h"
#include "Currency.h"

#include "MoneyAmountTests.h"
#include "AccountTransactionsTests.h"
#include "BankTests.h"
#include "PersonTests.h"


typedef long int Date;


int main(int argc, char* argv[]) {
  test_MoneyAmount();
  test_Transaction();
  test_Bank();
  test_Person();
  return 0;
}
