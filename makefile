CXX = g++
CXXFLAGS = -Wall -ansi -pedantic `pkg-config gtkmm-3.0 --cflags --libs`
LDFLAGS=
EXEC = main
SRC = $(wildcard *.cpp)

all: $(EXEC)

$(EXEC): $(SRC)
	$(CXX) $^ $(CXXFLAGS) -o $@

clean:
	rm *.o main

SRCsup = $(wildcard *.h)
NAME = picross_src.tar.gz

archive:
	tar -czf $(NAME) $(SRCsup) $(SRC) Fenetre.hpp makefile
