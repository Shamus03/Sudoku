#include <iostream>
#include "Sudoku.h"
#include "RecursiveSudokuSolver.h"
using namespace std;

RecursiveSudokuSolver::RecursiveSudokuSolver(Sudoku sudok)
{
    sudoku = sudok;
}

bool RecursiveSudokuSolver::solve()
{
    return solve(sudoku, 0, 0);
}

bool RecursiveSudokuSolver::solve(Sudoku sud, int row, int col)
{
    if (sud.isSolved())
    {
        sudoku = sud;
        return true;
    }

    if (row >= DIMENSION || col >= DIMENSION)
        return false;

    int nextRow = row;
    int nextCol = (col + 1) % DIMENSION;

    if (nextCol < col)
        nextRow++;
    
    if (sud.get(row, col) > 0)
        return solve(sud, nextRow, nextCol);

    for (int i = 1; i <= DIMENSION; i++)
    {
        Sudoku sudCopy = sud;
        if (sudCopy.set(row, col, i))
        {
            if(solve(sudCopy, nextRow, nextCol))
            {
                return true;
            }
        }
    }

    return false;
}

void RecursiveSudokuSolver::print()
{
    cout << "Recursive Sudoku Solver "
        << (sudoku.isSolved() ? "(solved)" : "(unsolved)") << endl;
    sudoku.print();
}
