CXX = g++
CXXFLAGS = -Wall -ansi -pedantic
LDFLAGS=
EXEC = main
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^

.o: $(SRC)
	$(CXX) $(CXXFLAGS) -c $^

clean:
	rm *.o main

SRCsup = $(wildcard *.h)
NAME = picross_src.tar.gz

archive:
	tar -czf $(NAME) $(SRCsup) $(SRC) makefile
