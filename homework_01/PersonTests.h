#ifndef PERSON_TEST_H
#define PERSON_TEST_H
#include "Person.h"
#include "Bank.h"
#include "AccountsOwner.h"
#include "Error.h"

int PersonCorrectDate(){
	Person person("John", "Smith", "02.12.1990");
	try {
		person.printPerson();
		person.chanegeDateOfBirth("03.03.190");
		person.changeFirstName("Ruslan");
		person.changeSecondName("Guseynov");
		person.printPerson();
	}
	catch (Error& error) {error.showError();}
	catch (...) {std::cout << "All errors catcher";}
	person.printPerson();
	return 0;
}

int test_Person(){
	std::cout<<"Person tests began:" << std::endl;
	PersonCorrectDate();
	std::cout<<"Person tests finished" << std::endl << std::endl << std::endl;
	return 0;
}
#endif

