#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char* argv[]){
	int arr[] = {1, 2, 3, 4, 1, 2 };
	int arrsize = sizeof(arr) / sizeof(int);
	int start, end;
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

	if (id == 0){
		start = 0;
		end = start + arrsize / 2;
	} else{
		start = arrsize / 2;
		end = arrsize;
	}

	int sum = 0;
	int i;
	for ( i = start; i < end; i++){
		sum += arr[i];
	}

	printf("Calculated partial sum: %d\n", sum);

	return 0;
}
