/*
 * GreedyBestFirstSearch.h
 *
 *  Created on: 25/03/2014
 *      Author: cameron
 */

#ifndef GREEDYBESTFIRSTSEARCH_H_
#define GREEDYBESTFIRSTSEARCH_H_

#include "TreeSearch.h"
#include <stack>
#include <map>
#include <string>

class GreedyBestFirstSearch: public TreeSearch {
private:
	int depthLimit;
	std::stack<state *> allStates;
	std::stack<state *> nextState;
public:
	GreedyBestFirstSearch(char *fname);
	virtual ~GreedyBestFirstSearch();
	void run();
	void print();



};

#endif /* GREEDYBESTFIRSTSEARCH_H_ */
