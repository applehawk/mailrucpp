#ifndef _BankTests_hh_
#define _BankTests_hh_

#include "Bank.h"
#include "Account.h"
#include "Currency.h"
#include "Client.h"
#include "MoneyAmount.h"

int test_Bank() {
	try{
	    std::cout<<"Bank tests began:" << std::endl;

		Bank bank;
		Currency *usd_curr = bank.getCurrencyByName("USD");
		Currency *eur_curr = bank.getCurrencyByName("EUR");


		int id_client1 = bank.createClient( "Jhon", "Bross", "02.12.1990" );
		std::cout << "Created client Jhon Bross. id = " << id_client1 << std::endl;
		int id_client2 = bank.createClient( "Victor", "Calugin", "02.12.1990" );
		std::cout << "Created client Victor Calugin. id = " << id_client2 << std::endl;

		bank.getClientById( id_client1 )->createAccount( MoneyAmount( usd_curr, 200.0 ) );
		std::cout << "Jhon Bross(" << id_client1 << ") has " << std::string( bank.getClientById( id_client1 )->getMainAccount()->getMoneyAmount() ) << std::endl;

		bank.getClientById( id_client2 )->createAccount( MoneyAmount( eur_curr, 100.0 ) );
		std::cout << "Victor Calugin(" << id_client2 << ") has " << std::string( bank.getClientById( id_client2 )->getMainAccount()->getMoneyAmount() ) << std::endl;
		std::cout << std::endl;

		int account_id2 = bank.getClientById( id_client2 )->getMainAccount()->getId();

		time_t now = std::time( NULL );

		for( int i=0, j=1; i<6; i++, j<<=1 ) {
			MoneyAmount sended_money_amount( usd_curr, j );
			time_t time = now - 100 + i;
			bank.getClientById( id_client1 )->getMainAccount()->initTransactionToById( account_id2, sended_money_amount, time );
			std::cout << "Inited transaction " << std::string( sended_money_amount ) << " from Jhon Bross to Victor Calugin at " << ctime( &time );
		}
		std::cout << std::endl;

		long time_delta = 100 - 2;
		std::cout << "Jhon Bross(" << id_client1 << ") saldo by last " << time_delta << " seconds is " << std::string( bank.getClientById( id_client1 )->getMainAccount()->getSaldo( time_delta )  ) << std::endl;
		std::cout << "Victor Calugin(" << id_client2 << ") saldo by last " << time_delta << " seconds is " << std::string( bank.getClientById( id_client2 )->getMainAccount()->getSaldo( time_delta ) ) << std::endl;
		std::cout << std::endl;

		std::cout << "Jhon Bross(" << id_client1 << ") has " << std::string( bank.getClientById( id_client1 )->getMainAccount()->getMoneyAmount()  ) << std::endl;
		std::cout << "Victor Calugin(" << id_client2 << ") has " << std::string( bank.getClientById( id_client2 )->getMainAccount()->getMoneyAmount() ) << std::endl;


	}catch(...){
		std::cout << "Exeption::test_bank";
	}
    std::cout<<"Bank tests finished" << std::endl << std::endl << std::endl;
	return 0;
}

#endif /* _BankTests_hh_ */
