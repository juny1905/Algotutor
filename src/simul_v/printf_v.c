#include <ncurses.h>
#include <unistd.h>
#include "simulview.h"


void printfView(int _xlimit, int _ylimit, int _seqNum)
{

	for(int i=(_ylimit/2); i<(_ylimit); i++)
	{
		mvaddch(_xlimit/2,i,'-');
	}

	refresh();
	sleep(1);

	return;

}
	
