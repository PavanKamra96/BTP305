/** 
   Name: Pavan Kumar Kamra
   Course: BTP305
**/

#include "Cstring.h"
#include "process.h"

void process(const char * proc) {
  if (strlen(proc) >= w1::charNum && proc != nullptr) {
    w1::CString ch(proc);
    std::cout << ch << std::endl;
  }
}
