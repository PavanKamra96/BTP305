/**
	Name: Pavan Kumar Kamra
	Course: BTP305
**/
#ifndef _DATATABLE_H_
#define _DATATABLE_H_

#include <iostream>
#include <fstream> 
#include <math.h> 
#include <vector>
#include <iomanip>
#include <algorithm> 
#include <functional> 

namespace w8 {
  template < typename T >
    class DataTable {
      private:
        std::vector < T > xcord; //vector for the x-coordinate
      std::vector < T > ycord; //vector for the y-coordinate
      int field_width; //field_width for the display
      int precision_Value; //precision value for the display. 

      public:
        // Default Constructor
        DataTable(): field_width(0), precision_Value(0) {}

      // Overload Constructor - inputs filename, Field Width, & Precision. 
      DataTable(std::ifstream & file, int FW, int PV) {
        field_width = FW;
        precision_Value = PV;
        while (!file.eof()) {
          if (file.good()) {
            T x, y;
            file >> x >> y;
            if (file.good()) {
              xcord.push_back(x);
              ycord.push_back(y);
            }
          }
        }
      }

      // Calculate & returns the Mean. 
      T mean() const {
        T mean, Total;
        Total = std::accumulate(ycord.begin(), ycord.end(), (T) 0);
        mean = Total / ycord.size();
        return mean;
      }

      // Calculates & returns the standard deviation 
      T sigma() const {
        T deviation, Total;
        T avg = mean();
        Total = std::accumulate(ycord.begin(), ycord.end(), (T) 0, [ = ](T Total, T current) {
          Total += std::pow(current - avg, 2);
          return Total;
        });
        deviation = Total / (ycord.size() - 1);
        deviation = std::sqrt(deviation);
        return deviation;
      }

      //Calculates & returns the mean of the dependent coordinates. 
      T median() const {
        std::vector < T > y = ycord;
        std::sort(y.begin(), y.end());
        return y[std::round(y.size() / 2.0)];
      }

      //This calculates the slope & y_intercept by reference
      void regression(T & slope, T & y_intercept) const {
        T part1, part2, part3;
        part1 = (std::inner_product(xcord.begin(), xcord.end(), ycord.begin(), (T) 0)) * xcord.size();
        part1 = part1 - (std::accumulate(xcord.begin(), xcord.end(), (T) 0) * std::accumulate(ycord.begin(), ycord.end(), (T) 0));
        part2 = xcord.size() * (std::accumulate(xcord.begin(), xcord.end(), (T) 0, [](T part2, T current) {
          part2 += std::pow(current, 2);
          return part2;
        }));
        part2 = part2 - (std::pow(std::accumulate(xcord.begin(), xcord.end(), (T) 0), 2));
        slope = part1 / part2;
        y_intercept = (std::accumulate(ycord.begin(), ycord.end(), (T) 0)) - (slope * std::accumulate(xcord.begin(), xcord.end(), (T) 0));
        y_intercept = y_intercept / xcord.size();
      }

      //displays the x and y Data Values
      void display(std::ostream & os) const {
        //os << "Data Values" << std::endl; 
        //os << "============" << std::endl; 
        os << std::setw(field_width) << "x" << std::setw(field_width) << "y" << std::endl;
        for (int i = 0; i < xcord.size(); i++) {
          os << std::setw(field_width) << std::fixed << std::setprecision(precision_Value) << xcord[i];
          os << std::setw(field_width) << std::fixed << std::setprecision(precision_Value) << ycord[i] << std::endl;
        }

      }

      ~DataTable() {
        xcord.clear();
        ycord.clear();
      }
    };
  template < typename T >
    // the << operator uploaded. 
    std::ostream & operator << (std::ostream & os,
      const DataTable < T > & st) {
      st.display(os);
      return os;
    }
}
#endif
