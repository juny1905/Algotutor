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

#define CODE_VIEW_PART 0
#define SIMUL_VIEW_PART 1
#define COMMENT_PART 2

#define BUFSIZE 255;

struct category
{
	char *cat_name;
	unsigned char action;
	struct category *cat_bottom;
	struct category *cat_next;	
};

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
	int half_maxRow = _maxRow/2;
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

void showMenu(int _maxRow, int _maxCol, int _menuCur, int _categoryNum, char *_menu[][5])
{
	/*
	char *menu[5][5] = {
		{"Algotutor - v.1.0.0", "1. Start", "2. End", 0,0},
		{"Select category","1. scanf and printf","2. if","3. for loop","4. nested for loop"},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0}
	};
	*/

	clearWorkspace(_maxRow,_maxCol,CODE_VIEW_PART);
	
	//mvadd_wch(4+(_menuCur*2),3,0x25B6);
	mvaddch(4+(_menuCur*2),3,'>');

	for(int i=0; i<5; i++)
	{
		if(i == 0)
		{
			mvaddstr_att(4+(i*2),4, \
			(char *)_menu[_categoryNum][i], A_BOLD);
		}
		else
		{
			mvaddstr(4+(i*2),4,(char *)_menu[_categoryNum][i]);
		}
	}

	return;
}

int checkMenuLength(int _categoryNum, char *_menu[][5])
{

}

void read_directory(char *_doc, struct category *_cat_head)
{
	
	DIR *dir = opendir(_doc);
	struct dirent *dirs = NULL;
	char *temp[4] = {"Algotutor - v.1.1.0",\
					 "1. Start",\
					 "2. End", 0};
	struct category *cur = _cat_head;
	int i = 0;

	/* read category */
	dirs = readdir(dir);
	
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
				cur->action = -1; // exit program

			cur->bottom = (struct category *)malloc(sizeof(struct category));
			cur->next = (struct category *)malloc(sizeof(struct category));
			cur->next->cat_name = (char *)malloc(strlen(temp[i]+1));
			strcpy(cur->next->cat_name, temp[i]);
			cur->next->next = NULL;
			cur->next->bottom = NULL;

			cur = cur->bottom;
			cur->next = NULL;
			cur->bottom = NULL;
	}

	/* another category */
	cur = _cat_head;
	while(cur->action != 1)
	{
			cur = cur->bottom;
	}

	cur->next = (struct category *)malloc(sizeof(struct category));
	

	head->cat_name = (char *)malloc(strlen(dirs->d_name)+1);
	strcpy(head->cat_name,dirs->d_name);
	head->next = NULL;
	//mvaddstr(10,2,head->cat_name);

	{
		struct menu *cur = head;

		while((dirs = readdir(dir)) != NULL)
		{
				if((strcmp(dirs->d_name,".") != 0) &&\
				   (strcmp(dirs->d_name,"..") != 0))
				{
					cur->next = (struct menu *)malloc(sizeof(struct menu));
					cur->next->cat_name = (char *)malloc(strlen(dirs->d_name)+1);
					strcpy(cur->cat_name,dirs->d_name);
					cur->next->next = NULL;
					cur = cur->next;
				}
			
		}

		//mvaddstr(20,2,cur->cat_name);
	}
}


int main(void)
{
	wchar_t key = -1;
	int maxRow = 0;
	int maxCol = 0;
	int cursorCol = 3;
	int categoryNum = 0;
	int maxCat = 5;
	int menuCur = 0;
	int maxMenu = 5;	

	struct category *cat_head = (struct category *)malloc(sizeof(struct category));
	cat_head->action = 0;
	cat_head->cat_bottom = NULL;
	cat_head->cat_next = NULL;

	/* Curses Initializations */
	init_ui();

	/* Check the Console size */
	getmaxyx(stdscr,maxRow,maxCol);

	/* Set the Background And Fonts Color */
	assume_default_colors(COLOR_YELLOW,COLOR_BLUE);
	
	/* Show up interface Frame */
	printFrame(maxRow, maxCol);
	//showMenu(maxRow,maxCol,menuCur,categoryNum,menu);
	


	/* testing */
	/*	
	{
		int i = 0;

		while(head != NULL)
		{
			mvaddstr(i,2,head->cat_name);
			head = head->next;
			i++;
		}
	}
	*/

	while((key = getch()) != 27)
	{
		switch(key)
		{
			case KEY_UP:	if((menuCur - 1) < 0)
					{
						menuCur = maxMenu - 1;
					}
					else
					{
						menuCur--;
					}
					break;

			case KEY_DOWN:	menuCur = (menuCur + 1)%maxMenu;
					break;

			case '\n':	categoryNum = (categoryNum+1)%maxCat;
					menuCur = 0;
					break;
		}

		//showMenu(maxRow,maxCol,menuCur,categoryNum,menu);

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

}
