/*
 * LengthFinder.cpp
 *
 *  Created on: Apr 13, 2014
 *      Author: Cameron
 */

#include "LengthFinder.h"
#include "TreeSearch.h"
#include "BoardGenerator.h"
#include "CustomUninformedDepthSearch.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>



LengthFinder::LengthFinder(char* fname, char* w, char* h,
		char* numberOfMoves) {
	filename = fname;
	width = w;
	height = h;
	numMoves = numberOfMoves;
	max = 0;
	// TODO Auto-generated constructor stub

}

LengthFinder::~LengthFinder() {
	// TODO Auto-generated destructor stub
}

void LengthFinder::run() {
	for (int i = 0; i < 100; i++) {
		BoardGenerator *bg = new BoardGenerator(filename.c_str(), width, height, numMoves);
		bg->run();
		bg->print();
		TreeSearch *bfs = new CustomUninformedDepthSearch(filename.c_str());
		bfs->run();
		if (bfs->depth() > max) {
			max = bfs->depth();
		}
		delete(bg);
		delete(bfs);




	}
}

void LengthFinder::print() {
	std::cout << max << std::endl;

}

