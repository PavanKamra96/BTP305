/**
   Name: Pavan Kumar Kamra
   Course: BTP305
**/ 

#ifndef _STATIONS_H_
#define _STATIONS_H_
#include <iostream> 
#include <cstring>
#include "Station.h"

	namespace w2 
	{
		class Stations 
		{
			private: 
			Station *stat; 
			char delimiter;
			int amount_Of_Stations;
    
			public: 
			 Stations(const char*);
			 ~Stations(); 	
			 void update() const; 
 			 void restock() const; 
			 void report() const; 
		}; 
	}
#endif 
