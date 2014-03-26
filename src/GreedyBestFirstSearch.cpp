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
	finalFingerprint = fingerprintState(finalState);
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
			if ((*i)->cost == best) {
				tempMap.insert(std::pair<move, std::vector<state *>::iterator>((*i)->mv, i));
			}
		}
		if ((bestIterator = tempMap.find(UP)) != tempMap.end()) {}
		else if ((bestIterator = tempMap.find(LEFT)) != tempMap.end()) {}
		else if ((bestIterator = tempMap.find(DOWN)) != tempMap.end()) {}
		else if ((bestIterator = tempMap.find(RIGHT)) != tempMap.end()) {}

		workingState = *bestIterator->second;
		newStates.erase(bestIterator->second);

		//prettyPrintState(workingState);
		//check if we are at end;
		finger = fingerprintState(workingState);
		if (finger.compare(finalFingerprint) == 0) {
			foundState = workingState;
			continue;
		}
		//check if current state exists in list
		if (discoveredStates.find(finger) == discoveredStates.end()) {
			//TODO: does dfs check for optimal route? ie, if depth is greater at this step that the step that was found, should I ignore the previous step?
			//TODO: I will just skip for now until I have a better understanding or if it impacts preformance.

			//add self to discovered states so it is not looped over again.
			discoveredStates.insert(std::pair<std::string, state*>(finger, workingState));
		} else {
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
	std::cout << filename << " GBFS ";
	std::string moves;
	int numbernodes = allStates.size();
	const state *tempState = foundState;
	while (tempState->parent != NULL) {
		switch (tempState->mv) {
		case UP:
			moves = "UP; " +moves;
			break;
		case DOWN:
			moves = "DOWN; " +moves;
			break;
		case LEFT:
			moves = "LEFT; " +moves;
			break;
		case RIGHT:
			moves = "RIGHT; " +moves;
			break;
		}
		tempState = tempState->parent;
	}
	std::cout << numbernodes << " " << moves << std::endl;
}
