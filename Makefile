CC=clang++-9
OO=-O2
STD=-std=c++17 -stdlib=libc++
CFLAGS=-Wall

# BUILD:
# 	mkdir build

# Algorithm: Algorithm.hpp
# 	$(CC) "$<" $(STD) $(OO)

all:build/sort_main.out \
	build/heap_main.out \
	build/queue_main.out \
	build/math_main.out  \
	build/meta_main.out

build/sort_main.out: test/Sort_test/main.cpp
	$(CC) "$<" $(STD) $(CFLAGS) $(OO) -o "$@"

build/heap_main.out: test/Heap_test/main.cpp
	$(CC) "$<" $(STD) $(CFLAGS) $(OO) -o "$@"

build/queue_main.out: test/Queue_test/main.cpp
	$(CC) "$<" $(STD) $(CFLAGS) $(OO) -o "$@"

build/math_main.out: test/Math_test/main.cpp
	$(CC) "$<" $(STD) $(CFLAGS) $(OO) -o "$@"

build/meta_main.out: test/Meta_test/main.cpp
	$(CC) "$<" $(STD) $(CFLAGS) $(OO) -o "$@"

mpltest: src/Meta/AuxiliaryTypes/mpltest.cpp
	$(CC) "$<" $(STD) $(CFLAGS) $(OO) -o "$@"


clean:
	rm -r build/*
	find . -name "*.o"    | xargs rm -f
	find . -name "*.out"  | xargs rm -f
	find . -name "*.obj"  | xargs rm -f
	find . -name "*.exe"  | xargs rm -f
	find . -name "*.gch"  | xargs rm -f
