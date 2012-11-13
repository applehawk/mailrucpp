#include <string>
#include <iostream>


#include "MoneyAmount.h"
#include "Currency.h"

#include "MoneyAmountTests.h"
#include "BankTests.h"
#include "PersonTests.h"


typedef long int Date;


int main(int argc, char* argv[]) {
  test_MoneyAmount();
  test_Bank();
  test_Person();

  return 0;
}
