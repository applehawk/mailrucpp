test: main.o MoneyAmount.o Currency.o Account.o Transaction.o Bank.o Client.o
	g++ -Wall main.o MoneyAmount.o Currency.o Account.o Transaction.o Bank.o Client.o -o bank;
	
main.o: main.cpp MoneyAmount.h Currency.h MoneyAmountTests.h AccountTransactionsTests.h BankTests.h
	g++ -Wall -c main.cpp -o main.o
	
Transaction.o: Transaction.cpp Transaction.h Account.h MoneyAmount.h
	g++ -Wall -c Transaction.cpp -o Transaction.o

MoneyAmount.o: MoneyAmount.cpp MoneyAmount.h Currency.h
	g++ -Wall -c MoneyAmount.cpp -o MoneyAmount.o

Currency.o: Currency.cpp Currency.h
	g++ -Wall -c Currency.cpp -o Currency.o
	
Account.o: Account.cpp Account.h MoneyAmount.h Bank.h
	g++ -Wall -c Account.cpp -o Account.o

Client.o: Client.cpp Client.h Person.h Bank.h Account.h Currency.h MoneyAmount.h
	g++ -Wall -c Client.cpp -o Client.o

Bank.o: Bank.cpp Bank.h Client.h Person.h Account.h Currency.h
	g++ -Wall -c Bank.cpp -o Bank.o