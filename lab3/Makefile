.SUFFIXES:         # remove all the implicit rules (avoid conflicts with our own rules)
.SECONDARY:        # all files are intermediate (keep them, otherwise they are removed)
.PHONY: all clean  # these targets are not files (even if a file named "all" or "clean" exists, the rule is applied)

LDFLAGS=
LIBS=
CFLAGS=-Wall -Werror -g
BIN=army-pokemon

all: $(BIN)

army-pokemon: main.o monster.o army-pokemon.o # corresponding to all .c files 
	gcc $(LDFLAGS) -o $@ $^ $(LIBS)

%.o: %.c monster.h macro.h army.h # .o files have to be recompiled when .h is modified
	gcc $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(BIN) *.o *~ 
