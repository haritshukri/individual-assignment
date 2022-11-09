#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char* argv[]){
	char ch, chFromParent;
	int fd[2];
	if(pipe(fd) == -1){
		printf("pipe error\n");
		return 1;
	}

	int id = fork();
	if(id == -1) {
		printf("fork error\n");
		return 2;
	}

	if (id != 0){
		close(fd[1]);
		printf("Parent: Enter a character %c\n", ch);
		write(fd[0], &ch, sizeof(ch));
		close(fd[1]);
	} else{
		close(fd[0]);
		printf("\nChild: The ASCII value of the ch variable is: %d", ch);
		read(fd[1], &chFromParent, sizeof(chFromParent));
		close(fd[1]);
	}

	return 0;
}
