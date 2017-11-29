#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <curses.h>

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

int main(void)
{
	int key = -1;
	int maxRow = 0;
	int maxCol = 0;
	int cursorCol = 3;

	/* Curses Initializations */
	init_ui();

	/* Check the Console size */
	getmaxyx(stdscr,maxRow,maxCol);

	/* Set the Background And Fonts Color */
	assume_default_colors(COLOR_WHITE,COLOR_BLACK);
	
	/* Show up interface Frame */
	printFrame(maxRow, maxCol);

	mvaddstr(4,2,"Algotutor");

	while((key = getch()) != '#')
	{
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
