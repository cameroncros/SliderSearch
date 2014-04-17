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
	UP = 0b0001,
	DOWN = 0b0010,
	LEFT = 0b0100,
	RIGHT = 0b1000,
	NOMV = 0b0000
};

struct fingerprint {
	double val;
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
};

#endif /* TREESEARCH_H_ */
