/** 
	Name: Pavan Kumar Kamra
	Course: BTP305
**/
#include "Product.h"

// Default Constructor
w7::Product::Product(): ProductId(0), cost(0.0) {}

// Overloaded Constructor
w7::Product::Product(long prod, double co): ProductId(prod), cost(co) {}

//Returns the cost of the product. 
double w7::Product::getCharge() const {
  return cost;
}

//Displays the Product Id. 
void w7::Product::display(std::ostream & os) const {
  os << std::setw(10) << ProductId << std::setw(10) << cost;
}
