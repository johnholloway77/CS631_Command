#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

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

	int n;
	int out_fd[2];
	int err_fd[2];

	pid_t pid;
	FILE *fp;
	fp = popen(string, "r+");

	if(pipe(out_fd) == -1 || pipe(err_fd) == -1){
		return -1;
	}


	if((pid = fork()) == -1){
		close(out_fd[0]);
		close(out_fd[1]);
		close(err_fd[0]);
		close(err_fd[1]);
		return -1;
	}


	
	if(pid == 0){ //child process
		
		//close write ends
		close(out_fd[0]);
		close(err_fd[0]);

		//duplicate the file descriptors of the read end of the pipes
		//onto the respective stdin & stdout file numbers
		dup2(out_fd[1], STDOUT_FILENO);
		dup2(err_fd[1], STDERR_FILENO);

		//tokenize string into argument for execvp
		char *args[2];
		int i = 0;
		char *token = strtok(strdup(string), " "); //strdup for a const string
		while (token != NULL && i < 2){
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		//execute command

		if(execvp(args[0], args) == -1){
			perror("execvp");
			return -1;
		}

	}else if (pid > 0) { //parent process
		close(out_fd[1]);
		close(err_fd[1]);

		ssize_t n;

		if((n = read(out_fd[0], outbuf, outlen)) >= 0){
			outbuf[n] = '\0';
		} else{
			outbuf[0] = '\0';
		}
		close(out_fd[0]);

		if((n = read(err_fd[0], errbuf, errlen)) >= 0){
			errbuf[n] = '\0';
		} else{
			errbuf[0] = '\0';
		}
		close(err_fd[0]);

		int status;
		if(waitpid(pid, &status, 0) == -1){
			return status;
		}

		return 0;

	}




	return 0;
}
