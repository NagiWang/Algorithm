all: BUILD \
     build/sort_main.out


BUILD:
	mkdir build


# build/algoritnm.o: Algoritnm.hpp
# 	clang++ "$<" -std=c++17 -o "$@" -Iinclude


build/sort_main.out: test/Sort_Test/main.cpp
	clang++ "$<" -std=c++17 -o "$@"



clean:
	rm -rf build
	find . -name "*.o"    | xargs rm -f
	find . -name "*.out"  | xargs rm -f
	find . -name "*.obj"  | xargs rm -f
	find . -name "*.exe"  | xargs rm -f