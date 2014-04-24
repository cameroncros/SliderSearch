/*
 * GreedyBestFirstSearch.cpp
 *
 *  Created on: 25/03/2014
 *      Author: cameron
 */

#include "GreedyBestFirstSearch.h"
#include <iostream>
#include <limits>
#include <list>

bool compareHeuristic(const state *first, const state *second);

GreedyBestFirstSearch::GreedyBestFirstSearch(char *fname) {
	filename = fname;
	loadFile(fname);
	foundState = NULL;
	newStates.push(initialState);
	// TODO Auto-generated constructor stub

}

GreedyBestFirstSearch::~GreedyBestFirstSearch() {
	// TODO Auto-generated destructor stub
}

void GreedyBestFirstSearch::run() {
	state *up, *down, *left, *right;
	state *workingState;
	while (foundState == NULL) {
		if (newStates.size() == 0) {
			return;
		}
		workingState = newStates.top();
		newStates.pop();

		//check if move was invalid
		if (workingState == NULL) {
			continue;
		}

		//check if we are at end;
		if (compareState(workingState, finalState) == true) {
			foundState = workingState;
			return;
		}

		//check if current state exists in history
		const state *tempState = workingState;
		bool repeated = false;
		while (tempState->parent != NULL) {
			tempState = tempState->parent;
			if (compareState(tempState, workingState) == true) {
				repeated=true;
				break;
			}
		}
		if (repeated == true) {
			continue;
		}

		//discover possible next states.
		up = getNextState(workingState, UP);
		left = getNextState(workingState, LEFT);
		down = getNextState(workingState, DOWN);
		right = getNextState(workingState, RIGHT);
		allStates.push(up);
		allStates.push(left);
		allStates.push(down);
		allStates.push(right);

		/*
		int low = 0;

		if (up != NULL && up->cost > low) {
			low = up->cost;
		}
		if (left != NULL && left->cost > low) {
			low = left->cost;
		}
		if (down != NULL && down->cost > low) {
			low = down->cost;
		}
		if (right != NULL && right->cost > low) {
			low = right->cost;
		}

		for (int i = low; i != 0; i--) {
			if (up != NULL && up->cost == i) {
				nextState.push(up);
			}
			if (left != NULL && left->cost == i) {
				nextState.push(left);
			}
			if (down != NULL && down->cost == i) {
				nextState.push(down);
			}
			if (right != NULL && right->cost == i) {
				nextState.push(right);
			}

		}
		*/

		
		std::list<state *> mylist;
		mylist.push_back(up);
		mylist.push_back(left);
		mylist.push_back(down);
		mylist.push_back(right);

		mylist.sort(compareHeuristic);
		std::list<state *>::iterator it;
		for (it = mylist.begin(); it != mylist.end(); ++it) {
			if (*it != NULL) {
				newStates.push(*it);
			}
		}
	}
}

bool compareHeuristic(const state *first, const state *second) {
	if (first == NULL) {
		return false;
	}
	if (second == NULL) {
		return true;
	}
	return (first->cost > second->cost);
}

void GreedyBestFirstSearch::print() {
	TreeSearch::print("GBFS", createdStates-deletedStates);
}
