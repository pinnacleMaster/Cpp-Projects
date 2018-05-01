#ifndef TOWER_OF_HANOI
#define TOWER_OF_HANOI

#include <vector>

class TowerOfHanoi {
public:
	TowerOfHanoi();
	TowerOfHanoi(const int& n); // parametric intiaizer - sets number of disks to n
	TowerOfHanoi(const int& n, const char& startPos, const char& endPos);

	std::vector<std::string> generateSolution();

private:
	void solve(const int& n, const char& currPeg,const char& toPeg);
	void move(const int& pegNum, const char& toPeg);
	char remove(const char& peg1, const char& peg2);

private:
	int numberOfDisks;
	char startPos, endPos;
	std::vector<std::string> moves;
};

#endif