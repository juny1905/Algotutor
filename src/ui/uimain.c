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
#include "mykey.h"
#include "cursor.h"

#define BUFSIZE 255;

//#define DOC_DIR "./doc/"

int uiMain(int *_xlimit, int *_ylimit, int *_menuCur, int *_maxMenu, int *_globalState, int *_keyFlag, struct category **_cat_head)
{
	//char doc_dir[20] = {0,};
	//struct category *cur = (*_cat_head);

	int maxRow = 0;
	int maxCol = 0;
	int categoryNum = 0;
	
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
	//load_directory(DOC_DIR,&_cat_head);
	//cur = _cat_head;
	
	/* Show up interface Frame */
	printFrame(maxRow, maxCol);
	showMenu(maxRow,maxCol,(*_menuCur),categoryNum,(*_cat_head));
	//selectMenu(menuCur,&cat_head);
	(*_maxMenu) = countCategory((*_cat_head));

	/* pending */
	(*_globalState) = IDLE;
	while(1)
	{
		if((*_globalState) == STRT && \
		   (*_keyFlag) == KEY_FLAG_ENTER )  
		{
			//(*_globalState) = cursor_select(&menuCur, _cat_head);
			showMenu(maxRow,maxCol,(*_menuCur),categoryNum,(*_cat_head));
			(*_maxMenu) = countCategory((*_cat_head));
			refresh();
			(*_keyFlag) = KEY_FLAG_OFF;
		}
		else if((*_globalState) == DIRS && \
			(*_keyFlag) == KEY_FLAG_ENTER)
		{	
			//(*_globalState) = cursor_select(&menuCur, _cat_head);
			showMenu(maxRow,maxCol,(*_menuCur),categoryNum,(*_cat_head));
			(*_maxMenu) = countCategory((*_cat_head));
			refresh();
			(*_keyFlag) = KEY_FLAG_OFF;
		}
		else if((*_globalState) == EVENT && \
			(*_keyFlag) == KEY_FLAG_ENTER)
		{
			//clearWorkspace(maxRow,maxCol,CODE_VIEW_PART);
			
			//(*_keyFlag) = KEY_FLAG_OFF;
		}
		else if((*_globalState) == -2)
		{
			break;
		}

		if((*_globalState) < EVENT && (*_keyFlag) == KEY_FLAG_UP)
		{
			//cursor_up(&menuCur, &maxMenu);
			(*_keyFlag) = KEY_FLAG_OFF;
		}
		else if((*_globalState) < EVENT && (*_keyFlag) == KEY_FLAG_DOWN)
		{
			//cursor_down(&menuCur, &maxMenu);
			(*_keyFlag) = KEY_FLAG_OFF;
		}

		//sleep(1);
	}

	/* Exit */
	echo();
	refresh();
	endwin();
	return 0;
}

/*
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
*/
