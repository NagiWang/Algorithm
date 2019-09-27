test/Sort_Test/sort_main.out: test/Sort_Test/main.cpp
	clang++ "$<" -std=c++17 -o "$@"

clean:
	find . -name "*.o"    | xargs rm -f
	find . -name "*.out"  | xargs rm -f
	find . -name "*.obj"  | xargs rm -f
	find . -name "*.exe"  | xargs rm -f