/**
    Name: Pavan Kumar Kamra
    Course: BTP305
**/

#ifndef _PRODUCT_H_
#define _PRODUCT_H_
#include "iProduct.h"
#include <iostream>
#include <iomanip>

namespace w7 {
	class Product: public iProduct 
	{
		private:
			long ProductId;
			double cost;
			
		public: 
			Product();
			Product(long, double);  
			double getCharge() const; 
			void display(std::ostream& os) const; 			
	};

}
#endif
