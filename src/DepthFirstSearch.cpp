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
	depthLimit = (width*height)*(width*height);
	nextState.push(initialState);
	// TODO Auto-generated constructor stub

}

DepthFirstSearch::~DepthFirstSearch() {
	while (allStates.size() != 0) {
		deleteState(allStates.top());
		allStates.pop();
	}
}


void DepthFirstSearch::run() {
	state *workingState;
	while (foundState == NULL) {
		workingState = nextState.top();

		//check if move was invalid
		if (workingState == NULL) {
			nextState.pop();
			continue;
		}
		//check if all lower states are checked
		if (workingState->childMoves == 15 /*0b1111*/) {
			nextState.pop();
			continue;
		}




		//check if this is a state that has been checked yet
		if (workingState->childMoves==NOMV) {

			//check if we are at end;
			if (compareState(workingState,finalState) == true) {
				foundState = workingState;
				return;
			}

			//check if current state exists in history
			const state *tempState = workingState;
			while (tempState->parent != NULL) {
				tempState = tempState->parent;
				if (compareState(tempState,workingState) == true) {
					nextState.pop();
					continue;
				}
			}
		}
		//Get next move
		state *temp;
		if ((workingState->childMoves & UP) == 0) {
			workingState->childMoves |= UP;
			temp = getNextState(workingState, UP);
			nextState.push(temp);
			allStates.push(temp);
			continue;
		}
		if ((workingState->childMoves & LEFT) == 0) {
			workingState->childMoves |= LEFT;
			temp = getNextState(workingState, LEFT);
			nextState.push(temp);
			allStates.push(temp);
			continue;
		}
		if ((workingState->childMoves & DOWN) == 0) {
			workingState->childMoves |= DOWN;
			temp = getNextState(workingState, DOWN);
			nextState.push(temp);
			allStates.push(temp);
			continue;
		}
		if ((workingState->childMoves & RIGHT) == 0) {
			workingState->childMoves |= RIGHT;
			temp = getNextState(workingState, RIGHT);
			nextState.push(temp);
			allStates.push(temp);
			continue;
		}


	}
}

void DepthFirstSearch::print() {
	TreeSearch::print("DFS", createdStates);
}
