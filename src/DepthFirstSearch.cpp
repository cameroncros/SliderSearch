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
	// TODO Auto-generated constructor stub

}

DepthFirstSearch::~DepthFirstSearch() {
	// TODO Auto-generated destructor stub
}


void DepthFirstSearch::run() {
	while (foundState == NULL) {
		state *temp;
		state *workingState;
		std::string finger;


		//get next state to test
		workingState = newStates.top();
		newStates.pop();


		//check if we are at end;
		if (workingState->fingerprint.compare(finalState->fingerprint) == 0) {
			foundState = workingState;
			continue;
		}

		//check if current state exists in history
		bool duplicate = false;
		const state *tempState = workingState;
		while (tempState->parent != NULL) {
			tempState = tempState->parent;
			if (tempState->fingerprint.compare(workingState->fingerprint) == 0) {
				duplicate = true;
				break;
			}
		}
		if (duplicate == true) {
			continue;
		}


		//discover possible next states.
		temp = getNextState(workingState, RIGHT);
		if (temp != NULL) {
			allStates.push_back(temp);
			newStates.push(temp);
		}
		temp = getNextState(workingState, DOWN);
		if (temp != NULL) {
			allStates.push_back(temp);
			newStates.push(temp);
		}
		temp = getNextState(workingState, LEFT);
		if (temp != NULL) {
			allStates.push_back(temp);
			newStates.push(temp);
		}
		temp = getNextState(workingState, UP);
		if (temp != NULL) {
			allStates.push_back(temp);
			newStates.push(temp);
		}





	}
}

void DepthFirstSearch::print() {
	TreeSearch::print("DFS");
}
