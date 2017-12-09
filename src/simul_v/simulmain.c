#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#include "simulview.h"

void simulMain(struct category **_cur, int _ylimit, int _xlimit, int *_state ,int *_seqNum, int *viewFlag)
{
	//int prev_seqNum = 0;

	while((*_state) > EXIT)
	{
		if((*_state) == EVENT)
		{
			if((*viewFlag) == TRUE)
			{
				if(strcmp((*_cur)->cat_name,"printf.txt") == 0)
				{
					printfView(_ylimit, _xlimit, *_seqNum);
					(*viewFlag) = FALSE;
					refresh();
				}
			}
		}
	}

	return;
}
