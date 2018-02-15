	/** 
	Name: Pavan Kumar Kamra
	Course: BTP305 
	**/

#include "Message.h"
	
//Default Constructor
w5::Message::Message() {
  user_name = "";
  reply_name = "";
  tweet = "";
}

//Overloaded Constructor that takes file input 
w5::Message::Message(std::ifstream & in , char c) {
  if ( in .good()) {
    getline( in , whole_Msg, c);
    std::string delimiter = " ";
    if (whole_Msg.find(delimiter) != std::string::npos) {
      user_name = whole_Msg.substr(0, whole_Msg.find(delimiter));
      whole_Msg = whole_Msg.erase(0, whole_Msg.find(delimiter) + 1);
      if (whole_Msg.at(0) != '@') {
        tweet = whole_Msg;
      } else {
        reply_name = whole_Msg.substr(1, whole_Msg.find(delimiter));
        tweet = whole_Msg.substr(whole_Msg.find(delimiter) + 1);
      }
    }

  }
}

// Member Function that checks if the private variables are empty. 
bool w5::Message::empty() const {
  return (user_name.empty() && reply_name.empty() && tweet.empty());
}

// Display Function!
void w5::Message::display(std::ostream & os) const {
  os << "Message \n";
  os << "User : " << user_name << "\n";

  if (!reply_name.empty()) {
    os << "Reply : " << reply_name << "\n";
  }

  os << "Tweet : " << tweet << "\n\n";
}