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
	Currency( const std::string&, const std::string&, double );
	Currency( const Currency& );

	const std::string& getName() const {return m_name;}
	const std::string& getSign() const { return m_sign; }
	double getValue() const { return m_value; };
	double getFactorForConverting( Currency* ) const;

  

  	friend bool operator ==(const Currency& left, const Currency& right);

private:
	std::string m_name;
	std::string m_sign;	//Sign of currency
	double m_value;

	Currency(); //Deny of default constructor

};


#endif
