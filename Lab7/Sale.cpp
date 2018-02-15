/** 
	Name: Pavan Kumar Kamra
	Course: BTP305
**/

#include "Sale.h"

namespace w7 {
  //This makes a list of products in a vector. 
  Sale::Sale(const char * filename) {
    std::ifstream file(filename);

    if (!file) {
      return;
    }

    while (file.good()) {
      try {
        products.push_back(readProduct(file));
      } catch (const char * message) {
        std::cerr << message << std::endl;
        for (auto p = products.begin(); p != products.end(); p++) {
          delete * p;
        }
        products.clear();
        file.close();
        return;
      }
    }
  }

  // This displays the results. 
  void Sale::display(std::ostream & os) const {
    double total = 0;
    os << std::setw(10) << "Product No";
    os << std::setw(10) << "Cost" << " " << "Taxable" << std::endl;
    for (int i = 0; i < products.size(); i++) {
      total += products[i] - > getCharge();
      products[i] - > display(os);
      os << std::endl;
    }
    os << std::setw(10) << "Total";
    os << std::setw(10) << std::setprecision(2);
    os << std::fixed << total;
  }
}