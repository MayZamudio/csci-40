a.out: main.cc map.h
    g++ -Wall -Wextra -Wpedantic -pedantic-errors -Wno-unused-variable -Wno-unused-parameter -std=c++17 -DMADE_USING_MAKEFILE -fmax-errors=1 -D_GLIBCXX_DEBUG -fsanitize=undefined -fsanitize=address main.cc -lncurses

unicode: unicode.o
    g++ unicode.o $(ncursesw5-config --libs) -o unicode

unicode.o: unicode_example.cc
    g++ unicode_example.cc $(ncursesw5-config --cflags) -c

clean:
    rm a.out core *.o