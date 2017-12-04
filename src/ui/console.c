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
#include "console.h"

#define BUFSIZE 255;

/*
struct category
{
	char *cat_name;
	unsigned char action;
	struct category *bottom;
	struct category *next;	
};
*/

void init_ui(void)
{
	initscr();
	start_color();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	return;
}

void clearWorkspace(int _maxRow, int _maxCol, int _option)
{
	if( _option == CODE_VIEW_PART )
	{
		for(int i=1; i<(_maxRow-5); i++)
		{
			for(int j=1; j<(_maxCol/2); j++)
			{
				mvaddch(i,j,' ');
			}
		}
	}
	else if( _option == SIMUL_VIEW_PART )
	{
		for(int i=1; i<(_maxRow-5); i++)
		{
			for(int j=(_maxCol/2); j<(_maxCol-1); j++)
			{
				mvaddch(i,j,' ');
			}
		}
	}
	else if( _option == COMMENT_PART )
	{
		for(int i=(_maxRow-4); i<(_maxRow-1); i++)
		{
			for(int j=1; i<(_maxCol-1); j++)
			{
				mvaddch(i,j,' ');
			}
		}
	}
	
	return;
}

void printFrame(int _maxRow, int _maxCol)
{
	//int half_maxRow = _maxRow/2;
	int half_maxCol = _maxCol/2;
	int midRow = _maxRow-5;

	for(int i=0; i<_maxRow; i++)
	{
		for(int j=0; j<_maxCol; j++)
		{
			if( ((i == 0) || (i == midRow)) && \
			(j != half_maxCol) && (j < (_maxCol-1)) && (j > 0) )
			{
				mvaddch(i,j,'-'|A_BOLD);
			}
			else if( ((i == 0) || (i == midRow)) )
			{
				mvaddch(i,j,'+'|A_BOLD);
			}
			else if( (i > 0) && (i < midRow) && \
			((j==0) || (j==half_maxCol) || (j==(_maxCol-1))))
			{
				mvaddch(i,j,'|'|A_BOLD);
			}
			else if( ((i>(midRow-1)) && (i<(_maxRow-1))) && \
			((j==0) || (j==(_maxCol-1))))
			{
				mvaddch(i,j,'|'|A_BOLD);
			}
			else if( (i == (_maxRow-1)) && \
			((j==0) || (j==(_maxCol-1))))
			{
				mvaddch(i,j,'+'|A_BOLD);
			}
			else if( (i == (_maxRow-1)) )
			{
				mvaddch(i,j,'-'|A_BOLD);
			}
		}
	}
}

void mvaddstr_att(int _y, int _x, const char *_str, int _att)
{
	int i=0;

	while(TRUE)
	{
		if(*(_str+i) == 0)
		{
			break;
		}
		mvaddch(_y, _x+i, *(_str+i) | _att);
		i++;
	}

	return;
}

void showMenu(int _maxRow, int _maxCol, int _menuCur, int _categoryNum, struct category *_cat_head)
{
	struct category *cur = _cat_head;
	
	clearWorkspace(_maxRow,_maxCol,CODE_VIEW_PART);
	
	mvaddch(4+(_menuCur*2), 3, '>');

	{
			int j = 0;

			while(cur->bottom != NULL)
			{
				if(j == 0)
				{
					mvaddstr_att(4+(j*2), 4, \
					(char *)cur->cat_name, A_BOLD);
					//mvaddch(4+(j*2), 25, (char)(cur->action + '1'));
				}
				else
				{
					mvaddstr(4+(j*2), 4, (char *)cur->cat_name);
					//mvaddch(4+(j*2), 25, (char)(cur->action + '1'));
				}

				cur = cur->bottom;
				j++;
			}
	}
	return;
}

