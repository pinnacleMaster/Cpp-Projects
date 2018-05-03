/*
 * CaesarShifter.cpp
 *
 *  Created on: May 2, 2018
 *      Author: takudzwamhonde
 */
#include "CaesarShifter.hpp"
#include <iostream>
#include <string>
CaesarShifter::CaesarShifter(const std::string& s) :text(s) {}

CaesarShifter::CaesarShifter(const std::string& _text, const int& _shiftBy) : text(_text), shiftBy(_shiftBy) {}


void CaesarShifter::encrypt()
{
  shift(shiftBy);
}

void CaesarShifter::decrypt()
{
  shift(26-(shiftBy%26));
}
void CaesarShifter::shift(const int& sh)
{
	std::string shiftedText;
	char Alp[26] = {
						  'A','B','C','D','E','F','G','H','I','J','K','L',
						  'M','N','O','P','Q','R','S','T','U','V','W','X',
						  'Y','Z'
				   };

	int Int [10] = {'0','1','2','3','4','5','6','7','8','9'};
	/*  Convert to uppercase  */
	/*        Shift Here      */
	int c;
	for(int i=0;i<text.size();i++)
	{
		text[i] = std::toupper(text[i]);
		if(text[i] >= 'A' && text[i] <= 'Z')
		{

			c = abs((int(text[i]) - int('A')  + sh) % 26);
			shiftedText.push_back(Alp[c]);
		}
		else if(text[i] >= '0' && text[i] <= '9')
		{
			c = abs((int(text[i]) - int('0')  + sh) % 10);
			shiftedText.push_back(Int[c]);
		}
	}
	text = shiftedText;
}

std::string CaesarShifter::getText()
{
	return text;
}
