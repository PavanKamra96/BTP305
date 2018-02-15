/**
	Name: Pavan Kumar Kamra
	Course: BTP305
**/


#ifndef _Message_h_
#define _Message_h_ 
#include <iostream>
#include <vector> 
#include <cstring> 
#include <string> 
#include <fstream> 

namespace w5 {
	class Message
	{
		private: 
			std::string user_name; 
			std::string reply_name; 
			std::string tweet;
			std::string whole_Msg; 		
		public: 
			Message();
			Message(std::ifstream& in, char c); 
			bool empty() const; 
			void display(std::ostream&) const; 
	};
 }
#endif 
