/** 
   Name:Pavan Kumar Kamra
   Course: BTP305
**/
#include "Station.h"

// default constructor - initialization list 
Station::Station(): station_Name(""), studen_Pass(0), adult_Pass(0) {};

// sets the object with the info recieved 
void Station::set(const std::string & Stat, unsigned Stud, unsigned Adu) {
  if (!Stat.empty()) {
    station_Name = Stat;
    studen_Pass = Stud;
    adult_Pass = Adu;
  } else { * this = Station();
  }

}

// updates ticket count. sold if negative, added if positive
void Station::update(PassType p, int pass) {
  if (p == Student) {
    if (pass > 0) {
      studen_Pass += (unsigned) pass;
    } else {
      int x = pass * -1;
      studen_Pass -= (unsigned) x;
    }
  } else if (p == Adult) {
    if (pass > 0) {
      adult_Pass += (unsigned) pass;
    } else {
      int y = pass * -1;
      adult_Pass -= (unsigned) y;
    }

  }

}

// returns the number of passes depending on if its Student or Adult
unsigned Station::inStock(PassType pa) const {
  if (pa == Student) {
    return studen_Pass;
  } else if (pa == Adult) {
    return adult_Pass;
  } else {
    return 0;
  }
}

// returns station name 
const std::string & Station::getName() const {
  return (station_Name);
}
