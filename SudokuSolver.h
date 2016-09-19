#ifndef SUDOKU_SOLVER_H
#define SUDOKU_SOLVER_H

#include "Sudoku.h"

class SudokuSolver
{
    protected:
        Sudoku sudoku;
        bool solved;
    public:
        virtual bool solve() = 0;
        virtual void print() = 0;
};

#endif
