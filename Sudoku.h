#ifndef SUDOKU_H
#define SUDOKU_H

#define SUDOKU_SIZE 3

class Sudoku
{
    private:
        int grid[SUDOKU_SIZE * SUDOKU_SIZE * SUDOKU_SIZE * SUDOKU_SIZE];
        int dimension;
        int remaining;
    public:
        Sudoku();
        Sudoku(std::string);
        int get(int row, int col) { return grid[row * dimension + col]; };
        int get(int absolute) { return grid[absolute]; };
        bool set(int row, int col, int val);
        bool set(int absolute, int val);
        bool isValidMove(int, int, int);
        bool isSolved() { return remaining == 0; };
        int getRemaining() { return remaining; };
        int getDimension() { return dimension; };
        void print();
};

#endif
