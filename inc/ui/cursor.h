#ifndef STATE_INFO_H
#define STATE_INFO_H

#define IDLE 0
#define STRT 1
#define DIRS 2
#define EVENT 3
#define BACK -1
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

#ifndef CUR_FUNCS_H
#define CUR_FUNCS_H

void cursor_up(int *_menuCur, int *_maxMenu);
void cursor_down(int *_menuCur, int *_maxMenu);
int cursor_select(int *_menuCur, struct category **cur);

#endif
