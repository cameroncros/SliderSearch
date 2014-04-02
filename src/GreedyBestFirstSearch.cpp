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
	newStates.push_back(initialState);
	// TODO Auto-generated constructor stub

}

GreedyBestFirstSearch::~GreedyBestFirstSearch() {
	// TODO Auto-generated destructor stub
}

void GreedyBestFirstSearch::run() {
	int bestIterator;
	while (foundState == NULL) {
		state *temp;
		state *workingState;
		std::string finger;


		//get next state to test
		int depth = newStates[newStates.size()-1]->depth;
		int best = std::numeric_limits<int>::max();
		for (int i = newStates.size()-1; i >= 0; i--) {
			if (newStates[i]->depth != depth) {
				break;
			}
			if (newStates[i]->cost <= best) {
				best = newStates[i]->cost;
				bestIterator = i;
			}

		}

		workingState = newStates[bestIterator];
		newStates.erase(newStates.begin()+bestIterator);

		//check if we are at end;
		if (workingState->fingerprint.compare(finalState->fingerprint) == 0) {
			foundState = workingState;
			continue;
		}

		//check if state has been seen before
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

void GreedyBestFirstSearch::print() {
	TreeSearch::print("GBFS");
}
