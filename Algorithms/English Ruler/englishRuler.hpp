#include <iostream>

void drawOneTick(const int& tickLength, const int& tickLabel=-1)
{
	for(int i=0; i< tickLength; i++)
		std::cout << "-";
	if (tickLabel > 0) std::cout << " " << tickLabel;
	std::cout << std::endl;
}
void drawTicks(const int& tickLength)
{
	if(tickLength > 0){
		drawTicks(tickLength-1);
		drawOneTick(tickLength);
		drawTicks(tickLength-1);
	}
}
void drawRuler(const int& nInches, const int& majorLength)
{
	drawOneTick(majorLength, 0);
	for(int i=0;i<nInches;i++){
		drawTicks(majorLength-1);
		drawOneTick(majorLength,i);
	}
}