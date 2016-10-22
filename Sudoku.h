#ifndef SUDOKU_H
#define SUDOKU_H
#include <string>

static const int SUDOKU_SIZE = 3;
static const int DIMENSION = SUDOKU_SIZE * SUDOKU_SIZE;

class Sudoku
{
    private:
        int grid[DIMENSION * DIMENSION];
        bool markup[DIMENSION * DIMENSION * DIMENSION];
        int remaining;
    public:
        Sudoku();
        Sudoku(std::string);
        int get(int row, int col) { return grid[row * DIMENSION + col]; };
        bool set(int row, int col, int val);
        bool isValidMove(int row, int col, int num)
            { return markup[(row * DIMENSION + col) * DIMENSION + num - 1]; };
        bool isSolved() { return remaining == 0; };
        int getRemaining() { return remaining; };
        void print();
};

#endif
