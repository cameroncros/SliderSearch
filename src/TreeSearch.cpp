/*
 * TreeSearch.cpp
 *
 *  Created on: 22/03/2014
 *      Author: cameron
 */

#include "TreeSearch.h"
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <algorithm>
#include <iostream>

TreeSearch::~TreeSearch() {
	// TODO Auto-generated destructor stub
}

TreeSearch::TreeSearch() {
	initialState=NULL;
	finalState=NULL;
	foundState=NULL;
	width=-1;
	height=-1;
	// TODO Auto-generated constructor stub

}

void TreeSearch::loadFile(char *filename) {
	int tempval;
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
		perror("Failed to open file:");
	}
	fscanf(fp, "%i", &height);
	fscanf(fp, "%i", &width);
	//	initialState.board = (int **)malloc(height *sizeof(int *));
	//	for (int i=0; i < height; i++) {
	//		initialState.board[i] = (int *)malloc(width*sizeof(int));
	//	}
	//	finalState.board = (int **)malloc(height *sizeof(int *));
	//	for (int i=0; i < height; i++) {
	//		finalState.board[i] = (int *)malloc(width*sizeof(int));
	//	}
	initialState = new state;
	initialState->cost=0;
	initialState->depth=0;
	initialState->fingerprint="";
	initialState->mv=NOMV;
	initialState->parent=NULL;

	initialState->board = new int*[height];
	for (int i=0; i < height; i++) {
		initialState->board[i] = new int[width];
	}
	finalState = new state;
	finalState->cost=0;
	finalState->depth=0;
	finalState->fingerprint="";
	finalState->mv=NOMV;
	finalState->parent=NULL;
	finalState->board = new int*[height];
	for (int i=0; i < height; i++) {
		finalState->board[i] = new int[width];
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			fscanf(fp, "%i;", &tempval);
			initialState->board[i][j]=tempval;
			//		printf("%i,%i - %i\n",i/width,i%width, tempval);
		}
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			fscanf(fp, "%i;", &tempval);
			finalState->board[i][j]=tempval;
			//		printf("%i,%i - %i\n",i/width,i%width, tempval);
		}
	}
	initialState->fingerprint=fingerprintState(initialState);
	finalState->fingerprint=fingerprintState(finalState);

}

/**
 * Gets the next state for the given direction, Returns NULL if the move is invalid.
 */
state *TreeSearch::getNextState(const state *parent, move dir) {
	state *temp = new state;
	int row=-1, col=-1;

	temp->board = new int*[height];
	for (int i=0; i < height; i++) {
		temp->board[i] = new int[width];
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			temp->board[i][j]=parent->board[i][j];
			if (parent->board[i][j] == 0) {
				col=j;
				row=i;
			}
		}
	}
	if (row==-1 || col == -1) {
		throw "Could not find empty cell?"; //TODO: unsure if this is legal or what it will result in, dont really care.
	}

	switch (dir) {
	case LEFT:
		if (col == 0) {
			deleteState(temp);
			return NULL;
		} else {
			temp->board[row][col]=temp->board[row][col-1];
			temp->board[row][col-1]=0;
		}
		break;
	case RIGHT:
		if (col == width-1) {
			deleteState(temp);
			return NULL;
		} else {
			temp->board[row][col]=temp->board[row][col+1];
			temp->board[row][col+1]=0;
		}
		break;
	case UP:
		if (row == 0) {
			deleteState(temp);
			return NULL;
		} else {
			temp->board[row][col]=temp->board[row-1][col];
			temp->board[row-1][col]=0;
		}
		break;
	case DOWN:
		if (row == height-1) {
			deleteState(temp);
			return NULL;
		} else {
			temp->board[row][col]=temp->board[row+1][col];
			temp->board[row+1][col]=0;
		}
		break;
	case NOMV:
		break; //shouldnt happen, this code juyst prevents the compiler warning
	}
	temp->parent=parent;
	temp->depth=parent->depth+1;
	temp->mv=dir;
	temp->cost=rateState(temp, finalState);
	temp->fingerprint=fingerprintState(temp);
	return temp;
}

