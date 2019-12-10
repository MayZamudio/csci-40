CC = g++
#CCFLAGS = -Wall -Wextra -std=c++17 -g -O3
CCFLAGS = -Wno-unused-variable -Wno-unused-parameter -std=c++17 -g -fmax-errors=1 -D_GLIBCXX_DEBUG -fsanitize=undefined -fsanitize=address
SRC = $(wildcard *.cc)
OBJ = $(SRC:%.cc=%.o)

a.out: $(OBJ)
    @echo Building a.out
    @$(CC) $(CCFLAGS) $^

%.o: %.cc
    @echo Compiling $<
    @$(CC) $(CCFLAGS) -c $<

clean:
    rm -f a.out *.o