/* 
   
 */

#ifndef _Person_hh_
#define _Person_hh_

#include <string>

class Person {
public:
	Person( const std::string &first_name, const std::string &second_name ) {
		m_first_name = first_name;
		m_second_name = second_name;
	}

	std::string getFullName() {
		return ( m_first_name + " " + m_second_name );
	}

protected:
    std::string m_first_name;
    std::string m_second_name;
    //time_t m_birth;
   // time_t m_created;



};

#endif /* _Person_hh_ */

