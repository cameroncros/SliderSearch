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
#include <stack>
#include <string>

class DepthFirstSearch: public TreeSearch {
private:
	int depthLimit;
	std::stack<state *> allStates;
	std::stack<state *> nextState;
public:
	DepthFirstSearch(char *filename);
	virtual ~DepthFirstSearch();
	void run();
	void print();
};

#endif /* DEPTHFIRSTSEARCH_H_ */
