#include <string>

using namespace std;

typedef long int Date;
typedef unsigned long long Decimal;

class Bank {
public:

private:
  int m_totalAccounts;

  vector<Account*> m_accounts;
  vector<Client*> m_clients;
}

class Transaction {
public:
  Transaction();
  ~Transaction();
private:
  Date m_dateOfOperation; 
  BankingAccount* m_sourceAccount;
  BankingAccount* m_destAccount;
}

class Account {
public:
  BankingAccount() {}
  ~BankingAccount() {}

  int debet(Date sum) {}
  int drawal(Decimal sum) {}
private:
};

class CheckingAccount : public Account {
public:
  CheckingAccount() {}
  ~CheckingAccount() {}
};

class SavingsAccount : public Account {
public:
  SavingsAccount() {}
  ~SavingsAccount() {}
};

class Person {
public:
  Person(const string& aFirstName, const string& aSecondName, int aDateBirth)
  {
    m_firstName = aFirstName;
    m_secondName = aSecondName;
    m_dateOfBirth = aDateBirth;
  }

  virtual ~Person() {}
  const string& firstName() { return m_firstName; }
  const string& secondName() { return m_secondName; }
  int dateOfBirth() { return m_dateOfBirth; }
private:
  string m_firstName;
  string m_secondName;
  int m_dateOfBirth;
};

class Client : public Person
{
public:
private:
  vector<Account*> m_accounts; 
};

class Employee : public Client
{
}

int main(int argc, char* argv[])
{
  return 0;
};
