#include "Account.h"


Account::Account( const MoneyAmount &money_amount ) {
	setMoneyAmount( money_amount );
}

MoneyAmount Account::getMoneyAmount() const {
	return m_money_amount;
}

void Account::initTransactionTo( Account *account_dst, MoneyAmount &money_amount_send ) {
	Transaction *new_transaction = new Transaction( this, account_dst, money_amount_send );	//TODO: Put transaction in "Bank" contain (not in heap)
	new_transaction->commit();

	m_transactions.push_back( new_transaction );
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
