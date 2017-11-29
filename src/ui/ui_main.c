#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <curses.h>

void init_ui(void)
{
	initscr();
	start_color();
	raw();
	keypad(stdscr, TRUE);
	noecho();
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

	/* Curses Initializations */
	init_ui();

	/* Check the Console size */
	getmaxyx(stdscr,maxRow,maxCol);

	/* Set the Background And Fonts Color */
	assume_default_colors(COLOR_WHITE,COLOR_BLACK);
	
	printFrame(maxRow, maxCol);

	while((key = getch()) != '#')
	{
		
	}

	/* Exit */
	echo();
	refresh();
	endwin();

}
