#ifndef SUDOKU_H
#define SUDOKU_H

static const int SUDOKU_SIZE = 3;
static const int DIMENSION = SUDOKU_SIZE * SUDOKU_SIZE;

class Sudoku
{
    private:
        int grid[DIMENSION * DIMENSION];
        int remaining;
    public:
        Sudoku();
        Sudoku(std::string);
        int get(int row, int col) { return grid[row * DIMENSION + col]; };
        int get(int absolute) { return grid[absolute]; };
        bool set(int row, int col, int val);
        bool set(int absolute, int val);
        bool isValidMove(int, int, int);
        bool isSolved() { return remaining == 0; };
        int getRemaining() { return remaining; };
        void print();
};

#endif
