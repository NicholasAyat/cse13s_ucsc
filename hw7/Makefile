CC = clang
CFLAGS = -Wall -Wextra -Werror -Wpedantic -gdwarf-4

all: businessdb test_hashtable

businessdb: main.o hashtable.o fileio.o
	$(CC) -o businessdb main.o hashtable.o fileio.o

test_hashtable: test_hashtable.o hashtable.o
	$(CC) -o test_hashtable test_hashtable.o hashtable.o

main.o: main.c hashtable.h fileio.h
	$(CC) $(CFLAGS) -c main.c

hashtable.o: hashtable.c hashtable.h
	$(CC) $(CFLAGS) -c hashtable.c

fileio.o: fileio.c fileio.h hashtable.h
	$(CC) $(CFLAGS) -c fileio.c

test_hashtable.o: test_hashtable.c hashtable.h
	$(CC) $(CFLAGS) -c test_hashtable.c

clean:
	rm -f businessdb test_hashtable *.o

format:
	clang-format -i *.c *.h 