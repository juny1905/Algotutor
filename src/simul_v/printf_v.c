#include <ncurses.h>
#include <unistd.h>

#include "simulview.h"
#include "uisub.h"

void printfView(int _xlimit, int _ylimit, int _seqNum)
{
	/* clearWorkspace : Simul view */
	//clearWorkspace(_ylimit,_xlimit,SIMUL_VIEW_PART);
	//printFrame(_ylimit,_xlimit);
	
	/* start function */
	if(_seqNum >= 0)
	{
		/* vertical line frame*/
		init_pair(1,COLOR_BLUE,COLOR_YELLOW);
		attron(COLOR_PAIR(1));
		mvaddstr(0,_xlimit/2+3,"< variable(in memory) >");
		attroff(COLOR_PAIR(1));
	
		mvaddch(_ylimit/2,_xlimit/2,'+'|A_BOLD);
		for(int i=(_xlimit/2)+1; i<(_xlimit-1); i++)
		{
			mvaddch(_ylimit/2,i,'-'|A_BOLD);
		}
		mvaddch(_ylimit/2,_xlimit-1,'+'|A_BOLD);
		attron(COLOR_PAIR(1));
		mvaddstr(_ylimit/2,_xlimit/2+3, "< console display(STDOUT) >");
		attroff(COLOR_PAIR(1));

		/* box */
		for(int i=(_xlimit/2)+3; i<(_xlimit-3); i++)
		{
			mvaddch(3,i,'-'|A_BOLD);
		}

		for(int i=(_xlimit/2)+3; i<(_xlimit-3); i++)
		{
			if((i == ((_xlimit/2)+3)) ||\
			   (i == (_xlimit-4)) ||
			   (i == (_xlimit/2)+(_xlimit/4)))
			{
				for(int j=4; j<7; j++)
				{
					mvaddch(j,i,'|'|A_BOLD);
				}
			}
		}

		for(int i=(_xlimit/2)+3; i<(_xlimit-3); i++)
		{
			mvaddch(7,i,'-'|A_BOLD);
		}

		/* print EMPTY */
		mvaddstr(5, (_xlimit/2)+6,"empty");

	}
	
	/* integer a = 9 */
	if(_seqNum >= 3)
	{
		if(_seqNum == 3)
		{
			init_pair(2,COLOR_BLUE,COLOR_YELLOW);
		}
		else
		{
			init_pair(2,COLOR_YELLOW,COLOR_BLUE);
		}
		attron(COLOR_PAIR(2));
		mvaddstr(5, (_xlimit/2)+5, "integer type a");
		mvaddstr(5, (_xlimit/2)+(_xlimit/4)+(_xlimit/8), "9");
		attroff(COLOR_PAIR(2));
	}
	
	/* printf */
	if(_seqNum >= 5)
	{
		if(_seqNum == 5)
		{
			init_pair(3,COLOR_BLUE,COLOR_YELLOW);
		}
		else
		{
			init_pair(3,COLOR_YELLOW,COLOR_BLUE);
		}
		attron(COLOR_PAIR(3));
		mvaddstr(_ylimit/2+2,_xlimit/2+2,"9");
		attroff(COLOR_PAIR(3));
	}
	
	//refresh();
	//sleep(1);

	return;

}
	
