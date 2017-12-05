#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <curses.h>
#include "cursor.h"
#include "loaddir.h"

int main(void)
{
	struct category *cat_head = NULL;
	struct category *cur = NULL;
	cat_head = (struct category *)malloc(sizeof(struct category));
	cat_head->cat_name = NULL;
	cat_head->cat_dir = NULL;
	cat_head->action = IDLE;
	cat_head->bottom = NULL;
	cat_head->next = NULL;
		
	load_directory("../../doc/",&cat_head);

	cur = cat_head;
	cur = cur->bottom->next->bottom;
	//cur = cur->bottom->next;

	//printf("%s : %s\n",cur->cat_name,cur->cat_dir);

	while(cur->bottom != NULL)
	{
		printf("%s : %s\n",cur->next->cat_name,cur->next->cat_dir);
		cur = cur->bottom;
	}

	return 0;
}
