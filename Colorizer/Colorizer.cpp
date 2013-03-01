// Colorizer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <windows.h>
#include <regex>

#define BUF_SIZE 10240

using namespace std;

string upperCase(string input) {
  for (string::iterator it = input.begin(); it != input.end(); ++ it)
    *it = toupper(*it);
  return input;
}

void outputLine(char pch[]) {
	
	string str = upperCase(string(pch));
	string regError = "ERROR";
	string regExcpetion = "EXCEPTION";
	string regWarning = "WARNING";
	string regMarpiec = "AT PL.MARPIEC.";
				
	if(str.find(regError) != string::npos || str.find(regExcpetion) != string::npos) {
		cout << "\33[1;31m" << pch << "\33[0m";
	} else if(str.find(regWarning) != string::npos) {
		cout << "\33[33m" << pch << "\33[0m";
	} else if(str.find(regMarpiec) != string::npos) {
		cout << "\33[1;34m" << pch << "\33[0m";
	} else {
		cout << pch;
	}
				
	cout.flush();
}

int _tmain(int argc, _TCHAR* argv[])
{

	string something;
	char ch;
	char buf[BUF_SIZE];
	char pch[BUF_SIZE];
	bool first;
	streamsize count;
	int lineCharCounter = 0;

	while(!cin.eof()) {
		ch = cin.peek();
		if(ch != -1) {
			count = cin.readsome(buf, BUF_SIZE);
			if(count > 0) {
				buf[count] = '\0';
				int bufferCounter = 0;

				char bufChar;
				while (bufferCounter < count) {
					do {
						bufChar = buf[bufferCounter];
						pch[lineCharCounter] = bufChar;

						lineCharCounter++;
						bufferCounter++;
					} while(bufChar != '\n' && bufferCounter < count);
					pch[lineCharCounter] = '\0';
					lineCharCounter = 0;
					outputLine(pch);
				}
			}
		} else {
			Sleep(20);
		}
	}
	
	return 0;
}
