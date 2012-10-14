#include "Currency.h"



Currency::Currency( const std::string& name, const std::string& sign, double value ) {
	m_value = value;
	m_sign = sign;
	m_name = name;
}


Currency::Currency( const Currency& src ) {
    m_name = src.m_name;
    m_sign = src.m_sign;
    m_value = src.m_value;
}


bool operator==( const Currency& left, const Currency& right){
  return ( (left.getValue() == right.getValue()) && 
        ( left.getName() == right.getName() ) && 
        ( left.getSign() == right.getSign() ) );
}
