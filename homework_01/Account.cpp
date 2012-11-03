#include "Account.h"

Account::Account() {
	m_money_amount = MoneyAmount();
	m_created = time(0);
	m_bank = NULL;
}

Account::Account( Bank* bank ) {
	m_money_amount = MoneyAmount();
	m_created = time(0);
	m_bank = bank;
}


Account::Account( const MoneyAmount &money_amount, Bank* bank ) {
	setMoneyAmount( money_amount );
	m_created = time(0);
	m_bank = bank;
}

Account::Account( Currency *currency, Bank* bank ) {
	setMoneyAmount( MoneyAmount( currency ) );
	m_created = time(0);
	m_bank = bank;
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


void Account::setMoneyAmount( const MoneyAmount &money_ammount ) {
	m_money_amount = money_ammount;
}


MoneyAmount Account::getSaldo(long time_delta, time_t final_time) const {
	//TODO
	return m_money_amount;
}


MoneyAmount Account::getSaldo( long time_delta ) const {
	//TODO
	return m_money_amount;
}
