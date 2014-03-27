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
	while (foundState == NULL) {
		state *temp;
		state *workingState;
		std::string finger;


		//get next state to test
		int best = std::numeric_limits<int>::max();
		std::map<move, std::vector<state *>::iterator> tempMap;
		std::map<move, std::vector<state *>::iterator>::iterator bestIterator;
		for (std::vector<state *>::iterator i = newStates.begin(); i != newStates.end(); i++) {
			if ((*i)->cost < best) {
				best = (*i)->cost;
				tempMap.clear();
				tempMap.insert(std::pair<move, std::vector<state *>::iterator>((*i)->mv, i));
			}
			else if ((*i)->cost == best) {
				tempMap.insert(std::pair<move, std::vector<state *>::iterator>((*i)->mv, i));
			}
		}
		if ((bestIterator = tempMap.find(UP)) != tempMap.end()) {}
		else if ((bestIterator = tempMap.find(LEFT)) != tempMap.end()) {}
		else if ((bestIterator = tempMap.find(DOWN)) != tempMap.end()) {}
		else if ((bestIterator = tempMap.find(RIGHT)) != tempMap.end()) {}

		workingState = *bestIterator->second;
		newStates.erase(bestIterator->second);

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
			temp->cost=rateState(temp, finalState);
			allStates.push_back(temp);
			newStates.push_back(temp);
		}
		temp = getNextState(workingState, DOWN);
		if (temp != NULL) {
			temp->cost=rateState(temp, finalState);
			allStates.push_back(temp);
			newStates.push_back(temp);
		}
		temp = getNextState(workingState, LEFT);
		if (temp != NULL) {
			temp->cost=rateState(temp, finalState);
			allStates.push_back(temp);
			newStates.push_back(temp);
		}
		temp = getNextState(workingState, UP);
		if (temp != NULL) {
			temp->cost=rateState(temp, finalState);
			allStates.push_back(temp);
			newStates.push_back(temp);
		}





	}
}

void GreedyBestFirstSearch::print() {
	TreeSearch::print("GBFS");
}
