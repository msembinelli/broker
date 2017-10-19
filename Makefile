OBJS := broker.o test/broker_tests.o test/unity/src/unity.o
INC=-Itest/unity/src/ -Itest/../
CFLAGS=-Wall -g -O0 -fprofile-arcs -ftest-coverage
LFLAGS=-lgcov -fprofile-arcs

# link
broker_tests: $(OBJS)
	gcc $(OBJS) $(LFLAGS) -o broker_tests
	./broker_tests
	gcov broker.c

# pull in dependency info for *existing* .o files
-include $(OBJS:.o=.d)

# compile and generate dependency info
%.o: %.c
	gcc -c $(CFLAGS) $(INC) $*.c -o $*.o
	gcc -MM $(CFLAGS) $(INC) $*.c > $*.d


# remove compilation products
clean:
	rm -f build *.o *.d
