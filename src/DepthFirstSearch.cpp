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
	state *temp;
	state *workingState;

	while (foundState == NULL) {



		//get next state to test
		if (newStates.size()!=0) {
			workingState = newStates.top();
			newStates.pop();
		} else {
			return;
		}


		//check if we are at end;
		if (workingState->fingerprint.compare(finalState->fingerprint) == 0) {
			foundState = workingState;
			continue;
		}

		//check if current state exists in history
		//		bool duplicate = false;
		//		const state *tempState = workingState;
		//		while (tempState->parent != NULL) {
		//			tempState = tempState->parent;
		//			if (tempState->fingerprint.compare(workingState->fingerprint) == 0) {
		//				duplicate = true;
		//				break;
		//			}
		//		}
		//		if (duplicate == true) {
		//			continue;
		//		}
		std::map<std::string, state* >::iterator past = discoveredStates.find(workingState->fingerprint);

		if (past != discoveredStates.end() && (*past).second->depth < workingState->depth) {
			//this state has occured before with less cost, it is not certain that this is in the same tree,
			//but it is faster than recursing up a huge tree comparing fingerprints
			continue;
		} else {
			discoveredStates.insert(std::pair<std::string, state*>(workingState->fingerprint, workingState));

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
