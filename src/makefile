CC=g++
CFLAGS= -std=c++17 -O2 -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion

main: main.o binary_tree.o stack.o linked_list.o
	$(CC) main.o binary_tree.o stack.o linked_list.o -o main

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

binary_tree.o: binary_tree.cpp binary_tree.hpp
	$(CC) $(CFLAGS) -c binary_tree.cpp 

stack.o: stack.cpp stack.hpp
	$(CC) $(CFLAGS) -c stack.cpp 

linked_list.o: linked_list.cpp linked_list.hpp
	$(CC) $(CFLAGS) -c linked_list.cpp 

clean:
	rm *.o main
