#include <iostream>
class Error
{
public:
	Error() {}
	virtual void showError() const { std::cerr << "Error of class Error";}
	virtual ~Error() {}
};

class ErrorPerson: public Error {};
class ErrorPersonDate: public ErrorPerson {};
class ErrorPersonDateYear: public ErrorPersonDate {
public:
	ErrorPersonDateYear(int _year): year(_year){}
	void showError() const {
		std::cout << "Year should be integer in range from 1920 to 1994"<< std::endl;
		std::cout << "Input year is " << year << std::endl;
	}
private:
	int year;
};
