// Workshop 6-Lambda Expression
// w6.cpp
#include <iostream>
#include "Grades.h"
#include <string>	
#include <cmath>
#include <functional>
int main(int argc, char* argv[]) 
	{
	if (argc != 2) {
		std::cerr << argv[0] <<": incorrect number of arguments\n";
		std::cerr << "Usage: " << argv[0] << "file_name\n";
		return 1;
	}

	std::function<std::string(float)> letter = [] (float f) -> std::string {
	
		int Grade = f; 
        
       		 if (Grade >= 90 && Grade <= 100) 
		{
        	    return "A+";
        	} 
		else if (Grade >= 80 && Grade <= 89) 
		{
            		return "A";
        	} 
		else if (Grade >= 75 && Grade <= 79) 
		{
            		return "B+";
        	} 
		else if (Grade >= 70 && Grade <= 74) 
		{
            		return "B";
        	} 
		else if (Grade >= 65 && Grade <= 69) 
		{
            		return "C+";
        	} 
		else if (Grade >= 60 && Grade <= 64) 
		{
            		return "C";
        	} 
		else if (Grade >= 55 && Grade <= 59) 
		{
            		return "D+";
        	} 
		else if (Grade >=50 && Grade <= 54) 
		{
            		return "D";
        	} 
		else 
		{
            		return "F";
        	}
    	};
	
	try 
	{
       		Grades grades(argv[1]);
        	grades.displayGrades(std::cout, letter);
    	} 
	catch (const char* m) 
	{
        	std::cout << m << std::endl;
        	return 1;
    	}
    		std::cout << "Press any key to continue ... ";
		std::cin.get();
}
