/*
 * tests.cpp
 *
 *  Created on: May 4, 2018
 *      Author: takudzwamhonde
 */
#include "tests.hpp"
void test1(){
	  Queue<std::string> CoffeeShopList;
	  CoffeeShopList.enqueue("Jonathan Burt - Frapaccino (XL) & Apple Crumble");
	  CoffeeShopList.enqueue("Melissa Funck - Cafe Americano (M) & Chocolate Chip Cookie");
	  CoffeeShopList.enqueue("Tafadzwa Nhema - French Vanilla Latte (L)");
	  CoffeeShopList.enqueue("Frank Kunzwa - BC Kicker Special (R)");
	  CoffeeShopList.enqueue("Dav Example - Roiboos Tea Latte w Honey (XXL) & Carrot Muffin");

	  std::cout << "------------ Coffee Shop -----------" << std::endl;
	  while(!CoffeeShopList.empty())
	  {
	      std::cout << "Customers Left: " << CoffeeShopList.size() << std::endl;
	      std::cout << "Now serving : " << CoffeeShopList.front() << std::endl; CoffeeShopList.dequeue();
	      usleep(2000000);
	  }
}

void test2(){
	Queue<std::string> CoffeeShopList;
	try{
		  CoffeeShopList.dequeue();
	}catch(QueueEmpty& qe)
	{
		std::cout << qe.getmsg() << std::endl;
	}

	 // obtaining front on an empty queue
    try{
		  CoffeeShopList.front();
	}catch(QueueEmpty& qe)
	{
		  std::cout << qe.getmsg() << std::endl;
	}
}
