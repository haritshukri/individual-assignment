// C program to demonstrate
// use of sleep function
// till 10 milliseconds
#include <stdio.h>
#include <unistd.h>
 
int main()
{
 
    printf("Program will sleep for 10 millisecond .\n");
 
    sleep(0.01);
 
    printf("This line will be executed after 10 millisecond.");
 
    return 0;
}
