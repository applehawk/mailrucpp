#include "Transaction.h"


Transaction::Transaction( Account *src, Account *dst, const MoneyAmount &money_amount ) {
	m_source_account = src;
	m_destination_account = dst;
	m_money_amount = money_amount;

	is_commited = false;
}


void Transaction::commit() {
	m_source_account->m_money_amount -= m_money_amount;
	m_destination_account->m_money_amount += m_money_amount;

	is_commited = true;
}
