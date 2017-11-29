#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>

void init_ui(void)
{
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	return;
}

int main(void)
{
	int key = -1;
	int maxCol = 0;
	int maxRow = 0;

	/* Curses Initializations */
	init_ui();

	/* Check the Console size */
	getmaxyx(stdscr,maxRow,maxCol);

	printf("%d %d\n",maxRow,maxCol);

	while(TRUE)
	{
		key = getch();
	}

	/* Exit */
	echo();
	refresh();
	endwin();

}
