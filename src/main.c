#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_THREADS 2

#include <ncurses.h>
#include <curses.h>
#include "uimain.h"
#include "uisub.h"

int xlimit = 0;
int ylimit = 0;

void *user_interface(void *_arg)
{
	uiMain(&xlimit,&ylimit);
	pthread_exit(NULL);
}

void *code_view(void *_arg)
{
	pthread_exit(NULL);
}

int main(int argc, char *argv)
{
	pthread_t threadPool[MAX_THREADS];

	int xlimit = 0;
	int ylimit = 0;

	/* create threads */
	for(int i=0; i<MAX_THREADS; i++)
	{
		int result = 0;
		if( i == 0 )
		{
			result = pthread_create(&threadPool[i], NULL,\
				user_interface, NULL);
		}
		else if( i == 1 )
		{
			result = pthread_create(&threadPool[i], NULL,\
				code_view, NULL);
		}

		if(result != 0)
		{
			perror("pthread_create : ");
			exit(1);
		}
	}

	for(int i=0; i<MAX_THREADS; i++)
	{
		pthread_join(threadPool[i], NULL);
	}

	return 0;
}
