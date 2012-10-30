test: main.o MoneyAmount.o Currency.o Account.o
	g++ -Wall main.o MoneyAmount.o Currency.o -o test;
	
main.o: main.cpp MoneyAmount.h Currency.h MoneyAmountTests.h
	g++ -Wall -c main.cpp -o main.o

MoneyAmount.o: MoneyAmount.cpp MoneyAmount.h Currency.h
	g++ -Wall -c MoneyAmount.cpp -o MoneyAmount.o

Currency.o: Currency.cpp Currency.h
	g++ -Wall -c Currency.cpp -o Currency.o
	
Account.o: Account.cpp Account.h MoneyAmount.h
	g++ -Wall -c Account.cpp -o Account.o