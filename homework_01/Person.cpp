#include "Person.h"
#include "Error.h"
#include <iostream>
#include <sstream>
#include <ctime>


time_t Person::encode(std::string date){
	int day = convert(0, 2, date);
	int month = convert(3, 5, date);
	int year = convert(6, 9, date);
	if ((year > year_end) || (year < year_begin)) throw ErrorPersonDateYear(year);
	//std::cout << "Day: " << day)<< "  " << "Month: " << month << "  " << "Year: " << year << std::endl;

	time_t rawtime;
	struct tm * timeinfo;

	timeinfo = localtime ( &rawtime );
	timeinfo->tm_year = year - 1900;
	timeinfo->tm_mon = month - 1;
	timeinfo->tm_mday = day;
	timeinfo->tm_hour = 0;
	timeinfo->tm_min = 0;
	timeinfo->tm_sec = 0;
	rawtime = mktime (timeinfo);
	//std::cout << ctime(&rawtime) << std::endl;
	return rawtime;
}

int Person::convert(unsigned short b, unsigned short e, std::string& str){
	int i;
	std::stringstream ss(str.substr(b,e)); ss >> i;
	return i;
}

time_t Person::setCurTime(){
	//time_t rawtime=time(0);
	//std::cout << ctime(&rawtime) << std::endl;
	return time(0);
}

void Person::printPerson(){
	std::cout << "Name: "<< m_first_name << std::endl;
	std::cout << "Second name: "<< m_second_name << std::endl;
	std::cout << "Date of birth: "<< ctime(&m_birth);
	std::cout << "Date of creation: "<< ctime(&m_created) << std::endl;
}
