#include "Bank.h"


Client::Client(const std::string& first_name, const std::string& second_name, const std::string& birth, Bank* bank):Person( first_name, second_name, birth ) {
	m_bank = bank;
}


int Client::createAccount() {
	int account_id = m_bank->generateAccountId();

	Account *account = new Account( account_id, this );


	addAccount( account_id, account );
	m_bank->addAccount( account_id, account );

	return account_id;
}

int Client::createAccount( Currency* currency ) {
	int account_id = m_bank->generateAccountId();
	Account *account = new Account( currency, account_id, this );


	addAccount( account_id, account );
	m_bank->addAccount( account_id, account );

	return account_id;
}

int Client::createAccount( const MoneyAmount &money_amount ) {
	int account_id = m_bank->generateAccountId();
	Account *account = new Account( money_amount, account_id, this );

	addAccount( account_id, account );
	m_bank->addAccount( account_id, account );

	return account_id;
}

Bank* Client::getBank() const {
	return m_bank;
}
