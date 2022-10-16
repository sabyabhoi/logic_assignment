CC=g++
CFLAGS= -std=c++17 -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion -g

main: main.o binary_tree.o stack.o linked_list.o hash_table.o
	$(CC) main.o binary_tree.o stack.o linked_list.o hash_table.o -o main

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

binary_tree.o: binary_tree.cpp binary_tree.hpp
	$(CC) $(CFLAGS) -c binary_tree.cpp 

stack.o: stack.cpp stack.hpp
	$(CC) $(CFLAGS) -c stack.cpp 

linked_list.o: linked_list.cpp linked_list.hpp
	$(CC) $(CFLAGS) -c linked_list.cpp 

hash_table.o: hash_table.cpp hash_table.hpp
	$(CC) $(CFLAGS) -c hash_table.cpp 

clean:
	rm *.o main
