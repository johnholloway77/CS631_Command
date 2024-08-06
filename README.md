# Command
This program was designed on and for FreeBSD 14.1 and serves as the second homework assignmen for the class CS631 Advanced Programming in the Unix Environment, taught by the wonderful Jan Schaumann.

## Assignment Goals
The objective of this assignment is to apply the lessons of Unix Interprocess Communication from the video lectures and textbook (Steven's Advanced Programming in the Unix Environment 3rd Edition), and to write a tool which requirescommunication between two related processes using the pipe(2) system call.

Full details of the assignment can be found [here](https://stevens.netmeister.org/631/f23-hw2.html).


## Problem Assignment
Write a function command(3) as described in the [manual page](https://stevens.netmeister.org/631/command.pdf). The code should run successfully when used in the following main() function:

```
int
main() {
	char out[BUFSIZ] = { 0 }, err[BUFSIZ] = { 0 };
	if (command("ls -l", out, BUFSIZ-1, err, BUFSIZ-1) == -1) {
		perror("command");
		exit(EXIT_FAILURE);
	}
	out[BUFSIZ-1] = '\0';
	err[BUFSIZ-1] = '\0';
	printf("stdout:\n%s\n", out);
	printf("stderr:\n%s\n", err);
	return EXIT_SUCCESS;
}
```

