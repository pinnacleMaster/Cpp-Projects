//============================================================================
// Name        : test_caesar_shift.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
// Notes       : Needs error handling for incorrect inputs by user
//============================================================================

#include <iostream>
#include "CaesarShifter.hpp"
#include <string>
using namespace std;

void print(std::string text, int f, int l)
{
  for(int i=f;i<l;i++)
  {
    if(i>=text.size())
      std::cout << " ";
    else
      std::cout << text[i];
  }
}

bool mainWin(int opt) {
	std::string text;
	int sh;
	  std::cout << "##################### CAESAR SHIFT ####################" << std::endl;
	  std::cout << "#                                                     #" << std::endl;
	  std::cout << "#    Information: Enter a text and a shift number.    #" << std::endl;
	  std::cout << "#           Text: "; getline(std::cin, text);
	  std::cout << "#       Shift By: "; std::cin >>sh;
	  std::cout << "#                                                     #" << std::endl;
	  std::cout << "#######################################################" << std::endl;
	  std::cout << std::endl; CaesarShifter CS(text, sh);
	  int start = 0;
	  if(opt == 1)
	  {
	  CS.encrypt();
	  text = CS.getText();
	  std::cout << "################## Encrypted Message  #################" << std::endl;
	  std::cout << "#                                                     #" << std::endl;
	    while(start<text.size())
	      {
	      std::cout << "# ";    print(text, start, start+51);   std::cout <<" #" << std::endl;
	      start+=51;
	      }

	  std::cout << "#                                                     #" << std::endl;
	  std::cout << "#######################################################" << std::endl;
	  }
	  else if(opt ==2)
	  {
		CS.decrypt();
		text = CS.getText();
	    std::cout << "################## Decrypted Message  #################" << std::endl;
	    std::cout << "#                                                     #" << std::endl;
	      while(start<text.size())
	        {
	        std::cout << "# ";    print(text, start, start+51);   std::cout <<" #" << std::endl;
	        start+=51;
	        }
	  std::cout << "#                                                     #" << std::endl;
	  std::cout << "#######################################################" << std::endl;
	  }
	  int optReturn;
	  if(opt == 1)
	  std::cout << "################ CAESAR SHIFT >> Encrypt ##############" << std::endl;
	  else
	  std::cout << "################ CAESAR SHIFT >> Decrypt ##############" << std::endl;
	  std::cout << "#                                                     #" << std::endl;
	  std::cout << "#                     1. Main Menu.                   #" << std::endl;
	  std::cout << "#                     2. Quit.                        #" << std::endl;
	  std::cout << "#                                                     #" << std::endl;
	  std::cout << "#######################################################" << std::endl;
	  std::cout << "######################### Option ######################" << std::endl;
	  std::cout << "#                                                     #" << std::endl;
	  std::cout << "#                 User option: ";  std::cin>>optReturn;
	  std::cout << "#                                                     #" << std::endl;
	  std::cout << "#######################################################" << std::endl;
	  std::cout << std::endl;

	  if(optReturn == 1)
		  return false;
	  else
		  return true;
}
int main() {
	int opt = -1;
	while(1)
	{
	  std::cout << "################# CAESAR SHIFT >> Menu ################" << std::endl;
	  std::cout << "#                                                     #" << std::endl;
	  std::cout << "#                     1. Encrypt                      #" << std::endl;
	  std::cout << "#                     2. Decrypt                      #" << std::endl;
	  std::cout << "#                     3. Quit                         #" << std::endl;
	  std::cout << "#                                                     #" << std::endl;
	  std::cout << "#######################################################" << std::endl;
	  std::cout << "################ CAESAR SHIFT - Option  ###############" << std::endl;
	  std::cout << "#                                                     #" << std::endl;
	  std::cout << "#                 User option: ";  std::cin>>opt;
	  std::cout << "#                                                     #" << std::endl;
	  std::cout << "#######################################################" << std::endl << endl;
	  cin.ignore();
	  if(opt == 3)
		  break;
	  if(mainWin(opt))
		  break;

	}

	  std::cout << "#######################################################" << std::endl;
	  std::cout << "#                                                     #" << std::endl;
	  std::cout << "#                   Now Closing...                    #" << std::endl;
	  std::cout << "#                                                     #" << std::endl;
	  std::cout << "#######################################################" << std::endl;

	return 0;
}
