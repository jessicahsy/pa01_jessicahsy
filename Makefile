
# Makefile
CXX_FLAG = --std=c++11 -g

all: testcards game

testcards: testcards.o cards.o
	g++ $(CXX_FLAG) -o testcards testcards.o cards.o


testcards.o: testcards.cpp
	g++ -c $(CXX_FLAG) testcards.cpp

#game: game.o
#
#game.o: game.cpp

cards.o: cards.cpp
	g++ -c $(CXX_FLAG) cards.cpp

clean:
	rm -f testcards *.o


#lab03
# CXX_FLAG = --std=c++11 -g

# all: testlist testrest

# testlist: testlist.o intlist.o
# 	g++ $(CXX_FLAG) -o testlist testlist.o intlist.o

# testrest: testrest.o intlist.o
# 	g++ $(CXX_FLAG) -o testrest testrest.o intlist.o

# testlist.o: testlist.cpp
# 	g++ -c $(CXX_FLAG) testlist.cpp

# testrest.o: testrest.cpp
# 	g++ -c $(CXX_FLAG) testrest.cpp

# intlist.o: intlist.cpp
# 	g++ -c $(CXX_FLAG) intlist.cpp

# clean:
# 	rm -f testrest testlist *.o