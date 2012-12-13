#include "Account.h"


Account::Account( int account_id, Client* owner ) {
	m_bank = owner->getBank();
	m_owner = owner;
	m_created = time(0);
	m_id = account_id;
}


Account::Account( const MoneyAmount &money_amount, int account_id, Client* owner ) {
	setMoneyAmount( money_amount );
	m_created = time(0);
	m_bank = owner->getBank();
	m_owner = owner;
	m_id = account_id;
}

Account::Account( Currency *currency, int account_id, Client* owner ) {
	setMoneyAmount( MoneyAmount( currency ) );
	m_created = time(0);
	m_bank = owner->getBank();
	m_owner = owner;
	m_id = account_id;
}


Account::~Account(){
	if ( m_owner->hasAccountById( m_id ) ) {
		m_owner->removeAccountById( m_id );
	}

	if ( m_bank->hasAccountById( m_id ) ) {
		m_bank->removeAccountById( m_id );
	}
}


int Account::getId() const {
	return m_id;
}

MoneyAmount Account::getMoneyAmount() const {
	return m_money_amount;
}

void Account::initTransactionTo( Account *account_dst, const MoneyAmount &money_amount_send ) {
	Transaction *new_transaction = new Transaction( this, account_dst, money_amount_send );	//TODO: Put transaction in "Bank" contain (not in heap)
	new_transaction->commit();

	m_transactions.push_back( new_transaction );
	//m_bank.addTranssaction( new_transaction ); TODO
}


void Account::initTransactionToById( int account_id, const MoneyAmount &money_amount_send ) {
	Account *account_dst = m_bank->getAccountById( account_id );

	initTransactionTo( account_dst, money_amount_send );
}

void Account::initTransactionTo( Account *account_dst, const MoneyAmount &money_amount_send, time_t time ) {
	Transaction *new_transaction = new Transaction( this, account_dst, money_amount_send );	//TODO: Put transaction in "Bank" contain (not in heap)
	new_transaction->commit( time );

	m_transactions.push_back( new_transaction );
	account_dst->m_transactions.push_back( new_transaction );
	//m_bank.addTranssaction( new_transaction ); TODO
}


void Account::initTransactionToById( int account_id, const MoneyAmount &money_amount_send, time_t time ) {
	Account *account_dst = m_bank->getAccountById( account_id );

	initTransactionTo( account_dst, money_amount_send, time );
}


void Account::setMoneyAmount( const MoneyAmount &money_ammount ) {
	m_money_amount = money_ammount;
}


MoneyAmount Account::getSaldo(long time_delta, time_t final_time) const {
	MoneyAmount saldo;
	time_t beginning_time = final_time - time_delta;
	for( std::vector<Transaction*>::const_iterator i = m_transactions.begin(); i != m_transactions.end(); ++i ) {
		if( beginning_time <= (*i)->getCommitTime() && (*i)->getCommitTime() <= final_time ) {
			MoneyAmount money_delta = (*i)->getMoneyAmount();
			if( (*i)->getSourceAccount() == this ){
				money_delta = -money_delta;
			}
			saldo += money_delta;
		}
	}
	return saldo;
}


MoneyAmount Account::getSaldo( long time_delta ) const {
	return getSaldo( time_delta, std::time( NULL ) );
}
