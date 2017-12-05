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

#ifndef KEY_HANDLER_H
#define KEY_HANDLER_H

void keyHandler(int *_menuCur, int *_maxMenu, int *_state, int *_keyFlag, struct category **_cat_head);

#endif
