#include <iostream>
#include "TowerOfHanoi.hpp"
#include <vector>

int main(){
	int n; std::cout << "The number of disks: "; std::cin >> n;
	TowerOfHanoi Tower1(n);
	std::vector<std::string> moves1 = Tower1.generateSolution();
	for (auto move: moves1)
		std::cout << move << std::endl;
	std::cout << "There are " << moves1.size() << " moves to make to solve this." << std::endl;

	return 0;
	
}