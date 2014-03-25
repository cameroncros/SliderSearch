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

enum move {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

struct state {
	int cost;
	int depth;
	int **board;
	const state *parent;
	move mv;
};

class TreeSearch {

public:


	int width;
	int height;
	std::string filename;
	state *initialState;
	state *finalState;


	virtual ~TreeSearch();
	TreeSearch();
	virtual void run()=0;
	virtual void print()=0;

	void loadFile(char *filename);
	state *getNextState(const state *parent, move dir);
	std::string fingerprintState(state *st);
	void prettyPrintState(const state *st);
	void deleteState(state *st);
	double rateState(const state* given, const state* baseline);
};

#endif /* TREESEARCH_H_ */
