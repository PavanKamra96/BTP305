/** 
   Name: Pavan Kumar Kamra
   Course: BTP305
**/

#ifndef _CSTRING_H_
#define _CSTRING_H_
#include <iostream> 
#include < cstring >

  // Creates a CString class inside the namespace w1. 
  namespace w1 {
    const int charNum = 4;
    class CString {
      public:
        CString();
		CString(const char * );
		void display(std::ostream & ) const;
      private:
        char str[charNum + 1];
    };
    std::ostream & operator << (std::ostream & , const CString & );
  }

#endif