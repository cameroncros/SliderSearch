/*
 * TreeSearch.h
 *
 *  Created on: 22/03/2014
 *      Author: cameron
 */

#ifndef TREESEARCH_H_
#define TREESEARCH_H_

#include "main.h"
#include <string>
#include <vector>

enum move {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NOMV
};

struct state {
	char cost;
	char depth;
	char **board;
	const state *parent;
	move mv;
	std::string fingerprint;
};

class TreeSearch {

private:
	std::string fingerprintState(state *st);

public:
	int width;
	int height;
	std::string filename;
	state *initialState;
	state *finalState;
	std::vector<state*> allStates; //used to keep track of all the new states so that they can be freed correctly.
	state *foundState;

	virtual ~TreeSearch();
	TreeSearch();
	virtual void run()=0;
	virtual void print()=0;
	void print(const char *str, int numbernodes);

	void loadFile(char *filename);
	state *getNextState(const state *parent, move dir);

	void prettyPrintState(const state *st);
	void deleteState(state *st);
	int rateState(const state* given, const state* baseline);
};

#endif /* TREESEARCH_H_ */
