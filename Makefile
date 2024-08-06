#Compiler
CC = clang

#Compiler Flags
CFLAGS = -Wall -Wextra

#Source files
SOURCES = main.c\
	  command.c

#Object files
OBJECTS = $(SOURCES:.c=.o)

#Libraries to link
#n/a

#output binary
BINARY=command_app

#rule to link to binary
$(BINARY): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) #$(LIBS) not needed

#Rule to compile the source files into the object files
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

#clean all files created
.PHONY: clean
clean:
	rm -rf $(BINARY) $(OBJECTS)

#clean only the object files
.PHONY: clean-obj
clean-obj:
	rm -rf $(OBJECTS)

