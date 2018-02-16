/**
	Name: Pavan Kumar Kamra
	Course: BTP305
**/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

extern const int FWC;
extern const int FWD;
extern const int FWP;
namespace w9 {
  struct Description {
    unsigned code;
    std::string desc;
    bool load(std::ifstream & f) { // this inputs from the file. 
      f >> code >> desc;
      return f.good();
    }

    void display(std::ostream & os) const {
      os << std::setw(FWC) << code << std::setw(FWD) << desc << std::endl; // displays info from the os stream. 
    }
  };

  struct Price {
    unsigned code;
    double price;
    bool load(std::ifstream & f) { // inputs from the file. 
      f >> code >> price;
      return f.good();
    }

    void display(std::ostream & os) const {
      os << std::setw(FWC) << code << std::setw(FWP) << price << std::endl;
    }
  };

  struct Product {
    std::string desc;
    double price;
    Product() {}
    Product(const std::string & str, double p): desc(str), price(p) {}
    void display(std::ostream & os) const {
      os << std::setw(FWD) << desc << std::setw(FWP) << price << std::endl;
    }
    void validate() { // this validates program to see if the prices are over 0. 
      if (price < 0.0) {
        throw "***Negative prices are invalid***";
      }
    }
  };
}
