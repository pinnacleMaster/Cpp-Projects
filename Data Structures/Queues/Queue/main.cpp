//============================================================================
// Name        : main.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "tests.hpp"

int main(){
	std::cout << "Testing general queue methods: " << std::endl;
	test1();
	std::cout << "Testing exception handling of queue methods: " << std::endl;
	test2();

  return 0;
}
