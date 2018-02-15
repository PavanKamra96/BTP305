/**
	Name: Pavan Kumar Kamra
	Course:BTP305
**/
#ifndef _TAXABLE_PRODUCT_H
#define _TAXABLE_PRODUCT_H
#include "Product.h"
#include <iostream>

namespace w7{
	class taxableProduct: public Product {
		private: 
			char taxType;
			static const double TAX[2]; // do not do in constructor. 			
		public:
			taxableProduct();
			taxableProduct(long P, double c, char a); 
			double getCharge() const; 
			void display (std::ostream& os) const;
		}; 
	}
#endif
