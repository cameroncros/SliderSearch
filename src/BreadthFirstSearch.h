/*
 * BreadthFirstSearch.h
 *
 *  Created on: 23/03/2014
 *      Author: cameron
 */

#ifndef BREADTHFIRSTSEARCH_H_
#define BREADTHFIRSTSEARCH_H_

#include "TreeSearch.h"
#include "main.h"
#include <map>
#include <vector>
#include <queue>
#include <string>

class BreadthFirstSearch: public TreeSearch {
private:
	std::queue<state*> newStates; //used to list all the new states so that they can be iterated correctly.
public:
	BreadthFirstSearch(char *filename);
	virtual ~BreadthFirstSearch();
	void run();
	void print();
};

#endif /* BREADTHFIRSTSEARCH_H_ */
