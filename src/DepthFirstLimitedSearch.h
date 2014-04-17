/*
 * DepthFirstSearch.h
 *
 *  Created on: 23/03/2014
 *      Author: cameron
 */

#ifndef DEPTHFIRSTLIMITEDSEARCH_H_
#define DEPTHFIRSTLIMITEDSEARCH_H_

#include "TreeSearch.h"
#include "main.h"
#include <map>
#include <vector>
#include <stack>
#include <string>

class DepthFirstLimitedSearch: public TreeSearch {
private:
	int depthLimit;
public:
	DepthFirstLimitedSearch(char *filename);
	virtual ~DepthFirstLimitedSearch();
	void run();
	void print();

	bool evaluateState(state *workingState);
};

#endif /* DEPTHFIRSTLIMITEDSEARCH_H_ */
