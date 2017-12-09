#ifndef STATE_INFO_H
#define STATE_INFO_H

#define IDLE 0
#define STRT 1
#define DIRS 2
#define EVENT 3
#define INIT -1
#define EXIT -2

#endif

#ifndef STRUCT_CAT_H
#define STRUCT_CAT_H

struct category
{
	char *cat_name;
	char *cat_dir;
	unsigned char action;
	struct category *bottom;
	struct category *next;
};

#endif

#ifndef SIMUL_VIEW_H
#define SIMUL_VIEW_H

void simulMain(struct category **_cur, int _ylimit, int _xlimit, int *_state, int *_seqNum, int *viewFlag);

void printfView(int _ylimit, int _xlimit, int _seqNum);

#endif
