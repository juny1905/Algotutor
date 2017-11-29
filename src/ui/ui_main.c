#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <curses.h>
#include <stddef.h>
#include <wchar.h>

#define CODE_VIEW_PART 0
#define SIMUL_VIEW_PART 1
#define COMMENT_PART 2

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
		mvaddstr(4+(i*2),4,(char *)_menu[_categoryNum][i]);
	}

	return;
}

int checkMenuLength(int _categoryNum, char *_menu[][5])
{

}

int main(void)
{
	int key = -1;
	int maxRow = 0;
	int maxCol = 0;
	int cursorCol = 3;
	int categoryNum = 0;
	int menuCur = 0;
	int maxMenu = 5;
	
	char *menu[5][5] = {
		{"Algotutor - v.1.0.0", "1. Start", "2. End", 0,0},
		{"Select category","1. scanf and printf","2. if","3. for loop","4. nested for loop"},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0}
	};

	/* Curses Initializations */
	init_ui();

	/* Check the Console size */
	getmaxyx(stdscr,maxRow,maxCol);

	/* Set the Background And Fonts Color */
	assume_default_colors(COLOR_WHITE,COLOR_BLACK);
	
	/* Show up interface Frame */
	printFrame(maxRow, maxCol);
	showMenu(maxRow,maxCol,menuCur,categoryNum,menu);
	
	while((key = getch()) != '#')
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
		}

		showMenu(maxRow,maxCol,menuCur,categoryNum,menu);

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
