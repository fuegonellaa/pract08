nfa: src/main_nfa.cc nfa.o set.o state.o transition.o
	mkdir -p bin
	g++ -o bin/nfa_simulation obj/* src/main_nfa.cc -I.

all: NFA doc

nfa.o: src/nfa.cc
	mkdir -p obj
	g++ -c src/nfa.cc -o obj/nfa.o

set.o: src/set.cc
	g++ -c src/set.cc -o obj/set.o

state.o: src/state.cc
	g++ -c src/state.cc -o obj/state.o

transition.o: src/transition.cc
	g++ -c src/transition.cc -o obj/transition.o

doc:
	doxygen

.PHONY: clean

clean:
	rm -rf html
	rm -f bin/*
	rm -f obj/*