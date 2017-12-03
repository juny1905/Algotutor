#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void)
{
	// pid_t pid[3] = {1,1,1};

	/*
	pid[0] = getpid();
	pid[1] = fork();

	if(pid[1] > 0)
	{
		pid[2] = fork();
	}
	*/
	/* user_interface process */
	//if(pid[1] == 0)
	//{
	
	pid_t pid;
	int status;
	if((pid = fork()) == 0)
	{
			execl("/home/parallels/algotutor/src/ui/ui_main","/ui_main",(char *)NULL);
	}
	else
	{
			wait(&status);
	}
	//}
	/* code_view_side process */
	//else if(pid[2] == 0)
	//{
	//	printf("%d\n",getpid());
	//}

	return 0;
}
