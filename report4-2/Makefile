CC=gcc
CFLAGS=-std=c99 -lm -DMEXP=216091
TARGET=report

terget: report4-2.o SFMT.o
	$(CC) $(CFLAGS) $^ -o $(TARGET)

.o.c:
	$(CC) $(CFLAGS) -c $<

clean: 
	rm -f *.o  $(TARGET)

