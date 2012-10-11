#include <string>

using namespace std;

class BankingAccount {
public:
  BankingAccount() {}
  ~BankingAccount() {}

  int debet(int sum) {} 

};

class CheckingAccount : public BankingAccount {
public:
  CheckingAccount() {}
  ~CheckingAccount() {}
};

class SavingsAccount : public BankingAccount {
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
};

int main(int argc, char* argv[])
{
  return 0;
};
