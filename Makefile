all:BUILD \
	Algorithm \
    build/sort_main.out \
	build/heap_main.out \
	build/queue_main.out \
	build/math_main.out

CC=clang++-8
OO=-O3
STD=-std=c++17

BUILD:
	mkdir build


Algorithm: Algorithm.hpp
	$(CC) "$<" $(STD) $(OO)


build/sort_main.out: test/Sort_test/main.cpp
	$(CC) "$<" $(STD) $(OO) -o "$@"

build/heap_main.out: test/Heap_test/main.cpp
	$(CC) "$<" $(STD) $(OO) -o "$@"

build/queue_main.out: test/Queue_test/main.cpp
	$(CC) "$<" $(STD) $(OO) -o "$@"

build/math_main.out: test/Math_test/main.cpp
	$(CC) "$<" $(STD) $(OO) -o "$@"

clean:
	rm -rf build
	find . -name "*.o"    | xargs rm -f
	find . -name "*.out"  | xargs rm -f
	find . -name "*.obj"  | xargs rm -f
	find . -name "*.exe"  | xargs rm -f
	find . -name "*.gch"  | xargs rm -f
