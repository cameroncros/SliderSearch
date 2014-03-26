/*
 * BoardGenerator.h
 *
 *  Created on: Mar 26, 2014
 *      Author: cameron
 */

#ifndef BOARDGENERATOR_H_
#define BOARDGENERATOR_H_

#include "TreeSearch.h"
#include <string>

/**
 * This class probably shouldnt be within tree search as it technically doesnt search,
 *  but it does use almost all of the same datastructures so it seems to be easiest
 */
class BoardGenerator: public TreeSearch {
private:
	int numMoves;
	std::string initialFingerPrint;
	std::string finalFingerPrint;
public:
	BoardGenerator(char *filename, char* width, char* height, char* numberOfMoves);
	virtual ~BoardGenerator();

	void run();
	void print();
};

#endif /* BOARDGENERATOR_H_ */
