/*
 * AStarSearch.cpp
 *
 *  Created on: 27/03/2014
 *      Author: cameron
 */

#include "AStarSearch.h"
#include <iostream>
#include <limits>

AStarSearch::AStarSearch(char *fname) {
	filename = fname;
	loadFile(fname);
	foundState = NULL;
	newStates.push_back(initialState);
	// TODO Auto-generated constructor stub

}

AStarSearch::~AStarSearch() {
	// TODO Auto-generated destructor stub
}

void AStarSearch::run() {
	state *temp;
	state *workingState;
	std::string finger;

	int bestIterator;

	
	while (foundState == NULL) {



		//get next state to test
		int best = std::numeric_limits<int>::max();
		for (int i = newStates.size()-1; i >= 0; i--) {
			if (newStates[i]->cost + newStates[i]->depth <= best) {
				best = newStates[i]->cost + newStates[i]->depth;
				bestIterator = i;
			}
		}

		workingState = newStates[bestIterator];
		newStates.erase(newStates.begin()+bestIterator);

		//check if we are at end;
		if (compareState(workingState,finalState) == true) {
			foundState = workingState;
			continue;
		}

		//check if state has been seen before
		std::map<std::string, state* >::iterator past = discoveredStates.find(workingState->finger.finger);

		if (past != discoveredStates.end() && (*past).second->depth < workingState->depth) {
			//this state has occured before with less cost, it is not certain that this is in the same tree,
			//but it is faster than recursing up a huge tree comparing fingerprints
			continue;
		} else {
			discoveredStates.insert(std::pair<std::string, state*>(workingState->finger.finger, workingState));
		}


		//discover possible next states.
		temp = getNextState(workingState, RIGHT);
		if (temp != NULL) {
			allStates.push_back(temp);
			newStates.push_back(temp);
		}
		temp = getNextState(workingState, DOWN);
		if (temp != NULL) {
			allStates.push_back(temp);
			newStates.push_back(temp);
		}
		temp = getNextState(workingState, LEFT);
		if (temp != NULL) {
			allStates.push_back(temp);
			newStates.push_back(temp);
		}
		temp = getNextState(workingState, UP);
		if (temp != NULL) {
			allStates.push_back(temp);
			newStates.push_back(temp);
		}





	}
}

void AStarSearch::print() {
	TreeSearch::print("AS", allStates.size());
}
