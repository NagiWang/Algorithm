all:BUILD \
	Algorithm \
    build/sort_main.out


BUILD:
	mkdir build


Algorithm: Algorithm.hpp
	clang++ -c Algorithm.hpp -std=c++17


build/sort_main.out: test/Sort_Test/main.cpp
	clang++ "$<" -std=c++17 -o "$@"



clean:
	rm -rf build
	find . -name "*.o"    | xargs rm -f
	find . -name "*.out"  | xargs rm -f
	find . -name "*.obj"  | xargs rm -f
	find . -name "*.exe"  | xargs rm -f
	find . -name "*.gch"  | xargs rm -f