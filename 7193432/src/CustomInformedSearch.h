/*
 * CustomInformedSearch.h
 *
 *  Created on: Apr 11, 2014
 *      Author: Cameron
 */

#ifndef CUSTOMINFORMEDSEARCH_H_
#define CUSTOMINFORMEDSEARCH_H_

#include "TreeSearch.h"
#include <deque>
#include <map>
#include <string>

class CustomInformedSearch: public TreeSearch {
private:
	std::deque<state*> newStates; //used to list all the new states so that they can be iterated correctly.
	std::map<std::string, state*> discoveredStates; //used to check if we have hit this state before.

public:
	CustomInformedSearch(char *fname);
	virtual ~CustomInformedSearch();
	void run();
	void print();
};

#endif /* CUSTOMINFORMEDSEARCH_H_ */
