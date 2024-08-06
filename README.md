# Command
This program was designed on and for FreeBSD 14.1 and serves as the second homework assignmen for the class CS631 Advanced Programming in the Unix Environment, taught by the wonderful Jan Schaumann. While the course is desgned around NetBSD, I am implementing the assignments in FreeBSD 14.1 as it is the operating system I am running on my laptop and the slight differences in the various Unix-like operating systems make things fun for learning!


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

## Building the Program
To build the program, follow these steps:

1. Navigate to the mainn directory of the program.
2. Run the following commands:

```sh
make
```

To remove only the object files created during the compilation process run the following command

```sh
make clean-obj
```

To remove all files, including the binary, run the following
```sh
make clean
```

## Running the Program

```sh
./command_app
```
