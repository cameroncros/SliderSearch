/*
 * GreedyBestFirstSearch.h
 *
 *  Created on: 25/03/2014
 *      Author: cameron
 */

#ifndef GREEDYBESTFIRSTSEARCH_H_
#define GREEDYBESTFIRSTSEARCH_H_

#include "TreeSearch.h"
#include <vector>
#include <map>
#include <string>

class GreedyBestFirstSearch: public TreeSearch {
private:
	std::map<std::string, state*> discoveredStates; //used to check if we have hit this state before.
	std::vector<state*> allStates; //used to keep track of all the new states so that they can be freed correctly.
	std::vector<state*> newStates; //used to list all the new states so that they can be iterated correctly.

	state *foundState;
	std::string finalFingerprint;
public:
	GreedyBestFirstSearch(char *fname);
	virtual ~GreedyBestFirstSearch();
	void run();
	void print();
};

#endif /* GREEDYBESTFIRSTSEARCH_H_ */
