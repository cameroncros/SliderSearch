/*
 * DepthFirstSearch.cpp
 *
 *  Created on: 23/03/2014
 *      Author: cameron
 */

#include "DepthFirstLimitedSearch.h"
#include <iostream>

DepthFirstLimitedSearch::DepthFirstLimitedSearch(char *fname) {
	filename = fname;
	loadFile(fname);
	foundState = NULL;
	depthLimit = (width*height)*(width*height);
	// TODO Auto-generated constructor stub

}

DepthFirstLimitedSearch::~DepthFirstLimitedSearch() {
	// TODO Auto-generated destructor stub
}


void DepthFirstLimitedSearch::run() {
	evaluateState(initialState);
}

bool DepthFirstLimitedSearch::evaluateState(state *workingState) {
	state *temp;

	//check if we are at end;
	if (compareState(workingState,finalState) == true) {
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
		if (compareState(tempState,workingState) == true) {
			return false;
			break;
		}
	}




	//discover possible next states.
	temp = getNextState(workingState, UP);
	if (temp != NULL && evaluateState(temp) == true) {
		return true;
	} else {
		deleteState(temp);
	}
	temp = getNextState(workingState, LEFT);
	if (temp != NULL && evaluateState(temp) == true) {
		return true;
	} else {
		deleteState(temp);
	}
	temp = getNextState(workingState, DOWN);
	if (temp != NULL && evaluateState(temp) == true) {
		return true;
	} else {
		deleteState(temp);
	}
	temp = getNextState(workingState, RIGHT);
	if (temp != NULL && evaluateState(temp) == true) {
		return true;
	} else {
		deleteState(temp);
	}
	return false;
}

void DepthFirstLimitedSearch::print() {
	TreeSearch::print("DFS", createdStates);
}
