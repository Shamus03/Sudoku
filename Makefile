.PHONY: clean run remake

CC=c++
CFLAGS=-c -Wall
LDFLAGS=
EXT=cc
SOURCES=Sudoku.cc RecursiveSudokuSolver.cc SolveSudoku.cc CrooksSudokuSolver.cc
OBJECTS=$(SOURCES:.$(EXT)=.o)
EXECUTABLE=SolveSudoku
DEFAULTPUZZLES=puzzles/0.txt

all: $(SOURCES) $(EXECUTABLE)

clean:
	rm -f *.o $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE) $(DEFAULTPUZZLES)

remake: clean all
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.$(EXT).o:
	$(CC) $(CFLAGS) $< -o $@
