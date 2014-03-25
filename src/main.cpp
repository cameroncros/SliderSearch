#include "main.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "TreeSearch.h"
#include "DepthFirstSearch.h"
#include "BreadthFirstSearch.h"

int main(int argc, char **argv) {
	searchtype method;
	TreeSearch *search;
	if (argc != 3) {
		printusage(argv[0]);
	}
	method = getSearchType(argv[2]);
	if (method == INVALID) {
		printusage(argv[0]);
	}
	switch (method) {
	case DFS:
		search = new DepthFirstSearch(argv[1]);
		break;
	case BFS:
		search = new BreadthFirstSearch(argv[1]);
		break;
	case GBFS:
		break;
	case AS:
		break;
	case CUS1:
		break;
	case CUS2:
		break;
	case INVALID:
		break;
	}
	search->run();
	search->print();
	delete(search);
	return 1;
}



searchtype getSearchType(char *methodstr) {

	if (strncmp("DFS", methodstr, 3) == 0) {
		return DFS;
	}
	if (strncmp("dfs", methodstr, 3) == 0) {
		return DFS;
	}
	if (strncmp("BFS", methodstr, 3) == 0) {
		return BFS;
	}
	if (strncmp("bfs", methodstr, 3) == 0) {
		return BFS;
	}
	if (strncmp("GBFS", methodstr, 4) == 0) {
		return GBFS;
	}
	if (strncmp("gbfs", methodstr, 4) == 0) {
		return GBFS;
	}
	if (strncmp("AS", methodstr, 2) == 0) {
		return AS;
	}
	if (strncmp("as", methodstr, 2) == 0) {
		return AS;
	}
	if (strncmp("CUS1", methodstr, 4) == 0) {
		return CUS1;
	}
	if (strncmp("cus1", methodstr, 4) == 0) {
		return CUS1;
	}
	if (strncmp("CUS2", methodstr, 4) == 0) {
		return CUS2;
	}
	if (strncmp("cus2", methodstr, 4) == 0) {
		return CUS2;
	}
	return INVALID;
}

void printusage(char *progname) {
	printf("Usage: %s [filename] [method]\n"
			"Methods:\n"
			"DFS: Depth First Search\n"
			"BFS: Breadth First Search\n"
			"GBFS:\n"
			"AS:\n"
			"CUS1: Uninformed Search\n"
			"CUS2: Informed Search", progname);
	exit(1);
}



