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

#ifndef LOAD_DIR_FUNCS_H
#define LOAD_DIR_FUNCS_H

int load_directory(char *_doc, struct category **_cat_head);

#endif
