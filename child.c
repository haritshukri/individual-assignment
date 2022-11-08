#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	int id = fork();
	printf("Hello World from id: %d\n", id);
	if (id == 0){
		printf("Hi from child process\n");
	} else{
		printf("Hi from parent process\n");
	}
	return 0;
}
