/** 
	Name: Pavan Kumar Kamra
	Date: 9/29/2015
	Course: BTP305
	Purpose: The Header file for Text.cpp.
**/

#ifndef _TEXT_H_
#define _TEXT_H_
#include <iostream>
#include <cstring>
#include <string>

	namespace w3 
	{
		class Text 
		{
			private:
				std::string* T;  
				size_t records; 
			public: 
				Text(); 
				Text(std::string const&); 
				Text(const Text&); // copy constructor  
				Text& operator=(const Text&); // copy assignment operator 
				Text(Text&&); // move constructor 
				Text&& operator=(Text&&); // move assignment operator 
				~Text(); // destructor
				size_t size() const; // member function that returns the number of records of text data. 
		};
	}
#endif
