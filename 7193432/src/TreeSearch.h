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
	UP = 1<<0,
	DOWN = 1<<1,
	LEFT = 1<<2,
	RIGHT = 1<<3,
	NOMV = 0
};

struct fingerprint {
	long val;
	std::string finger;
};

struct state {
	char cost;
	char depth;
	char **board;
	const state *parent;
	char childMoves;
	move mv;
	fingerprint finger;
};



class TreeSearch {

private:
	

public:
	int width;
	int height;
	std::string filename;
	state *initialState;
	state *finalState;
	std::vector<state*> allStates; //used to keep track of all the new states so that they can be freed correctly.
	state *foundState;
	int createdStates;
	int deletedStates;

	virtual ~TreeSearch();
	TreeSearch();
	virtual void run()=0;
	virtual void print()=0;
	void print(const char *str, int numbernodes);
	int depth();

	void loadFile(const char *filename);
	state *getNextState(const state *parent, move dir);

	void prettyPrintState(const state *st);
	void deleteState(state *st);
	int rateState(const state* given, const state* baseline);
	bool compareState(const state *first, const state *second);

	void fingerprintState(state *st);
	void cleanAllStates();
};

#endif /* TREESEARCH_H_ */
