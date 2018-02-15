/** 
	Name: Pavan Kumar Kamra
	Course: BTP305
**/
#include "iProduct.h"
#include "Product.h"
#include "taxableProduct.h"
#include <string>
#include <vector>
	
	// This overloads the << operator
std::ostream & w7::operator << (std::ostream & os,
  const iProduct & P) {
  P.display(os);
  return os;
}

//This reads, extracts the info, & divides the information in correct variables from a file. 
w7::iProduct * w7::readProduct(std::ifstream & file) {
  std::string record;
  long productId;
  double cost;
  char tax;
  w7::iProduct * prod;
  std::vector < std::string > tokens;

  int startpos = 0, endpos = 0;
  std::getline(file, record);
  int length = record.size();
  while (startpos < length) {
    endpos = record.find(' ', startpos);
    if (endpos == std::string::npos) {
      endpos = length;
    }
    tokens.push_back(record.substr(startpos, endpos - startpos)); //add values to vector.
    startpos = endpos + 1;
  }

  productId = std::stol(tokens[0]);
  cost = std::stod(tokens[1]);

  if (tokens.size() == 2) {
    return new Product(productId, cost);
  }
  tax = tokens[2].c_str()[0];
  if (tax == 'H' || tax == 'P') {
    return new taxableProduct(productId, cost, tax);
  }
  throw "File is corrupted! ";

}
