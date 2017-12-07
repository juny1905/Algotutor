#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <curses.h>
#include <stddef.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#include "loaddir.h"

#define BUFSIZE 255

/* in loaddir.h */
/*
#define IDLE 0
#define STRT 1
#define DIRS 2
#define EVENT 3
#define BACK -1
#define EXIT -2

struct category
{
	char *cat_name;
	char *cat_dir;
	unsigned char action;
	struct category *bottom;
	struct category *next;
};
*/

int load_directory(char *_doc, struct category **_cat_head)
{
	
	DIR *dir = NULL;
	struct dirent *dirs = NULL;
	char *temp[4] = {"Algotutor - v.1.1.0",\
					 "1. Start",\
					 "2. End", 0};
	char *catArray[10] = {0,};
	struct category *cur = (*_cat_head);
	struct category *prev_cur = NULL;
	int i = 0;
	int cnt = 0;

	cur->cat_dir = NULL;

	/* root category */
	while(temp[i] != 0)
	{	
			cur->cat_name = (char *)malloc(strlen(temp[i])+1);
			strcpy(cur->cat_name, temp[i]);

			if(i == 0)
				cur->action = IDLE; // do nothing
			else if(i == 1)
				cur->action = STRT; // another category
			else if(i == 2)
				cur->action = EXIT; // exit program

			cur->next = (struct category *)malloc(sizeof(struct category));
			cur->next->cat_name = (char *)malloc(strlen(temp[i]+1));
			strcpy(cur->next->cat_name, temp[i]);
			cur->next->action = IDLE;
			cur->next->next = NULL;
			cur->next->bottom = NULL;
			cur->next->cat_dir = NULL;

			cur->bottom = (struct category *)malloc(sizeof(struct category));
			cur = cur->bottom;
			cur->cat_dir = NULL;
			cur->next = NULL;
			cur->bottom = NULL;

			i++;

	}

	/* choose the start */
	cur = (*_cat_head);
	while(cur->action != STRT)
	{
		cur = cur->bottom;
	}
	cur = cur->next;

	/* remember cur pointer */
	if( cur->cat_name != NULL )
	{
		cur->bottom = (struct category *)malloc(sizeof(struct category));
		cur->bottom->action = IDLE;
		cur->bottom->cat_name = NULL;
		cur->bottom->cat_dir = NULL;
		cur->bottom->next = NULL;
		cur->bottom->bottom = NULL;
		cur = cur->bottom;
	}
	prev_cur = cur;

	/* read and make ordered */
	dir = opendir(_doc);
	i = 0;
	while((dirs = readdir(dir)) != NULL)
	{
		if((strcmp(dirs->d_name,".") == 0) ||\
		   (strcmp(dirs->d_name,"..") == 0))
		{
			continue;
		}

		/* really special case */
		if(strcmp(dirs->d_name,"test.txt") == 0)
		{
			continue;
		}

		catArray[i] = (char *)malloc(strlen(dirs->d_name)+1);
		strcpy(catArray[i],dirs->d_name);
		//printf("%s :%d\n",catArray[i],i);
		i++;
	}

	for(int n=0; n<i; n++)
	{
		for(int m=n; m<i; m++)
		{
			if(strcmp(catArray[n],catArray[m]) > 0)
			{
				char *str_temp = catArray[n];
				catArray[n] = catArray[m];
				catArray[m] = str_temp;
			}
		}
	}

	/* add To SLL value of catArray >> (cat_cat_dir) */
	for(int n=0; n<i; n++)
	{
		if(cur->cat_name == NULL)
		{
			char str_temp[BUFSIZE] = {0,};
			strcpy(str_temp, _doc);
			strcat(str_temp, catArray[n]);

			cur->cat_dir = (char *)malloc(strlen(str_temp)+1);
			strcpy(cur->cat_dir, str_temp);

			cur->cat_name = (char *)malloc(strlen(catArray[n])+1);
			strcpy(cur->cat_name, catArray[n]);
			cur->action = DIRS;

			//printf("%s, %s\n", cur->cat_name, cur->cat_dir);
			
		}

		if(cur->bottom == NULL)
		{
			cur->bottom = (struct category *)malloc(\
					sizeof(struct category));
			cur->bottom->action = IDLE;
			cur->bottom->cat_name = NULL;
			cur->bottom->cat_dir = NULL;
			cur->bottom->bottom = NULL;
		}

		cur = cur->bottom;
	}

	/* load sub_directory file */
	cur = prev_cur;

	while(cur->bottom != NULL)
	{
		DIR *sub_dir = opendir(cur->cat_dir);
		struct dirent *sub_dirs = NULL;

		if(cur->next == NULL)
		{
			cur->next = (struct category *)malloc(\
				sizeof(struct category));
			cur->next->cat_name = (char *)malloc(\
				strlen(cur->cat_name)+1);
			strcpy(cur->next->cat_name, cur->cat_name);
			cur->next->cat_dir = NULL;
			cur->next->next = NULL;
			cur->next->bottom = NULL;
			cur->next->action = IDLE;
		}

		while((sub_dirs = readdir(sub_dir)) != NULL)
		{
			if((strcmp(sub_dirs->d_name,".") == 0) ||\
			   (strcmp(sub_dirs->d_name,"..") == 0))
			{
				continue;
			}

			if(cur->next->bottom == NULL)
			{				
				char str_temp[BUFSIZE] = {0,};
				strcpy(str_temp, cur->cat_dir);
				strcat(str_temp, "/");
				strcat(str_temp, sub_dirs->d_name);

				cur->next->bottom = (struct category *)malloc(\
					sizeof(struct category));
				
				cur->next->bottom->cat_name = (char *)malloc(\
					strlen(sub_dirs->d_name)+1);
				strcpy(cur->next->bottom->cat_name, \
					sub_dirs->d_name);
				
				cur->next->bottom->cat_dir = (char *)malloc(\
					strlen(str_temp)+1);
				strcpy(cur->next->bottom->cat_dir, str_temp);

				/* EVENT is 'Do something' */
				cur->next->bottom->action = EVENT;
				cur->next->bottom->bottom = NULL;
				cur->next->bottom->next = NULL;
				
				/* debug code */
				//printf("%d %s %s\n",cur->next->action,cur->next->cat_name,cur->next->cat_dir);
				//printf("%d %s %s\n",cur->next->bottom->action,cur->next->bottom->cat_name,cur->next->bottom->cat_dir);



			}
		}
		
		if(cur->bottom != NULL)
		{
			cur = cur->bottom;
		}

		if(closedir(sub_dir) != 0)
		{
			perror("closedir(sub_dir) : ");
			return -1;
		}
	}

	if(closedir(dir) != 0)
	{
		perror("closedir(dir) : ");
		return -1;
	}
	return cnt;

}

/*
int main(void)
{
	struct category *cat_head = (struct category *)malloc(\
			sizeof(struct category));

	cat_head->action = IDLE;
	cat_head->cat_name = NULL;
	cat_head->cat_dir = NULL;
	cat_head->bottom = NULL;
	cat_head->next = NULL;

	load_directory("../../doc/",&cat_head);

	return 0;
}
*/
