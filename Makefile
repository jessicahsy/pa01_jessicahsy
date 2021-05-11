CXX_FLAG = --std=c++11 -g
all: testlist #main

testlist: testcards.o cards.o
	g++ $(CXX_FLAG) -o testcards testcards.o cards.o

# main: main.o cards.o
# 	g++ $(CXX_FLAG) -o main main.o cards.o

testlist.o: testcards.cpp
	g++ -c $(CXX_FLAG) testcards.cpp

# main.o: main.cpp
# 	g++ -c $(CXX_FLAG) main.cpp

cards.o: cards.cpp
	g++ -c $(CXX_FLAG) cards.cpp

clean:
	rm -f  testlist *.o


# #lab03
# # CXX_FLAG = --std=c++11 -g

# # all: testlist testrest

# # testlist: testlist.o intlist.o
# # 	g++ $(CXX_FLAG) -o testlist testlist.o intlist.o

# # testrest: testrest.o intlist.o
# # 	g++ $(CXX_FLAG) -o testrest testrest.o intlist.o

# # testlist.o: testlist.cpp
# # 	g++ -c $(CXX_FLAG) testlist.cpp

# # testrest.o: testrest.cpp
# # 	g++ -c $(CXX_FLAG) testrest.cpp

# # intlist.o: intlist.cpp
# # 	g++ -c $(CXX_FLAG) intlist.cpp

# # clean:
# # 	rm -f testrest testlist *.o