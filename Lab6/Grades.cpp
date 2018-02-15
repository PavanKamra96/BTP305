 /**
    Name: Pavan Kumar Kamra
    Course: BTP305
**/

#include "Grades.h"
#include <iomanip> 

Grades::Grades() {
  Grade = nullptr;
  studentID = nullptr;
  recordsNum = 0;
}

Grades::Grades(const char * fileName) {
  std::ifstream fileN(fileName);

  if (!fileN) {
    throw "File did not open. Error~";
  }
  int record;
  std::string dummy;
  while (std::getline(fileN, dummy)) {
    ++record;
  }
  recordsNum = record;
  fileN.clear();
  fileN.seekg(std::ios::beg);
  studentID = new long[recordsNum];
  Grade = new float[recordsNum];

  for (int i = 0; i < recordsNum; i++) {
    fileN >> studentID[i];
    fileN >> Grade[i];
  }

  fileN.close();

}

void Grades::displayGrades(std::ostream & os, std:: function < std::string(float) > GradeLetter) const {
  for (int x = 0; x < recordsNum; x++) {
    os << studentID[x];
    os << " " << std::fixed << std::setprecision(2) << Grade[x];
    os << " " << GradeLetter(Grade[x]) << std::endl;
  }
}

Grades::~Grades() {
  if (Grade != nullptr) {
    delete[] Grade;
    Grade = nullptr;
  }
  if (studentID != nullptr) {
    delete[] studentID;
    studentID = nullptr;
  }
}