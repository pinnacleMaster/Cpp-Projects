#ifndef TOWER_OF_HANOI
#define TOWER_OF_HANOI

#include <vector>

class TowerOfHanoi {
public:
	TowerOfHanoi();
	TowerOfHanoi(const int& n); // sets number of disks to n.
	TowerOfHanoi(const int& n, const char& _startPeg, const char& _endPeg);// sets number of disks to n, start peg to startPeg & target peg to endPeg.
	std::vector<std::string> generateSolution(); // returns a vector of strings, instructing the user how the pegs must be moved to solve the puzzle.

private:
	void solve(const int& n, const char& currPeg,const char& toPeg); // solves the puzzle
	void move(const int& diskNum, const char& toPeg); // pushes a string into the moves vector :- "move disk [diskNum] to [toPeg]." 
	char remove(const char& peg1, const char& peg2); // returns C = {A,B,B} - peg1 U peg2, where U is the set union method.

private:
	int numberOfDisks; // number of pegs on starting disks.
	char startPeg, endPeg; // starting peg and target peg.
	std::vector<std::string> moves; // moves to be made by the user. 
};

#endif