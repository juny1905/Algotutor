#ifndef UI_CONSOLE_H
#define UI_CONSOLE_H

#define CODE_VIEW_PART 0
#define SIMUL_VIEW_PART 1
#define COMMENT_PART 2

struct category
{
	char *cat_name;
	unsigned char action;
	struct category *bottom;
	struct category *next;
};

void init_ui(void);
void clearWorkspace(int _maxRow, int _maxCol, int _option);
void printFrame(int _maxRow, int _maxCol);
void mvaddstr_att(int _y, int _x, const char *_str, int _att);
void showMenu(int _maxRow, int _maxCol, int _menuCur, int _categoryNum, struct category *_cat_head);
int create_directory(char *_doc, struct category **_cat_head);
void selectMenu(int _menuCur, struct category **cur);
int countCategory(struct category *cur);
int ui_main(int *_xlimit, int *_ylimit);

#endif
