#include "Currency.h"

bool operator==( const Currency& left, const Currency& right){
  return ( (left.getValue() == right.getValue()) && 
        ( left.getName() == right.getName() ) && 
        ( left.getSign() == right.getSign() ) );
}
