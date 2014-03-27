/*
 * AStarSearch.h
 *
 *  Created on: 25/03/2014
 *      Author: cameron
 */

#ifndef ASTARSEARCH_H_
#define ASTARSEARCH_H_

#include "TreeSearch.h"
#include <vector>
#include <map>
#include <string>

class AStarSearch: public TreeSearch {
private:
	std::vector<state*> newStates; //used to list all the new states so that they can be iterated correctly.

public:
	AStarSearch(char *fname);
	virtual ~AStarSearch();
	void run();
	void print();
};

#endif /* AStarSearch_H_ */