/**
 * Returns a string unique to the state.
 */
std::string TreeSearch::fingerprintState(state *st) {
	std::ostringstream fingerprint;
	int totalvals = width*height;
	for (int i=0; i < totalvals; i++) {
		fingerprint << st->board[i/width][i%width] << ";";
	}
	return fingerprint.str();
}

void TreeSearch::prettyPrintState(const state *st) {
	std::cout << "Move: " << st->mv << std::endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			std::cout << st->board[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;

}

void TreeSearch::deleteState(state* st) {
	if (st->board != NULL) {
		for (int i=0; i < height; i++) {
			delete(st->board[i]);
		}
		delete(st->board);
	}
	delete(st);
}


/**
 * This function ranks a state on the distance between the tiles in each state 0 is perfect -Not Admissable, but it was a decent first attempt?
 */
//int TreeSearch::rateState(const state* given, const state* baseline) {
//	int tempValue; //value of the position we are searching for
//	int sumDistances=0;
//
//	for (int xpos1 = 0; xpos1 < height; xpos1++) { //xposition of the value we are looking for
//		for (int ypos1 = 0; ypos1 < width; ypos1++) { //yposition of the value we are looking for
//			tempValue=given->board[xpos1][ypos1];
//			for (int xpos2 = 0; xpos2 < height; xpos2++) { //xposition that the value is found at
//				for (int ypos2 = 0; ypos2 < width; ypos2++) { //yposition that the value is found at
//					if (baseline->board[xpos2][ypos2] == tempValue) {
//						sumDistances += (((xpos1-xpos2)*(xpos1-xpos2))+((ypos1-ypos2)*(ypos1-ypos2))); //sqrt is expensive, dont bother as it doesnt affect the number meaningfully anyway
//						goto jump; //not happy about this, but it is a fairly short jump and probably clearer as a goto than a seperate function+return
//					}				//	 |
//				}					//	 |
//			}						//	 |
//			jump:;					// <-|
//		}
//	}
//	prettyPrintState(given);
//	prettyPrintState(baseline);
//	std::cout << sumDistances <<std::endl;
//	return sumDistances;
//}

/**
 * This function ranks a state on the Manhattan distance between the tiles in each state 0 is perfect
 */
int TreeSearch::rateState(const state* given, const state* baseline) {
	int tempValue; //value of the position we are searching for
	int sumDistances=0;

	for (int xpos1 = 0; xpos1 < height; xpos1++) { //xposition of the value we are looking for
		for (int ypos1 = 0; ypos1 < width; ypos1++) { //yposition of the value we are looking for
			tempValue=given->board[xpos1][ypos1];
			if (tempValue == 0) { //distance to zero not really useful, but I havent tested either way. Probably a fairly consistent scaling factor
				continue;
			}
			for (int xpos2 = 0; xpos2 < height; xpos2++) { //xposition that the value is found at
				for (int ypos2 = 0; ypos2 < width; ypos2++) { //yposition that the value is found at
					if (baseline->board[xpos2][ypos2] == tempValue) {
						sumDistances += ((xpos1-xpos2)+(ypos1-ypos2)); //sqrt is expensive, dont bother as it doesnt affect the number meaningfully anyway
					}
				}
			}
		}
	}
	return sumDistances;
}

void TreeSearch::print(const char *str) {
	std::cout << filename << " " << str << " ";
	std::string moves;
	int numbernodes = allStates.size();
	if (foundState != NULL) {
		const state *tempState = foundState;

		while (tempState->parent != NULL) {
			switch (tempState->mv) {
			case UP:
				moves = "UP; " +moves;
				break;
			case DOWN:
				moves = "DOWN; " +moves;
				break;
			case LEFT:
				moves = "LEFT; " +moves;
				break;
			case RIGHT:
				moves = "RIGHT; " +moves;
				break;
			case NOMV:
				break; //shouldnt happen, this code juyst prevents the compiler warning
			}
			tempState = tempState->parent;
		}
	} else {
		moves = "Failed to find path";
	}
	std::cout << numbernodes << " " << moves << std::endl;
}
