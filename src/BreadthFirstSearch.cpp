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
	finalFingerprint = fingerprintState(finalState);
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


		//prettyPrintState(workingState);
		//check if we are at end;
		finger = fingerprintState(workingState);
		if (finger.compare(finalFingerprint) == 0) {
			foundState = workingState;
			continue;
		}
		//check if current state exists in list
		if (discoveredStates.find(finger) == discoveredStates.end()) {
			//TODO: does dfs check for optimal route? ie, if Breadth is greater at this step that the step that was found, should I ignore the previous step?
			//TODO: I will just skip for now until I have a better understanding or if it impacts preformance.

			//add self to discovered states so it is not looped over again.
			discoveredStates.insert(std::pair<std::string, state*>(finger, workingState));
		} else {
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
	std::cout << filename << " BFS ";
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
