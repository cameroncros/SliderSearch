/*
 * BoardGenerator.cpp
 *
 *  Created on: Mar 26, 2014
 *      Author: cameron
 */
#define _CRT_SECURE_NO_WARNINGS

#include "BoardGenerator.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>


BoardGenerator::BoardGenerator(char* fname, char* w, char* h,
		char* numberOfMoves) {
	sscanf(w, "%i", &width);
	sscanf(h, "%i", &height);
	sscanf(numberOfMoves, "%i", &numMoves);
	filename = fname;
	initialState = new state;

	initialState->board = new char*[height];
	for (int i=0; i < height; i++) {
		initialState->board[i] = new char[width];
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			initialState->board[i][j]=i*width+j;
		}
	}
	initialState->cost=0;
	initialState->depth=0;
	initialState->parent=NULL;
	fingerprintState(initialState);

	//needed to avoid 
	finalState = new state;

	finalState->board = new char*[height];
	for (int i = 0; i < height; i++) {
		finalState->board[i] = new char[width];
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			finalState->board[i][j] = i*width + j;
		}
	}
	finalState->cost = 0;
	finalState->depth = 0;
	finalState->parent = NULL;
	fingerprintState(finalState);
	srand((int)time(NULL));
}

BoardGenerator::~BoardGenerator() {
	// TODO Auto-generated destructor stub
}

void BoardGenerator::run() {
	state *nextState= NULL;
	state *currentState = new state;
	currentState->board = new char*[height];
	for (int i = 0; i < height; i++) {
		currentState->board[i] = new char[width];
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			currentState->board[i][j] = i*width + j;
		}
	}
	currentState->cost = 0;
	currentState->depth = 0;
	currentState->parent = NULL;

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
		nextState = NULL;
	}
	deleteState(finalState);
	finalState = currentState;
}


void BoardGenerator::print() {
	std::cout << width << std::endl
			<< height << std::endl
			<< initialState->finger.finger <<std::endl
			<< finalState->finger.finger << std::endl <<std::endl;

	std::fstream file;
	file.open(filename, std::fstream::out);

	file << width << std::endl
		<< height << std::endl
		<< initialState->finger.finger << std::endl
		<< finalState->finger.finger;
	file.close();


	prettyPrintState(initialState);
	prettyPrintState(finalState);
}
