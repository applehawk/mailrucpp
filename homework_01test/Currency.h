#ifndef H_CURRENCY
#define H_CURRENCY

#include <string>

class CurrExcp
{
public:
  CurrExcp(const std::string& _excp): errstr(_excp) {}
  std::string errstr;
};

class Currency{
public:
  Currency( const Currency& src ) {
    m_name = src.m_name;
    m_sign = src.m_sign;
    m_value = src.m_value;
  }
	Currency( const std::string& name, const std::string& sign, double value ) {
		m_value = value;
		m_sign = sign;
		m_name = name;
	}

  friend bool operator ==(const Currency& left, const Currency& right);

	const std::string& getName() const {return m_name;}
	const std::string& getSign() const { return m_sign; }
	double getValue() const { return m_value; };

private:
	std::string m_name;
	std::string m_sign;	//Sign of currency
	double m_value;

	Currency(); //Deny of default constructor

};


#endif
