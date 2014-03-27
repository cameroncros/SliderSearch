/*
 * BoardGenerator.cpp
 *
 *  Created on: Mar 26, 2014
 *      Author: cameron
 */

#include "BoardGenerator.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>


BoardGenerator::BoardGenerator(char* fname, char* w, char* h,
		char* numberOfMoves) {
	sscanf(w, "%i", &width);
	sscanf(h, "%i", &height);
	sscanf(numberOfMoves, "%i", &numMoves);
	filename = fname;
	initialState = new state;

	initialState->board = new int*[height];
	for (int i=0; i < height; i++) {
		initialState->board[i] = new int[width];
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			initialState->board[i][j]=i*width+j;
		}
	}
	initialState->cost=0;
	initialState->depth=0;
	initialState->parent=NULL;


}

BoardGenerator::~BoardGenerator() {
	// TODO Auto-generated destructor stub
}

void BoardGenerator::run() {
	state *nextState= NULL;
	state *currentState=initialState;
	move mv;
	for (int i=0; i< numMoves; i++) {
		while (nextState == NULL) {
			int value = rand()%4;
			switch (value) {
			case 0:
				mv=UP;
				break;
			case 1:
				mv=DOWN;
				break;
			case 2:
				mv=LEFT;
				break;
			case 3:
				mv=RIGHT;
				break;
			}
			nextState=getNextState(currentState, mv);
		}
		deleteState(currentState);
		currentState=nextState;
		nextState=NULL;
	}
	deleteState(currentState);

}


void BoardGenerator::print() {
	std::cout << width << std::endl
			<< height << std::endl
			<< initialState->fingerprint <<std::endl
			<< finalState->fingerprint << std::endl;
}
