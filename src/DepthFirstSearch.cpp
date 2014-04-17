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
	// TODO Auto-generated destructor stub
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
		if (workingState->childMoves == 0b1111) {
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

			//check if we are getting too deep
			if (workingState->depth > depthLimit) {
				nextState.pop();
				continue;
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
		if ((workingState->childMoves & UP) == 0) {
			workingState->childMoves |= UP;
			nextState.push(getNextState(workingState, UP));
			continue;
		}
		if ((workingState->childMoves & LEFT) == 0) {
			workingState->childMoves |= LEFT;
			nextState.push(getNextState(workingState, LEFT));
			continue;
		}
		if ((workingState->childMoves & DOWN) == 0) {
			workingState->childMoves |= DOWN;
			nextState.push(getNextState(workingState, DOWN));
			continue;
		}
		if ((workingState->childMoves & RIGHT) == 0) {
			workingState->childMoves |= RIGHT;
			nextState.push(getNextState(workingState, RIGHT));
			continue;
		}


	}
	evaluateState(initialState);
}

bool DepthFirstSearch::evaluateState(state *workingState) {
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

void DepthFirstSearch::print() {
	TreeSearch::print("DFS", foundState->depth);
}
