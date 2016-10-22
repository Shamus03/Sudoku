#ifndef CROOKS_SUDOKU_SOLVER_H
#define CROOKS_SUDOKU_SOLVER_H

#include "SudokuSolver.h"
class Sudoku;

class CrooksSudokuSolver : public SudokuSolver
{
    private:
        bool solveExposedSingles();
        bool solveHiddenSingles();
    public:
        CrooksSudokuSolver(Sudoku sudok);
        bool solve();
        void print();
};

#endif
