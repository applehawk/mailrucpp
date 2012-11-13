#include "AccountsOwner.h"

void AccountsOwner::addAccount(int account_id, Account* account) {
	if ( hasAccountById( account_id ) ) {
		throw "Error: dublicate id";
	}

	m_accounts.insert( std::pair<int, Account*>( account_id, account ) );
	max_id = std::max( max_id, account_id );
}


Account* AccountsOwner::getAccountById( int account_id ) const {
	if ( !hasAccountById( account_id ) ) {
			throw "Error: Hasn't account with this id";
	}

	return m_accounts.find( account_id )->second;
}


bool AccountsOwner::hasAccountById( int account_id ) const {
	return ( m_accounts.find( account_id ) != m_accounts.end() );
}


void AccountsOwner::removeAccountById( int account_id ) {
	if ( !hasAccountById( account_id ) ) {
		throw "Error: Hasn't account with this id";

	}

	m_accounts.erase( m_accounts.find( account_id ) );
}


int AccountsOwner::getMaxId() const {
	return max_id;
}

Account* AccountsOwner::getMainAccount() const {
	if ( size() == 0 ) {
		throw "No accounts";
	}

	return m_accounts.begin()->second;
}

int AccountsOwner::size() const {
	return m_accounts.size();
}
