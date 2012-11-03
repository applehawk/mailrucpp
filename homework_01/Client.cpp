#include "Bank.h"


Client::Client(const std::string& first_name, const std::string& second_name, const std::string& birth, Bank* bank):Person( first_name, second_name, birth ) {
	m_bank = bank;
}

int Client::getMainAccountId() const {
	if ( !m_accounts_id.empty() ) {
		return m_accounts_id[0]; //return first account
	} else {
		//Exeption();
		return -1;
	}
}


Account* Client::getMainAccount() const {
	int main_account_id = getMainAccountId();
	if ( main_account_id != -1 ) {
		return m_bank->getAccountById( m_accounts_id[0] ); //return first account
	} else {
		//Exeption();
		return NULL;
	}
}

int Client::createAccount() {
	Account *account = new Account( m_bank );
	int account_id = m_bank->addAccountInBase( account );

	m_accounts_id.push_back( account_id );

	return account_id;

}

int Client::createAccount(Currency* currency) {
	Account *account = new Account( currency, m_bank );
	int account_id = m_bank->addAccountInBase( account );

	m_accounts_id.push_back( account_id );

	return account_id;
}

int Client::createAccount( const MoneyAmount &money_amount ) {
	Account *account = new Account( money_amount, m_bank );
	int account_id = m_bank->addAccountInBase( account );

	m_accounts_id.push_back( account_id );

	return account_id;
}
