/**
	Name: Pavan Kamra
    Course: BTP305
**/
#include "Stations.h"
#include <fstream> 
#include <iomanip>
	
	// constructor that inputs from Stations.dat file. 
	w2::Stations::Stations(const char* name)
	{
		if (name != nullptr) 
		{
			std::ifstream data(name); 
			if (data.is_open())
			{
				if(data.good())
				{
				    data >> amount_Of_Stations >> delimiter;
				    stat = new Station[4];
				    std::string stat_Name; 
				    unsigned int student_Passes, adult_Passes;  
				    for (int i = 0; i < amount_Of_Stations; i++)
				    {
				    	getline(data,stat_Name, delimiter); 
					data >> student_Passes >> adult_Passes; 
					stat[i].set(stat_Name, student_Passes, adult_Passes);  
				    } 	
		
				}
			}
			data.close(); 
		}
	}

	// this method is used to update the Student / Adult passes sold. 
	void w2::Stations::update() const 
	{
		int student_Passes, adult_Passes; 	 
		std::cout << "\nPasses Sold :"; 
		std::cout << "\n--------------";
		for (int i = 0; i < amount_Of_Stations; i++)
		{
			std::cout << stat[i].getName() << std::endl;

			std::cout <<  " Student Passes sold : "; 
			std::cin >> student_Passes; 
			stat[i].update(Student, -student_Passes);
 
			std::cout <<  " Adult   Passes sold : ";
			std::cin >> adult_Passes; 
			stat[i].update(Adult, -adult_Passes);		
		}
	}

	// this method is used to update the Student/Adult passes added 
	void w2::Stations::restock() const
	{
		int stu_Passes, adu_Passes; 
		std::cout << "\nPasses Added :" ; 
		std::cout << "\n---------------";
		for(int i =0; i < amount_Of_Stations; i++)
		{
			std::cout << stat[i].getName() << std::endl;
 
			std::cout << " Student Passes added : "; 
			std::cin >> stu_Passes;
			stat[i].update(Student, stu_Passes);
 
			std::cout << " Adult   Passes added : "; 
			std::cin >> adu_Passes; 
			stat[i].update(Adult, adu_Passes); 
		}
	}

	// this method gives the final report on the tickets. 
	void w2::Stations::report() const
	{
		std::cout << "\nPasses in Stock : Student Adult" << std::endl; 
		std::cout << "-------------------------------" << std::endl; 
		for (int i=0; i< amount_Of_Stations; i++) 
		{   
		std::cout.setf(std::ios::left);
		std::cout.width(15);
		std::cout << stat[i].getName(); 
		std::cout.unsetf(std::ios::left); 
		std::cout.width(10); 
		std::cout << stat[i].inStock(Student); 
		std::cout.width(6); 
		std::cout << stat[i].inStock(Adult);
		}
		std::cout << "\n"; 
	}
	
	// Destructor that updates the Stations.dat file with the new information and deallocates dynamic space. 
	 w2::Stations::~Stations() 
	{
		std::ofstream outData("Stations.dat");
		if (outData.is_open())
		{
			outData << amount_Of_Stations << delimiter;
			for (int i=0; i < amount_Of_Stations; i++)
			{
				outData << stat[i].getName() << delimiter << stat[i].inStock(Student) << " " << stat[i].inStock(Adult); 
			}
		}
			outData.close(); 
			delete [] stat; 
	} 
	