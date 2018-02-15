/** 
	Name: Pavan Kumar Kamra
	Course: BTP305
**/
#include "Notifications.h"

//Default Constructor
w5::Notifications::Notifications(): M() {}

//Copy Constructor 
w5::Notifications::Notifications(const Notifications & src) {
  for (int i = 0; i < M.size(); i++) {
    M[i] = src.M[i];
  }
}

//Copy Assignment operator 
w5::Notifications & w5::Notifications::operator = (const Notifications & src) {
  if (this != & src) {

    for (int i = 0; i < M.size(); i++) {
      M[i] = src.M[i];
    }
  }
  return *this;
}

//Move constructor
w5::Notifications::Notifications(Notifications && src) {
  M = std::move(src.M);
}

//Move assignment operator
w5::Notifications && w5::Notifications::operator = (Notifications && src) {
  if (this != & src) {
    M = std::move(src.M);
  }
  return std::move( * this);
}

//Adds msgs to the set
void w5::Notifications::operator += (const Message & msg) {
  if (M.size() < 10) {
    M.push_back(msg);
  }
}

//Inserts the Message objects to the os output stream. 
void w5::Notifications::display(std::ostream & os) const {
  for (int i = 0; i < M.size(); i++) {
    M[i].display(os);
  }
}
