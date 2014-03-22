enum searchtype {
	DFS,
	BFS,
	GBFS,
	AS,
	CUS1,
	CUS2,
	INVALID,
};

enum move {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

struct state {
	int **board;
	state *parent;
	move mv;

};

int width;
int height;
state initialState;
state finalState;

void printusage(char *progname);
searchtype getSearchType(char *methodstr);
void loadFile(char *filename);
