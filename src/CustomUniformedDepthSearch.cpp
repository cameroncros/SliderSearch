/*
 * CustomUniformedDepthSearch.cpp
 *
 *  Created on: 23/03/2014
 *      Author: cameron
 */

#include "CustomUniformedDepthSearch.h"
#include <iostream>

CustomUniformedDepthSearch::CustomUniformedDepthSearch(char *fname) {
	filename = fname;
	loadFile(fname);
	foundState = NULL;
	depthLimit = 1;
	// TODO Auto-generated constructor stub

}

CustomUniformedDepthSearch::~CustomUniformedDepthSearch() {
	// TODO Auto-generated destructor stub
}


void CustomUniformedDepthSearch::run() {
	while (foundState == NULL) {
	evaluateState(initialState);
	depthLimit++;
	}
}

bool CustomUniformedDepthSearch::evaluateState(state *workingState) {
	state *temp;

	//check if we are at end;
	if (workingState->fingerprint.compare(finalState->fingerprint) == 0) {
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
		if (tempState->fingerprint.compare(workingState->fingerprint) == 0) {
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

void CustomUniformedDepthSearch::print() {
	TreeSearch::print("DFS", foundState->depth);
}
