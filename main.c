#include <stdio.h>
#include <stdlib.h>

#include "./command.h"


int main(void)
{
	char out[BUFSIZ] = {0}, err[BUFSIZ] = {0};
	
	char *string = "ls -l";
//	char *string;
	if( command(string, out, BUFSIZ - 1, err, BUFSIZ - 1) == -1){
		perror("command");
		exit(EXIT_FAILURE);
	}

	out[BUFSIZ - 1] = '\0';
	err[BUFSIZ - 1] = '\0';

	printf("stdout:\n%s\n", out);
	printf("stderr:\n%s\n", err);

	return EXIT_SUCCESS;
}
