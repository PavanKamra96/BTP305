/*
	Name: Pavan Kumar Kamra
	Date: 2015-09-30
	Course: BTP305
	Purpose: The class member files for Text class. 
*/

#include "Text.h"
#include <string>
#include <fstream> 

	// Default constructor
w3::Text::Text() {
  T = nullptr;
  records = 0;
}

// one argument constructor that reads the file
w3::Text::Text(const std::string & name) {
  if (!name.empty()) {
    std::ifstream text(name);
    if (text.is_open()) {
      if (text.good() && !text.eof()) {
        std::string dummy;
        records = 0;
        while (std::getline(text, dummy)) {
          ++records;
        }

        text.clear();
        text.seekg(std::ios::beg);
        if (text.good()) {
          T = new std::string[records];
          for (int i = 0; i < records; i++) {
            std::getline(text, T[i]);
          }
        }
      }
    }
    text.close();
  }
}

// copy constructor
w3::Text::Text(const Text & src) {
  records = src.records;

  T = new std::string[records];
  for (int i = 0; i < records; i++) {
    T[i] = src.T[i];
  }
}

// copy assignment operator
w3::Text & w3::Text::operator = (const Text & src) {
  if (this != & src) {
    records = src.records;

    if (T != nullptr) {
      delete[] T;
      T = nullptr;
    }

    T = new std::string[records];
    for (int i = 0; i < records; i++) {
      T[i] = src.T[i];
    }
  }
  return *this;
}

//move constructor
w3::Text::Text(Text && src) {
  records = src.records;
  T = src.T;
  src.records = 0;
  src.T = nullptr;
}

// move assignment operator
w3::Text && w3::Text::operator = (Text && src) {
  if (this != & src) {
    records = src.records;

    if (T != nullptr) {
      M = nullptr;
    }
    delete[] T;
    T = nullptr;
  }

  if (src.T != nullptr) {
    records = src.records;
    T = src.T;
    src.records = 0;
    src.T = nullptr;
  }

}
return std::move( * this);
}

// destructor
w3::Text::~Text() {
  if (T != nullptr) {
    delete[] T;
  }
}

// member function that returns the number
size_t w3::Text::size() const {
  return records;
}