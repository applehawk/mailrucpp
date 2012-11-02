#include "Bank.h"

Bank::Bank() {
	//Default value
	addCurrency( new Currency( "USD", "$", 1.0 ) );
	addCurrency( new Currency( "EUR", "€", 1.3 ) );
	addCurrency( new Currency( "RUR", "rub", 0.035 ) );

}



int Bank::createClient( const std::string &first_name, const std::string &second_name ) {
	Client *client = new Client( first_name, second_name, this );
	int client_id = m_clients.size();

	m_clients.insert( std::pair<int, Client*>( client_id, client ) );

	return client_id;
}


int Bank::addAccountInBase( Account* account ) {
	int account_id = m_accounts.size();

	m_accounts.insert( std::pair<int, Account*>( account_id, account ) );

	return account_id;
}


Client* Bank::getClientById( const int client_id ) const {
	if ( m_clients.find( client_id ) != m_clients.end() ) {
		return m_clients.find( client_id )->second;
	} else {
		//Exeption; TODO
		return NULL;
	}
}


Currency* Bank::getCurrencyByName( const std::string &name ) const {
	if ( m_currencies.find( name ) != m_currencies.end() ) {
		return m_currencies.find( name )->second;
	} else {
		//Exeption; TODO
		return NULL;
	}
}

Account* Bank::getAccountById( const int account_id ) const {
	if ( m_accounts.find( account_id ) != m_accounts.end() ) {
		return m_accounts.find( account_id )->second;
	} else {
		//Exeption; TODO
		return NULL;
	}
}

void Bank::addCurrency( Currency *currency ) {
	m_currencies.insert( std::pair<std::string, Currency*>( currency->getName(), currency ) );
}
