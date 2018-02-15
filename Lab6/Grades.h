/**
	Name: Pavan Kumar Kamra
	Course: BTP305 
**/

#ifndef _Grades_h_
#define _Grades_h_
#include <iostream> 
#include <string> 
#include <fstream> 
#include <functional>

class Grades {
	private:
		long* studentID;
		float* Grade;
		int recordsNum;  
			
	public:
		Grades();
		~Grades();
		Grades(const char*);  
		void displayGrades(std::ostream&, std::function<std::string(float)>) const; 
};
#endif 	
