#include "TowerOfHanoi"
TowerOfHanoi::TowerOfHanoi(){
	numberOfDisks = 0;
	startPos = 'A';
	endPos = 'C';
}

TowerOfHanoi::TowerOfHanoi(const int& n){
	numberOfDisks = n;
	startPos = 'A';
	endPos = 'C';
}

TowerOfHanoi::TowerOfHanoi(const int& n, const char& _startPos, const char& _endPos){
	numberOfDisks = n;
	startPos = _startPos;
	endPos = _endPos;
}

std::vector<std::string> TowerOfHanoi::generateSolution()
{
	solve(numberOfDisks,startPos, endPos);
	return moves;
}

void TowerOfHanoi::solve(const int& n, const char& currPeg,const char& toPeg){

	if(n<=0){
		return;
	}
	else
	{
		char nextPeg = remove(currPeg, toPeg); // "ABC" - could be a string
		if(n == 1){
			move(1, toPeg);
			return;
		}
		else
		{
			solve(n-1, currPeg, nextPeg); // * I dont know what currPeg msut be
			move(n, toPeg);
			solve(n-1, nextPeg, toPeg);
		}

	}
}

void TowerOfHanoi::move(const int& pegNum, const char& toPeg){
	std::string c = std::to_string(pegNum);
	std::string s = "Move tile " + c + " to peg ";
	s.push_back(toPeg);
	moves.push_back(s);
}

char TowerOfHanoi::remove(const char& peg1, const char& peg2){
	char peg;
	if ((peg1 == 'A' && peg2 == 'B') || (peg1 == 'B' && peg2 == 'A')) { peg = 'C';}
	else if ((peg1 == 'A' && peg2 == 'C')  || (peg1 == 'C' && peg2 == 'A')) { peg = 'B';}
	else if ((peg1 == 'B' && peg2 == 'C') || (peg1 == 'C' && peg2 == 'B')) { peg = 'A';}
	return peg;
}










