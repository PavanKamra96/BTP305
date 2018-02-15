/**
	Name: Pavan Kumar Kamra
	Course: BTP305
**/

#ifndef _SALE_H_
#define _SALE_H_
#include "iProduct.h"
#include <vector>
#include <fstream> 
#include <iomanip>

namespace w7 {
	class Sale
	{
		std::vector<iProduct*> products;

	public:
		Sale(const char* filename);
		void display(std::ostream& os) const;
	};
}
#endif

