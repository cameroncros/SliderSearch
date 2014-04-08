/*
 * AStarSearch.h
 *
 *  Created on: 25/03/2014
 *      Author: cameron
 */

#ifndef ASTARSEARCH_H_
#define ASTARSEARCH_H_

#include "TreeSearch.h"
#include <deque>
#include <map>
#include <string>

class AStarSearch: public TreeSearch {
private:
	std::deque<state*> newStates; //used to list all the new states so that they can be iterated correctly.
	std::map<std::string, state*> discoveredStates; //used to check if we have hit this state before.

public:
	AStarSearch(char *fname);
	virtual ~AStarSearch();
	void run();
	void print();
};

#endif /* AStarSearch_H_ */
