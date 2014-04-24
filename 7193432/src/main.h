#ifndef MAIN_H
#define MAIN_H

#include <string>

enum searchtype {
	DFS,
	BFS,
	GBFS,
	AS,
	CUS1,
	CUS2,
	INVALID,
	GEN,
	LEN
};

void printusage(char *progname);
searchtype getSearchType(char *methodstr);
void loadFile(char *filename);

#endif
