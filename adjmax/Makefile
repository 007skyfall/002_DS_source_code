CC=gcc
CFLAG=-Wall -g -O0

graph: *.c 
	$(CC) $(CFLAG) -o $@ $^

.PHONY:clean
	
clean:
	rm -rf *.o graph
