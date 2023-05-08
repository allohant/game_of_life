#include "cell.h"
Cell::Cell(){
	currentState = false;
	futureState = false;
}
Cell::Cell(bool state){
	currentState = state;
	futureState = false;
}
Cell::~Cell(){}
void Cell::setCurrentState(bool state){
	currentState = state;
}
void Cell::setFutureState(bool state){
	futureState = state;
}
void Cell::updateState(){
	currentState = futureState;
}
bool Cell::isAlive(){
	return currentState;
}
