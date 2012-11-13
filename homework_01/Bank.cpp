#include "Bank.h"

Bank::Bank() {
	//Default value
	addCurrency( new Currency( "USD", "$", 1.0 ) );
	addCurrency( new Currency( "EUR", "€", 1.3 ) );
	addCurrency( new Currency( "RUR", "rub", 0.035 ) );

}



int Bank::createClient( const std::string &first_name, const std::string &second_name, const std::string &birth ) {
	Client *client = new Client( first_name, second_name, birth, this );
	int client_id = m_clients.size();

	m_clients.insert( std::pair<int, Client*>( client_id, client ) );

	return client_id;
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

int Bank::generateAccountId() const {
	return getMaxId() + 1;
}

void Bank::addCurrency( Currency *currency ) {
	m_currencies.insert( std::pair<std::string, Currency*>( currency->getName(), currency ) );
}
