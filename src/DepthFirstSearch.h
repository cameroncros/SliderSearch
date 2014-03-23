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
	std::string filename;
	std::map<std::string, state*> discoveredStates; //used to check if we have hit this state before.
	std::vector<state*> allStates; //used to keep track of all the new states so that they can be freed correctly.
	std::stack<state*> newStates; //used to list all the new states so that they can be iterated correctly.

	state *workingState;
	state *foundState;
	std::string finalFingerprint;
public:
	DepthFirstSearch(char *filename);
	virtual ~DepthFirstSearch();
	void run();
	void print();
};

#endif /* DEPTHFIRSTSEARCH_H_ */
