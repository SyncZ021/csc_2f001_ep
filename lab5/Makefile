.SUFFIXES:         # remove all the implicit rules (avoid conflicts with our own rules)
.SECONDARY:        # all files are intermediate (keep them, otherwise they are removed)
.PHONY: all clean  # these targets are not files (even if a file named "all" or "clean" exists, the rule is applied)

LDFLAGS=
LIBS=
CFLAGS=-Wall -Werror -g -std=c++20
BIN=ast

all: $(BIN)

ast: main.o node.o integer.o list.o keyword.o add.o symbol.o frame.o set.o
	g++ $(LDFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp node.h integer.h list.h keyword.h add.h symbol.h frame.h set.h
	g++ $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(BIN) *.o *~ 
