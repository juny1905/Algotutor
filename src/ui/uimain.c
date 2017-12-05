#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <curses.h>
#include <stddef.h>
#include <wchar.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#include "loaddir.h"
#include "uisub.h"

#define BUFSIZE 255;

#define DOC_DIR "../../doc/"

int uiMain(int *_xlimit, int *_ylimit)
{
	//char doc_dir[20] = {0,};
	int maxRow = 0;
	int maxCol = 0;
	int categoryNum = 0;
	int maxCat = 5;
	int menuCur = 0;
	int maxMenu = 5;	
	
	struct category *cur = NULL;
	struct category *cat_head = (struct category *)malloc(sizeof(struct category));
	cat_head->action = 0;
	cat_head->bottom = NULL;
	cat_head->next = NULL;

	/* Curses Initializations */
	init_ui();

	/* Check the Console size */
	getmaxyx(stdscr,maxRow,maxCol);
	(*_xlimit) = maxRow;
	(*_ylimit) = maxCol;

	/* Set the Background And Fonts Color */
	assume_default_colors(COLOR_YELLOW,COLOR_BLUE);
	
	/* Load Directory & create Catrgory */
	//strcpy(doc_dir,"./doc/");
	load_directory(DOC_DIR,&cat_head);
	cur = cat_head;
	
	/* Show up interface Frame */
	printFrame(maxRow, maxCol);
	showMenu(maxRow,maxCol,menuCur,categoryNum,cat_head);
	//selectMenu(menuCur,&cat_head);
	maxMenu = countCategory(cat_head);

	/* pending */
	while(1)
	{
	}

	/* Exit */
	echo();
	refresh();
	endwin();
	return 0;
}

int main(void)
{
	int xlimit, ylimit;
	//uiMain(&xlimit, &ylimit);

	//init_ui();
	initscr();
	start_color();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	assume_default_colors(COLOR_YELLOW, COLOR_BLUE);
	while(1)
	{
	}

	return 0;
}
