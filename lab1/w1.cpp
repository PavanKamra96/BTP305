/** 
   Name: Pavan Kumar Kamra
   Course: BTP305
**/

#include <iostream> 
#include "Cstring.h"
#include "process.h"

int main(int argc, char * argv[]) {

  std::cout << "Command Line : ";
  for (int j = 0; j < argc; j++) {
    std::cout << argv[j] << " ";
  }

  if (argc <= 1) {
    std::cout << "\nInsufficient Number of Arguments (min 1)" << std::endl;
  } else {
    std::cout << "\nMaximum number of characters stored : " << w1::charNum << std::endl;
  }

  for (int k = 1; k < argc; k++) {
    process(argv[k]);
  }
}