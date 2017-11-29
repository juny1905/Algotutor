#include <stdio.h>
#include <term.h>
#include <termios.h>
#include <unistd.h>
#include <ncurses.h>

/*
int getch(void)
{
	int ch;
	struct termios buf;
	struct termios save;

	tcgetattr(0, &save);
	buf = save;
	buf.c_lflag &= ~(ICANON|ECHO);
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;
	tcsetattr(0, TCSAFLUSH, &buf);
	ch = getchar();
	//printf("%d ",ch);
	//ch = getchar();
	//printf("%d\n",ch);
	tcsetattr(0, TCSAFLUSH, &save);
	return ch;
}
*/

int main(void)
{

	int key = -1;

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	key = getch();
	printf("%d\n",key);

	while((key = getch()) != '#')
	{
		switch(key)
		{
			case KEY_UP: printf("up\n");
				     break;
			case KEY_DOWN: printf("down\n");
				       break;
			case KEY_LEFT: printf("left\n");
				       break;
			case KEY_RIGHT: printf("right\n");
					break;
			default: ;//printf("%d\n",key);
		}
	}

	refresh();
	echo();
	endwin();

	return 0;

}
