/** 
	Name: Pavan Kumar Kamra
	Course: BTP305
**/

#ifndef _Notifications_h_
#define _Notifications_h_
#include <iostream> 
#include <cstring>
#include <vector>
#include "Message.h"
#define msgDEFINE 10 

namespace w5
{
	class Notifications
	{
		private:
			std::vector<Message> M; 	   	
		public: 
			Notifications(); 
			Notifications(const Notifications&);
			Notifications& operator=(const Notifications&); 
			Notifications(Notifications&&); 
			Notifications&& operator=(Notifications&&);
			void operator+=(const Message& msg); 
			void display(std::ostream& os) const; 
	}; 
}
#endif 
