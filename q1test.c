#include "types.h"
#include "user.h"

#define NCHILD 10


int main()
{
	int pid;
	ticketlockinit();

	pid =fork();
	for (int i = 1; i < NCHILD; i++)
	{
		if (pid<0)
		{
			printf(1,"fork failed\n");
			exit();
		}
		else if(pid>0)
			pid=fork();
	}
	if (pid<0)
	{
		printf(1,"fork failed\n");
		exit();
	}
	else if (pid==0)
	{
		printf(1,"child adding to shared counter\n");
		ticketlocktest();

	}
	else
	{
		for (int i = 0; i < NCHILD; i++)
		{
			wait();
			printf(1,"userprogram finished\n");
			printf(2,"ticket lock value: %d \n",ticketlocktest()-1);


					}
	}
	exit();
	return 0;
	
}
