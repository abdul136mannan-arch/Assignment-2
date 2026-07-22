#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main()
{
    pid_t pid[3];

    for(int i=0;i<3;i++)
    {
        pid[i]=fork();

        if(pid[i]==0)
        {
            printf("Child %d started\n",getpid());

            if(i==2)
                sleep(15);
            else
                sleep(3);

            printf("Child %d finished\n",getpid());
            exit(0);
        }
    }

    sleep(5);

    if(kill(pid[2],0)==0)
    {
        printf("Terminating unresponsive child %d\n",pid[2]);
        kill(pid[2],SIGKILL);
    }

    while(wait(NULL)>0);

    printf("All child processes handled successfully.\n");

    return 0;
}
