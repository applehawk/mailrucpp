#ifndef _Person_hh_
#define _Person_hh_

#include <iostream>

class Person {
private:
    time_t m_created;
    time_t encode(std::string str);
    time_t setCurTime();
    int convert(unsigned short b, unsigned short e, std::string&);
    Person();
public:
	Person(std::string _first_name, std::string _second_name, std::string _birth)
	{
		m_first_name = _first_name;
		m_second_name = _second_name;
		m_birth = encode(_birth);
		m_created = setCurTime();
	}
	void changeFirstName(std::string str) {m_first_name = str;}
	void changeSecondName(std::string str) {m_second_name = str;}
	void chanegeDateOfBirth(std::string str) {m_birth = encode(str);}
	void printPerson();

protected:
    std::string m_first_name;
    std::string m_second_name;
    time_t m_birth;



};

#endif /* _Person_hh_ */

