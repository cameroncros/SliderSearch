/*
 * GreedyBestFirstSearch.h
 *
 *  Created on: 25/03/2014
 *      Author: cameron
 */

#ifndef GREEDYBESTFIRSTSEARCH_H_
#define GREEDYBESTFIRSTSEARCH_H_

#include "TreeSearch.h"
#include <deque>
#include <map>
#include <string>

class GreedyBestFirstSearch: public TreeSearch {
private:
	int depthLimit;
public:
	GreedyBestFirstSearch(char *fname);
	virtual ~GreedyBestFirstSearch();
	void run();
	void print();

	bool evaluateState(state *workingState);
};

#endif /* GREEDYBESTFIRSTSEARCH_H_ */
