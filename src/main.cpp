#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
	searchtype method;
	if (argc != 3) {
		printusage(argv[0]);
	}
	method = getSearchType(argv[2]);
	if (method == INVALID) {
		printusage(argv[0]);
	}
	loadFile(argv[1]);
	switch (method) {
	case DFS:
		break;
	case BFS:
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
	return 1;
}

void loadFile(char *filename) {
	int totalvals;
	int tempval;
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
		perror("Failed to open file:");
	}
	fscanf(fp, "%i", &height);
	fscanf(fp, "%i", &width);
	totalvals = width*height;
	initialState.board = (int **)malloc(height *sizeof(int *));
	for (int i=0; i < height; i++) {
		initialState.board[i] = (int *)malloc(width*sizeof(int));
	}
	finalState.board = (int **)malloc(height *sizeof(int *));
	for (int i=0; i < height; i++) {
		finalState.board[i] = (int *)malloc(width*sizeof(int));
	}

	for (int i=0; i < totalvals; i++) {
		fscanf(fp, "%i;", &tempval);
		initialState.board[i/width][i%width]=tempval;
		printf("%i,%i - %i\n",i/width,i%width, tempval);
	}
	for (int i=0; i < totalvals; i++) {
		fscanf(fp, "%i;", &tempval);
		finalState.board[i/width][i%width]=tempval;
		printf("%i,%i - %i\n",i/width,i%width, tempval);
	}

}

searchtype getSearchType(char *methodstr) {

	if (strncmp("DFS", methodstr, 3) == 0) {
		return DFS;
	}
	if (strncmp("dfs", methodstr, 3) == 0) {
		return DFS;
	}
	if (strncmp("BFS", methodstr, 3) == 0) {
		return DFS;
	}
	if (strncmp("bfs", methodstr, 3) == 0) {
		return DFS;
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


