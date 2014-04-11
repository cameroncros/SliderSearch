/*
 * BreadthFirstSearch.cpp
 *
 *  Created on: 23/03/2014
 *      Author: cameron
 */

#include "BreadthFirstSearch.h"
#include <iostream>
#include <sstream>

BreadthFirstSearch::BreadthFirstSearch(char *fname) {
	filename = fname;
	loadFile(fname);
	foundState = NULL;
	newStates.push(initialState);
	// TODO Auto-generated constructor stub

}

BreadthFirstSearch::~BreadthFirstSearch() {
	// TODO Auto-generated destructor stub
}


void BreadthFirstSearch::run() {
	while (foundState == NULL) {
		state *temp;
		std::string finger;
		state *workingState;


		//get next state to test
		workingState = newStates.front();
		newStates.pop();


		//check if we are at end;
		if (compareState(workingState, finalState) == true) {
			foundState = workingState;
			continue;
		}

		//check if current state exists in history
		bool duplicate = false;
		const state *tempState = workingState;
		while (tempState->parent != NULL) {
			tempState = tempState->parent;
			if (compareState(tempState,workingState) == true) {
				duplicate = true;
				break;
			}
		}
		if (duplicate == true) {
			continue;
		}


		//discover possible next states.
		temp = getNextState(workingState, UP);
		if (temp != NULL) {
			allStates.push_back(temp);
			newStates.push(temp);
		}
		temp = getNextState(workingState, LEFT);
		if (temp != NULL) {
			allStates.push_back(temp);
			newStates.push(temp);
		}
		temp = getNextState(workingState, DOWN);
		if (temp != NULL) {
			allStates.push_back(temp);
			newStates.push(temp);
		}
		temp = getNextState(workingState, RIGHT);
		if (temp != NULL) {
			allStates.push_back(temp);
			newStates.push(temp);
		}
	}
}

void BreadthFirstSearch::print() {
	TreeSearch::print("BFS", allStates.size());
}
