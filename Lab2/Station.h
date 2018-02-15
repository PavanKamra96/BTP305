/**
   Name: Pavan Kumar Kamra
   Course: BTP305
**/

#ifndef _STATION_H_
#define _STATION_H_
#include <iostream>
#include <cstring> 
#include <string>

	enum PassType {Student, Adult}; 
	class Station 
	{
		private:
		    std::string station_Name;  
			unsigned int studen_Pass;
			unsigned int adult_Pass; 		 
		public: 
			Station(); 
			void set(const std::string&, unsigned, unsigned);
			void update(PassType, int);
			unsigned inStock(PassType) const; 
			const std::string& getName() const; 
	};
#endif 
