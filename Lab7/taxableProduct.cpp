/**
	Name:Pavan Kumar Kamra
	Course: BTP305
**/

#include "taxableProduct.h"

//static array for the GST & HST. 
const double w7::taxableProduct::TAX[2] = {
  0.13,
  0.08
};

//default constructor
w7::taxableProduct::taxableProduct(): taxType() {}

//overloaded constructor
w7::taxableProduct::taxableProduct(long P, double c, char a): Product(P, c), taxType(a) {}

//gets the charge and if HST/GST is applied/ 
double w7::taxableProduct::getCharge() const {
  double base = Product::getCharge();
  double total;
  if (taxType == 'H') {
    return base + base * TAX[0];
  } else {
    return base + base * TAX[1];
  }

}

//display. 
void w7::taxableProduct::display(std::ostream & os) const {
  Product::display(os); //this is how you do it for a class. Instance is a dot function.
  os << " " << taxType << "ST";
}