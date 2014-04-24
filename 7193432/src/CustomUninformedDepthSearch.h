/*
 * CustomUniformedDepthSearch.h
 *
 *  Created on: 23/03/2014
 *      Author: cameron
 */

#ifndef CUSTOMUNINFORMEDDEPTHSEARCH_H_
#define CUSTOMUNINFORMEDDEPTHSEARCH_H_

#include "TreeSearch.h"
#include "main.h"
#include <map>
#include <vector>
#include <stack>
#include <string>

class CustomUninformedDepthSearch: public TreeSearch {
private:
	int depthLimit;
	std::stack<state *> nextState;
public:
	CustomUninformedDepthSearch(const char *filename);
	virtual ~CustomUninformedDepthSearch();
	void run();
	void print();
};

#endif /* CUSTOMUNINFORMEDDEPTHSEARCH_H_ */
