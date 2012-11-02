#include "Bank.h"
#include "Account.h"
#include "Currency.h"
#include "Client.h"
#include "MoneyAmount.h"

int test_Bank() {
	try{
		std::cout << "test_Bank" << std::endl;

		Bank bank;
		Currency *usd_curr = bank.getCurrencyByName("USD");
		Currency *eur_curr = bank.getCurrencyByName("EUR");

		MoneyAmount sended_money_amount( usd_curr, 100.0 );


		int id_client1 = bank.createClient( "Jhon", "Bross" );
		std::cout << "Created client Jhon Bross. id = " << id_client1 << std::endl;
		int id_client2 = bank.createClient( "Victor", "Calugin" );
		std::cout << "Created client Victor Calugin. id = " << id_client2 << std::endl;

		bank.getClientById( id_client1 )->createAccount( MoneyAmount( usd_curr, 200.0 ) );
		std::cout << "Jhon Bross(" << id_client1 << ") has " << std::string( bank.getClientById( id_client1 )->getMainAccount()->getMoneyAmount() ) << std::endl;
		bank.getClientById( id_client2 )->createAccount( MoneyAmount( eur_curr, 100.0 ) );
		std::cout << "Victor Calugin(" << id_client2 << ") has " << std::string( bank.getClientById( id_client2 )->getMainAccount()->getMoneyAmount() ) << std::endl;
		std::cout << std::endl;

		int account_id2 = bank.getClientById( id_client2 )->getMainAccountId();

		bank.getClientById( id_client1 )->getMainAccount()->initTransactionToById( account_id2, sended_money_amount );
		std::cout << "Inited transaction " << std::string( sended_money_amount ) << " from  Jhon Bross to Victor Calugin" << std::endl;
		std::cout << std::endl;
		std::cout << "Jhon Bross(" << id_client1 << ") has " << std::string( bank.getClientById( id_client1 )->getMainAccount()->getMoneyAmount()  ) << std::endl;
		std::cout << "Victor Calugin(" << id_client2 << ") has " << std::string( bank.getClientById( id_client2 )->getMainAccount()->getMoneyAmount() ) << std::endl;


	}catch(...){
		std::cout << "Exeption::test_bank";
	}

	return 0;
}
