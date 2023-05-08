#include "utility.h"
#include "cell.h"
#include "field.h"
Field::Field(){
	sizeX = 100;
	sizeY = 300;
	cellField = new Cell*[sizeX];
	for (int i = 0; i < sizeX; ++i) {
		cellField[i] = new Cell[sizeY];
	}
}
Field::Field(int x, int y){
	sizeX = x;
	sizeY = y;
	cellField = new Cell*[sizeX];
	for (int i = 0; i < sizeX; ++i) {
		cellField[i] = new Cell[sizeY];
	}
}
Field::~Field(){
	for(int i=0;i<sizeX; i++){
		delete [] cellField[i];
	}
	delete [] cellField;
}
void Field::update(){
	bool newState = false;
	for(int i = 0; i<sizeX; i++){
		for(int j = 0; j<sizeY; j++){
			newState = defineNewState(i, j);	
			cellField[i][j].setFutureState(newState);
		}
	}
	for(int i = 0; i<sizeX; i++){
		for(int j = 0; j<sizeY; j++){
			cellField[i][j].updateState();

		}
	}
}
bool Field::defineNewState(int x, int y){
	bool newState = false;	
	int livingNeighbours = 0;
	for(int i =x-1; i<=x+1;i++){
		for(int j =y-1; j<=y+1;j++){
			livingNeighbours += cellField[mod(i,sizeX)][mod(j,sizeY)].isAlive();

		}
	}
	
	if(cellField[x][y].isAlive() == false){
		if(livingNeighbours == 3){
			newState = true;
		}
	}
	if(cellField[x][y].isAlive() == true){
		livingNeighbours--;
		if(livingNeighbours < 2 || livingNeighbours > 3){
			newState = false;
		}
		else {
			newState = true;
		}
	}
	return newState;
}
