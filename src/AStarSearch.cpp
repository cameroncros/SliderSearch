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

	int best;
	std::map<move, std::vector<state *>::iterator> tempMap;
	std::map<move, std::vector<state *>::iterator>::iterator bestIterator;
	while (foundState == NULL) {



		//get next state to test
		tempMap.clear();
		best = std::numeric_limits<int>::max();
		for (std::vector<state *>::iterator i = newStates.begin(); i != newStates.end(); i++) {
			if ((*i)->cost+(*i)->depth < best) {
				best = (*i)->cost;
				tempMap.clear();
				tempMap.insert(std::pair<move, std::vector<state *>::iterator>((*i)->mv, i));
			} else if ((*i)->cost == best) {
				tempMap.insert(std::pair<move, std::vector<state *>::iterator>((*i)->mv, i));
			}
		}
		//check if we have run out of moves
		if (tempMap.size() == 0) {
			return;
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

void AStarSearch::print() {
	TreeSearch::print("AS");
}
