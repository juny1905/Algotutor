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

#ifndef UI_SUB_H
#define UI_SUB_H

#define CODE_VIEW_PART 0
#define SIMUL_VIEW_PART 1
#define COMMENT_PART 2

void init_ui(void);
void clearWorkspace(int _maxRow, int _maxCol, int _option);
void printFrame(int _maxRow, int _maxCol);
void mvaddstr_att(int _y, int _x, const char *_str, int _att);
void showMenu(int _maxRow, int _maxCol, int _menuCur, int _categoryNum, struct category *_cat_head);
int countCategory(struct category *cur);

#endif
