#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void ignore_handler(int sig){
	(void)printf("sig %d ignored\n", sig);
}

int command(const char *string, char *outbuf, int outlen, char *errbuf, int errlen)
{
	signal(SIGINT, ignore_handler);
	signal(SIGQUIT, ignore_handler);
	
	if(string == NULL){
		return -1;
	}

	return 0;
}
