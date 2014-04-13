/*
 * LengthFinder.h
 *
 *  Created on: Apr 13, 2014
 *      Author: Cameron
 */

#ifndef LENGTHFINDER_H_
#define LENGTHFINDER_H_

#include "TreeSearch.h"
#include <string>

/**
 * This class probably shouldnt be within tree search as it technically doesnt search,
 *  but it does use almost all of the same datastructures so it seems to be easiest
 */
class LengthFinder: public TreeSearch {
private:
	char *numMoves;
	char *width;
	char *height;
	int max;
public:
	LengthFinder(char *filename, char* width, char* height, char* numberOfMoves);
	virtual ~LengthFinder();

	void run();
	void print();
};


#endif /* LENGTHFINDER_H_ */
