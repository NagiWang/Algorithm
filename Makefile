test/Sort_Test/sort_main.out: test/Sort_Test/main.cpp
	g++ "$<" -std=c++17 -o "$@"

clean:
	rm -rf */*.out  */.o