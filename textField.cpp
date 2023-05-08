#include <iostream>
#include <time.h>
#include <stdio.h>
#include "textField.h"
TextField::TextField(int x, int y) : Field::Field(x, y) {}
TextField::TextField(int x, int y, const char* filename) : Field::Field(x, y) {
	const char* nameOfFile;
	nameOfFile = filename;
	FILE *inFile;
	inFile = fopen(nameOfFile, "r");	
	while(!inFile){
		inFile = fopen(nameOfFile, "r");	
		if(!inFile){
			std::cout << "Can't open the file '"<< nameOfFile << "'. Enter correct filename:" << std::endl;
			char newFilename[50];
			std::cin >> newFilename;
			nameOfFile = newFilename;
		}
	}
	char c = 0;
	int i = 0, j = 0;
	while((c = fgetc(inFile)) != EOF){

		if(i>=sizeX-1){
			i=0;
		}
		if(j>=sizeY-1){
			j=0;
		}
		switch(c){
			case 32:
				cellField[i][j].setCurrentState(false);
				j++;
				break;
			case 10:
				i++;
				j = 0;
				break;
			default:
				cellField[i][j].setCurrentState(true);
				j++;
				break;
		}

	}
	fclose(inFile);
}
void TextField::show(){
	for (int i = 0; i < sizeX; ++i) {
		for (int j = 0; j < sizeY; ++j){
			bool state = cellField[i][j].isAlive();
			if(state){
				std::cout << "o";
			} else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}
// inf for Infinity. The game never ends (while(true)).
void TextField::infPlay(int updateSec){
	time_t start, now;
	start = time(0);
	while(true){
		now = time(0);
		if( (now-start) == updateSec){
			show();
			update();
			start=time(0);
		}

	}
}
TextField::~TextField(){}
