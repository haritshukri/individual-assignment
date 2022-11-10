#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

int main(void)
{
	int pipefds[2];
	char str[50];
	int i;

	if(pipe(pipefds) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	pid_t pid = fork();

	if(pid != 0)
	{
		void sigintHandler(int sig_num)

        signal(SIGINT, sigintHandler);
    	printf("\n Cannot be terminated using Ctrl+C \n");
    	fflush(stdout);

	}

	printf("\nParent: Enter a message:\n");
	scanf("%s",&str);
	int x;
	for( x = 0; x < 3; x++){
		sleep(2);
		printf("Receiving..\n");
	}
	close(pipefds[0]);
	write(pipefds[1],&str,sizeof(str));
	exit(EXIT_SUCCESS);
}

if (pid == 0)
{
	wait(NULL);
	close(pipefds[1]);
	read(pipefds[0],&str,sizeof(str));
	printf("\nChild: Display message: %s\n", str);
	return EXIT_SUCCESS;
}
