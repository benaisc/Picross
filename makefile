CXX=g++
CXXFLAGS=-Wall -ansi -pedantic
LDFLAGS=-Wall
EXEC=main
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) $^ -o $@

%.o: $(SRC)
	$(CXX) $(CXXFLAGS) -c $^

clean:
	rm *.o
