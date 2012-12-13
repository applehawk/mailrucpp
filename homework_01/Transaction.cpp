#include "Transaction.h"


Transaction::Transaction( Account *src, Account *dst, const MoneyAmount &money_amount ) {
	m_source_account = src;
	m_destination_account = dst;
	m_money_amount = money_amount;
	m_commited = not_commited_time;
}


void Transaction::commit() {
	commit( std::time( NULL ) );
}

void Transaction::commit( time_t time ) {
	m_source_account->m_money_amount -= m_money_amount;
	m_destination_account->m_money_amount += m_money_amount;

	m_commited = time;
}

time_t Transaction::getCommitTime() const throw( ErrorTransactionNotCommited ) {
	if ( !isCommited() ) {
		throw new ErrorTransactionNotCommited();
	}
	return m_commited;
}

bool Transaction::isCommited() const throw() {
	return m_commited != not_commited_time;
}
