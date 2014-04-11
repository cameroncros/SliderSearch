/*
 * GreedyBestFirstSearch.cpp
 *
 *  Created on: 25/03/2014
 *      Author: cameron
 */

#include "GreedyBestFirstSearch.h"
#include <iostream>
#include <limits>

GreedyBestFirstSearch::GreedyBestFirstSearch(char *fname) {
	filename = fname;
	loadFile(fname);
	foundState = NULL;
	depthLimit = (width*height)*(width*height);
	// TODO Auto-generated constructor stub

}

GreedyBestFirstSearch::~GreedyBestFirstSearch() {
	// TODO Auto-generated destructor stub
}

void GreedyBestFirstSearch::run() {
	evaluateState(initialState);
}

bool GreedyBestFirstSearch::evaluateState(state *workingState) {
	state *up, *down, *left, *right;

	//check if we are at end;
	if (compareState(workingState, finalState) == true) {
		foundState = workingState;
		return true;
	}

	//check if we are getting too deep
	if (workingState->depth > depthLimit) {
		return false;
	}

	//check if current state exists in history
	const state *tempState = workingState;
	while (tempState->parent != NULL) {
		tempState = tempState->parent;
		if (compareState(tempState, workingState) == true) {
			return false;
		}
	}




	//discover possible next states.
	up = getNextState(workingState, UP);
	left = getNextState(workingState, LEFT);
	down = getNextState(workingState, DOWN);
	right = getNextState(workingState, RIGHT);

	int numTests = 0;
	if (up == NULL) {
		numTests++;
	}
	if (down == NULL) {
		numTests++;
	}
	if (left == NULL) {
		numTests++;
	}
	if (right == NULL) {
		numTests++;
	}
	int testDepth=0;
	while (numTests < 4) {
		if (up != NULL && up->cost == testDepth) {
			if (evaluateState(up) == true) {
				return true;
			} else {
				deleteState(up);
				numTests++;
			}
		}
		if (left != NULL && left->cost == testDepth) {
			if (evaluateState(left) == true) {
				return true;
			} else {
				deleteState(left);
				numTests++;
			}
		}
		if (down != NULL && down->cost == testDepth) {
			if (evaluateState(down) == true) {
				return true;
			} else {
				deleteState(down);
				numTests++;
			}
		}
		if (right != NULL && right->cost == testDepth) {
			if (evaluateState(right) == true) {
				return true;
			} else {
				deleteState(right);
				numTests++;
			}
		}
		testDepth++;
	}
	return false;
}

void GreedyBestFirstSearch::print() {
	TreeSearch::print("GBFS", createdStates-deletedStates);
}
