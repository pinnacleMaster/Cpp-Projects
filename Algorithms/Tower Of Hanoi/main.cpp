#include <iostream>
#include "TowerOfHanoi.hpp"
#include <vector>

int main(){

	TowerOfHanoi Tower1(1);
	std::vector<std::string> moves1 = Tower1.generateSolution();
	for (auto move: moves1)
		std::cout << move << std::endl;
	std::cout << "There are " << moves1.size() << " moves to make to solve this." << std::endl;

	TowerOfHanoi Tower2(3,'B', 'A');
	std::vector<std::string> moves2 = Tower2.generateSolution();
	for (auto move: moves2)
		std::cout << move << std::endl;
	std::cout << "There are " << moves2.size() << " moves to make to solve this." << std::endl;
	
}