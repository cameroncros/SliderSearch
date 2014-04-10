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

class CustomUniformedDepthSearch: public TreeSearch {
private:
	int depthLimit;
public:
	CustomUniformedDepthSearch(char *filename);
	virtual ~CustomUniformedDepthSearch();
	void run();
	void print();

	bool evaluateState(state *workingState);
};

#endif /* CUSTOMUNINFORMEDDEPTHSEARCH_H_ */
