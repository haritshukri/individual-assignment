#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int sig_num){
	signal(SIGNIT, sigint_handler);
	printf("\n Cannot be stopped using Ctrl+C \n");
	fflush(stdout);
}

int main(){
	int pid;
	char pipewritemessage[30] = "Harits, are you coming to clas?";
	char pipewritemessage[30] = "I am on my way sir";
	char pipewritemessage[30] = "Alrigth then, be safe";
	char readmessage[30];
	int pipefds1[1], pipefs2[2], pipefds3[3];
	int returnstat1, returnstat2, returnstat3;

	returnstat1 = pipe(pipefds1);

	if(returnstat1 == -1){
		printf("Unable to reach pipe 1\n");
		return 1;
	}

	returnstat2 = pipe(pipefds2);

	if(returnstat2 == -1){
		printf("Unable to reach pipe 2\n");
		return 1;
	}

	returnstat3 = pipe(pipefds3);

	if(returnstat3 == -1){
		printf("Unable to reach pipe 3\n");
		return 1;
	}

	
return 0;
}
