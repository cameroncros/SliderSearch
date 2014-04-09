/*
 * DepthFirstSearch.h
 *
 *  Created on: 23/03/2014
 *      Author: cameron
 */

#ifndef DEPTHFIRSTSEARCH_H_
#define DEPTHFIRSTSEARCH_H_

#include "TreeSearch.h"
#include "main.h"
#include <map>
#include <vector>
#include <stack>
#include <string>

class DepthFirstSearch: public TreeSearch {
private:
	std::stack<state*> newStates; //used to list all the new states so that they can be iterated correctly.
	std::map<std::string, state*> discoveredStates; //used to check if we have hit this state before.
	int depthLimit;
public:
	DepthFirstSearch(char *filename);
	virtual ~DepthFirstSearch();
	void run();
	void print();
};

#endif /* DEPTHFIRSTSEARCH_H_ */
