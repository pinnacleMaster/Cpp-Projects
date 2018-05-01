#include <iostream>
#include "TowerOfHanoi"
#include <vector>

int main(){

	TowerOfHanoi Tower1(1);
	vector<string> moves1 = Tower1.generateSolution();
	for (auto move: moves1)
		cout << move << endl;
	cout << "There are " << moves1.size() << " moves to make to solve this." << endl;

	TowerOfHanoi Tower2(3,'B', 'A');
	vector<string> moves2 = Tower2.generateSolution();
	for (auto move: moves2)
		cout << move << endl;
	cout << "There are " << moves2.size() << " moves to make to solve this." << endl;
	
}