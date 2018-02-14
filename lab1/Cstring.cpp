/** 
   Name: Pavan Kumar Kamra
   Date: 9/18/2015
   Course: BTP305
   Purpose: Cstring class that involves Default constructors, overloadded constructor, display function & << operator 
**/

#include "Cstring.h"

// Default Constructor 	
w1::CString::CString() {
  str[0] = '\0';
}

//Overloaded Constructor that checks if inputted string is long enough & if the user inputted, else it becomes the default constructor.  	
w1::CString::CString(const char * character) {
  if (character != nullptr && strlen(character) >= w1::charNum) {
    for (int i = 0; i < w1::charNum; i++) {
      str[i] = character[i];
      str[i + 1] = '\0';
    }
  } else {
    str[0] = '\0';
  }
}

//displays the results 
void w1::CString::display(std::ostream & res) const {
  res << str;
}

//this overloads the << operator and returns what should be displayed. 
std::ostream & w1::operator << (std::ostream & res,
  const CString & stri) {
  static int num = 0;
  res << num << ": ";
  stri.display(res);
  num++;
  return res;
}