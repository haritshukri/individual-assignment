#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	int id = fork();
	if(id == 0){
		printf("Hi saya anak id: %d\n", id);
	} else{
		printf("Hi saya parent id: &d\n", id);
	}
	return 0;
}
