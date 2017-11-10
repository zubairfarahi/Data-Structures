build:
	gcc -std=c9x test.c -lm -Wall -g -D_GNU_SOURCE -o test

test:
	./test

clean:
	rm -f test

valgrind:
	valgrind ./test

.PHONY: test
