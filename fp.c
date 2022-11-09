#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

#define MAX_LIMIT 80

void sigint_handler(int sig_num){
	signal(SIGINT, sigint_handler);
	printf("\n Cannot stop the program using Ctrl+C \n");
	fflush(stdout);
}

int main(void){

	char name[MAX_LIMIT];

	for(int i=1; i<5; i++){
		pid_t pid = fork();

		if(pid == 0){
			fgets(name, MAX_LIMIT, stdin);
			printf("Your name is %s\n", name);
			exit(0);
		}
		else{
			printf("What is your name?\n");
			wait(NULL);
		}
	}
	return EXIT_SUCCESS;
}
