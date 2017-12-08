#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_THREADS 4
#define DOC_DIR "./doc/"

#include <ncurses.h>
#include <curses.h>

#include "uimain.h"
#include "uisub.h"
#include "keyhandler.h"
#include "loaddir.h"
#include "mykey.h"

#include "viewcode.h"
#include "readcode.h"


int xlimit = 0;
int ylimit = 0;
int menuCur = 0;
int maxMenu = 3;
int globalState = INIT;
int keyFlag = KEY_FLAG_OFF;

int seqNum = 0; // To indicate current code squence;

struct category *catHead = NULL;

void *user_interface(void *_arg)
{
	catHead = (struct category *)malloc(sizeof(struct category));
	memset(catHead, 0, sizeof(struct category));
	load_directory(DOC_DIR, &catHead);
	uiMain(&xlimit,&ylimit,&menuCur,&maxMenu,&globalState,&keyFlag,\
		&catHead);
	pthread_exit(NULL);
}

void *code_view(void *_arg)
{
	LINE *para = (LINE *)malloc(sizeof(LINE));
	int line_para = 0;
	while(TRUE)
	{
		if(globalState == EVENT && keyFlag == KEY_FLAG_ENTER)
		{
			para = ReadFile(catHead->cat_dir);
			line_para = countPara(para);
			keyFlag = KEY_FLAG_OFF;	
		}
		else if(globalState == EVENT)
		{
			currentLine(0,3,ylimit,xlimit,seqNum);
			printPara(3,2,ylimit,xlimit,seqNum,para);
			if( keyFlag == KEY_FLAG_ENTER && seqNum != line_para)
			{
				seqNum++;
				keyFlag = KEY_FLAG_OFF;
			}

			refresh();
			sleep(1);
		}	
		else if(globalState == EXIT)
		{
			clearWorkspace(ylimit,xlimit,CODE_VIEW_PART);
			clearWorkspace(ylimit,xlimit,COMMENT_PART);

			seqNum = 0;
			break;
		}
	}
	pthread_exit(NULL);
}

void *simul_view(void *_arg)
{
	pthread_exit(NULL);
}

void *keyhandler(void *_arg)
{
	keyHandler(&menuCur,&maxMenu,&globalState,&keyFlag,&catHead);
	pthread_exit(NULL);
}

int main(int argc, char *argv)
{
	pthread_t threadPool[MAX_THREADS];

	//int xlimit = 0;
	//int ylimit = 0;

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
			while(globalState == INIT);
			result = pthread_create(&threadPool[i], NULL,\
				keyhandler, NULL);
		}
		else if( i == 2 )
		{	
			result = pthread_create(&threadPool[i], NULL,\
				code_view, NULL);
		}
		else if( i == 3 )
		{
			result = pthread_create(&threadPool[i], NULL,\
				simul_view, NULL);
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
