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
	width=-1;
	height=-1;
	// TODO Auto-generated constructor stub

}

void TreeSearch::loadFile(char *filename) {
	int totalvals;
	int tempval;
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
		perror("Failed to open file:");
	}
	fscanf(fp, "%i", &height);
	fscanf(fp, "%i", &width);
	totalvals = width*height;
//	initialState.board = (int **)malloc(height *sizeof(int *));
//	for (int i=0; i < height; i++) {
//		initialState.board[i] = (int *)malloc(width*sizeof(int));
//	}
//	finalState.board = (int **)malloc(height *sizeof(int *));
//	for (int i=0; i < height; i++) {
//		finalState.board[i] = (int *)malloc(width*sizeof(int));
//	}
	initialState.board = new int*[height];
	for (int i=0; i < height; i++) {
		initialState.board[i] = new int[width];
	}
	finalState.board = new int*[height];
	for (int i=0; i < height; i++) {
		finalState.board[i] = new int[width];
	}

	for (int i=0; i < totalvals; i++) {
		fscanf(fp, "%i;", &tempval);
		initialState.board[i/width][i%width]=tempval;
//		printf("%i,%i - %i\n",i/width,i%width, tempval);
	}
	for (int i=0; i < totalvals; i++) {
		fscanf(fp, "%i;", &tempval);
		finalState.board[i/width][i%width]=tempval;
//		printf("%i,%i - %i\n",i/width,i%width, tempval);
	}

}

/**
 * Gets the next state for the given direction, Returns NULL if the move is invalid.
 */
state *TreeSearch::getNextState(const state *parent, move dir) {
	state *temp = new state;
	int totalvals = width*height;
	int row=-1, col=-1;

	temp->parent=parent;
	temp->depth=parent->depth+1;
	temp->cost=parent->cost+1;
	temp->mv=dir;

	temp->board = new int*[height];
	for (int i=0; i < height; i++) {
		temp->board[i] = new int[width];
	}
	for (int i=0; i < totalvals; i++) {
		temp->board[i/width][i%width]=parent->board[i/width][i%width];
		if (parent->board[i/width][i%width] == 0) {
			col=i/width;
			row=i%width;
		}
	}
	if (row==-1 || col == -1) {
		throw "Could not find empty cell?"; //TODO: unsure if this is legal or what it will result in, dont really care.
	}

	switch (dir) {
	case LEFT:
		if (col == 0) {
			return NULL;
		} else {
			temp->board[row][col]=temp->board[row][col-1];
			temp->board[row][col-1]=0;
		}
		break;
	case RIGHT:
		if (col == height-1) {
			return NULL;
		} else {
			temp->board[row][col]=temp->board[row][col+1];
			temp->board[row][col+1]=0;
		}
		break;
	case UP:
		if (row == 0) {
			return NULL;
		} else {
			temp->board[row][col]=temp->board[row-1][col];
			temp->board[row-1][col]=0;
		}
		break;
	case DOWN:
		if (row == width-1) {
			return NULL;
		} else {
			temp->board[row][col]=temp->board[row+1][col];
			temp->board[row+1][col]=0;
		}
		break;
	}
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

void TreeSearch::prettyPrintState(state *st) {
	std::cout << "Move: " << st->mv << std::endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			std::cout << st->board[i][j] << " ";
		}
		std::cout << std::endl;
			}
	std::cout << std::endl << std::endl;

}
