#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <curses.h>
#include <stddef.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include "console.h"

#define BUFSIZE 255;

int create_directory(char *_doc, struct category **_cat_head)
{
	
	DIR *dir = opendir(_doc);
	struct dirent *dirs = NULL;
	char *temp[4] = {"Algotutor - v.1.1.0",\
					 "1. Start",\
					 "2. End", 0};
	struct category *cur = (*_cat_head);
	int i = 0;
	int cnt = 0;

	/* root category */
	while(temp[i] != 0)
	{	
			cur->cat_name = (char *)malloc(strlen(temp[i])+1);
			strcpy(cur->cat_name, temp[i]);

			if(i == 0)
				cur->action = 0; // do nothing
			else if(i == 1)
				cur->action = 1; // another category
			else if(i == 2)
				cur->action = -2; // exit program

			cur->next = (struct category *)malloc(sizeof(struct category));
			cur->next->cat_name = (char *)malloc(strlen(temp[i]+1));
			strcpy(cur->next->cat_name, temp[i]);
			cur->next->action = 0;
			cur->next->next = NULL;
			cur->next->bottom = NULL;

			cur->bottom = (struct category *)malloc(sizeof(struct category));
			cur = cur->bottom;
			cur->next = NULL;
			cur->bottom = NULL;

			i++;

	}

	/* read another category */
	cur = (*_cat_head);
	while(cur->action != 1)
	{
			cur = cur->bottom;
	}
	cur = cur->next;
	
	if( cur->cat_name != NULL )
	{
		cur->bottom = (struct category *)malloc(sizeof(struct category));
		cur->bottom->action = 0;
		cur->bottom->cat_name = NULL;
		cur->bottom->next = NULL;
		cur->bottom->bottom = NULL;
		cur = cur->bottom;
	}

	while((dirs = readdir(dir)) != NULL)	
	{
		if((strcmp(dirs->d_name,".") == 0) ||\
		   (strcmp(dirs->d_name,"..") == 0))
		{
			continue;
		}

		if(cur->cat_name == NULL)
		{
			cur->cat_name = (char *)malloc(strlen(dirs->d_name)+1);
			strcpy(cur->cat_name, dirs->d_name);
			cur->action = 1; 
		}

		if(cur->bottom == NULL)
		{
			cur->bottom = (struct category *)malloc(sizeof(struct category));
			cur->bottom->action = 0;
			cur->bottom->cat_name = NULL;
			cur->bottom->next = NULL;
			cur->bottom->bottom = NULL;
		}

		cur = cur->bottom;
		cnt++;
	}

	cur->cat_name = (char *)malloc(strlen("Go Back")+1);
	strcpy(cur->cat_name, "Go Back");
	cur->action = -1; 

	return cnt;

}

