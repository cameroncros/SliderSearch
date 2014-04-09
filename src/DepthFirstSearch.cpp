/*
 * DepthFirstSearch.cpp
 *
 *  Created on: 23/03/2014
 *      Author: cameron
 */

#include "DepthFirstSearch.h"
#include <iostream>

DepthFirstSearch::DepthFirstSearch(char *fname) {
	filename = fname;
	loadFile(fname);
	foundState = NULL;
	newStates.push(initialState);
	depthLimit = 16;
	// TODO Auto-generated constructor stub

}

DepthFirstSearch::~DepthFirstSearch() {
	// TODO Auto-generated destructor stub
}


void DepthFirstSearch::run() {
	evaluateState(initialState);
}

bool DepthFirstSearch::evaluateState(state *workingState) {
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

	//			std::map<std::string, state* >::iterator past = discoveredStates.find(workingState->fingerprint);
	//
	//			if (past != discoveredStates.end() && (*past).second->depth < workingState->depth) {
	//				//this state has occured before with less cost, it is not certain that this is in the same tree,
	//				//but it is faster than recursing up a huge tree comparing fingerprints
	//				continue;
	//			} else {
	//				discoveredStates.insert(std::pair<std::string, state*>(workingState->fingerprint, workingState));
	//
	//			}


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

void DepthFirstSearch::print() {
	TreeSearch::print("DFS", foundState->depth);
}
