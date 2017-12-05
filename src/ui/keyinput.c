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

#define DOC_DIR "./doc/"

void keyInput()
{

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

	return;
}
