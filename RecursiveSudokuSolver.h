#ifndef RECURSIVE_SUDOKU_SOLVER_H
#define RECURSIVE_SUDOKU_SOLVER_H

#include "SudokuSolver.h"
class Sudoku;

class RecursiveSudokuSolver : public SudokuSolver
{
    private:
        bool solve(Sudoku sud, int row, int col);
        int movesMade;
    public:
        RecursiveSudokuSolver(Sudoku sudok);
        bool solve();
        void print();
        int getRecursiveGuessesMade();
};

#endif
