#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

# define BUFFER_SIZE 5

int main(void)
{
	char	potential_line[BUFFER_SIZE];

    potential_line[0] = '1';
    potential_line[1] = '2';
    potential_line[2] = '3';
    potential_line[3] = '4';
    potential_line[4] = '5';

    printf("'%s'", potential_line);
}