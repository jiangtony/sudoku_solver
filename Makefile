CC=g++
C++FLAGS=-Wall -pedantic
ALL_OBJ = Sudoku.o
PROG_NAME=sudoku

%.o : %.cpp
	g++ -std=c++11 -c $< -o $@ $(C++FLAGS)

$(PROG_NAME): $(ALL_OBJ)
	$(CC) $(C++FLAG) -o $@ $(ALL_OBJ)

all:
	make $(PROG_NAME)

clean:
	(rm -f *.o sudoku;)