int create_directory(char *_doc, struct category **_cat_head)
{
	
	DIR *dir = opendir(_doc);
	struct dirent *dirs = NULL;
	char *temp[4] = {"Algotutor - v.1.1.0",\
					 "1. Start",\
					 "2. End", 0};
	struct category *cur = (*_cat_head);
	int i = 0;
	int cnt = 0;

	/* root category */
	while(temp[i] != 0)
	{	
			cur->cat_name = (char *)malloc(strlen(temp[i])+1);
			strcpy(cur->cat_name, temp[i]);

			if(i == 0)
				cur->action = 0; // do nothing
			else if(i == 1)
				cur->action = 1; // another category
			else if(i == 2)
				cur->action = -2; // exit program

			cur->next = (struct category *)malloc(sizeof(struct category));
			cur->next->cat_name = (char *)malloc(strlen(temp[i]+1));
			strcpy(cur->next->cat_name, temp[i]);
			cur->next->action = 0;
			cur->next->next = NULL;
			cur->next->bottom = NULL;

			cur->bottom = (struct category *)malloc(sizeof(struct category));
			cur = cur->bottom;
			cur->next = NULL;
			cur->bottom = NULL;

			i++;

	}

	/* read another category */
	cur = (*_cat_head);
	while(cur->action != 1)
	{
			cur = cur->bottom;
	}
	cur = cur->next;
	
	if( cur->cat_name != NULL )
	{
		cur->bottom = (struct category *)malloc(sizeof(struct category));
		cur->bottom->action = 0;
		cur->bottom->cat_name = NULL;
		cur->bottom->next = NULL;
		cur->bottom->bottom = NULL;
		cur = cur->bottom;
	}

	while((dirs = readdir(dir)) != NULL)	
	{
		if((strcmp(dirs->d_name,".") == 0) ||\
		   (strcmp(dirs->d_name,"..") == 0))
		{
			continue;
		}

		if(cur->cat_name == NULL)
		{
			cur->cat_name = (char *)malloc(strlen(dirs->d_name)+1);
			strcpy(cur->cat_name, dirs->d_name);
			cur->action = 1; 
		}

		if(cur->bottom == NULL)
		{
			cur->bottom = (struct category *)malloc(sizeof(struct category));
			cur->bottom->action = 0;
			cur->bottom->cat_name = NULL;
			cur->bottom->next = NULL;
			cur->bottom->bottom = NULL;
		}

		cur = cur->bottom;
		cnt++;
	}

	cur->cat_name = (char *)malloc(strlen("Go Back")+1);
	strcpy(cur->cat_name, "Go Back");
	cur->action = -1; 

	return cnt;

}

void selectMenu(int _menuCur, struct category **cur)
{
	//struct category *temp = (*cur);
	//int cnt = 0;

	for(int i=0; i<(_menuCur); i++)
	{
		if( (*cur)->bottom != NULL )
		{
			(*cur) = (*cur)->bottom;
		}
	}

	if( (*cur)->action == 0 )
	{
	}
	else if( (*cur)->action == 1 )
	{
		if( (*cur)->next != NULL )
		{
			(*cur) = (*cur)->next;
		}
	}
	
	return;
}

int countCategory(struct category *cur)
{
	int result = 0;
	
	while(cur->bottom != NULL)
	{
		cur = cur->bottom;
		result++;
	}

	return result;
}

int ui_main(int *_xlimit, int *_ylimit)
{
	wchar_t key = -1;
	int maxRow = 0;
	int maxCol = 0;
	int categoryNum = 0;
	int maxCat = 5;
	int menuCur = 0;
	int maxMenu = 5;	
	
	struct category *cur = NULL;
	struct category *prev = NULL;
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
	
	/*  */
	create_directory("../doc/",&cat_head);
	cur = cat_head;
	
	/* Show up interface Frame */
	printFrame(maxRow, maxCol);
	showMenu(maxRow,maxCol,menuCur,categoryNum,cat_head);
	selectMenu(menuCur,&cat_head);
	maxMenu = countCategory(cat_head);

	while((key = getch()) != 27)
	{

		showMenu(maxRow,maxCol,menuCur,categoryNum,cur);

		switch(key)
		{

			case KEY_UP:	
					
					mvaddch(4+(menuCur*2), 3, ' ');

					if((menuCur - 1) < 0)
					{
						menuCur = maxMenu - 1;
					}
					else
					{
						menuCur--;
					}

					mvaddch(4+(menuCur*2), 3, '>');	

					break;

			case KEY_DOWN:	
				
					mvaddch(4+(menuCur*2), 3, ' ');	
					menuCur = (menuCur + 1)%maxMenu;	
					mvaddch(4+(menuCur*2), 3, '>');

					break;

			case '\n':
					prev = cur;
					cur = prev;
					selectMenu(menuCur,&cur);
					maxMenu = countCategory(cur);
					showMenu(maxRow,maxCol,menuCur,categoryNum,cur);
					//showMenu(maxRow,maxCol,menuCur,categoryNum,cur);					
					categoryNum = (categoryNum+1)%maxCat;
					menuCur = 0;
					break;
		}

		// for debugging
		if( key == 'a' )
		{
			clearWorkspace(maxRow,maxCol,CODE_VIEW_PART);
		}
	}

	/* Exit */
	echo();
	refresh();
	endwin();
	return 0;
}
