//============================================================================
// Name        : CLL.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "CLL.hpp"
#include "unistd.h"
#include <string>


int main() {
	CLL<std::string> playlist;
	playlist.add("Coldplay - Whisper - A Rush Of Blood To The Head");
  	playlist.add("Made In Japan - Free Spirit - Sights And Sounds");
	playlist.add("The Antlers - Putting The Dog To Sleep - Burst Apart");
	playlist.add("Local Natives -  Black Spot - Hummingbird");
	playlist.add("How To Dress Well - Words I Don't Remember - \"What Is This Heart?\"");
	int i = 10;
	while(i>0){
		std::cout << "Now Playing: " << playlist.front() << std::endl;
		playlist.advance();
		usleep(1500000);
		i--;
	}
	return 0;
}
