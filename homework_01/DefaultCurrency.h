/*
 * DefaultCurrency.h
 *
 *  Created on: 30.10.2012
 *      Author: anton
 */

#ifndef DEFAULTCURRENCY_H_
#define DEFAULTCURRENCY_H_

#include "Currency.h"

#define DEFAULT_NAME "USD"
#define DEFAULT_SIGN "$"

class DefaultCurrency: public Currency {
public:
	DefaultCurrency():Currency( DEFAULT_NAME, DEFAULT_SIGN, 1.0 ) {

	}
};

#endif /* DEFAULTCURRENCY_H_ */
