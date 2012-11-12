#include "AccountsOwner.h"
#include "MoneyAmount.h"
#include "Account.h"
#include "Bank.h"
#include <vector>

void AccountsOwner::addAccount(Account& account){
	m_accounts.push_back(&account);
}

void AccountsOwner::showAccounts(){
	for(std::vector<Account*>::iterator it = m_accounts.begin(); it != m_accounts.end(); ++it) {
		std::cout << "OK!!!";
	}
}
