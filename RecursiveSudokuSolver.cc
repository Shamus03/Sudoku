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
    return solve(sudoku, 0);
}

bool RecursiveSudokuSolver::solve(Sudoku sud, int start)
{
    if (sud.isSolved())
    {
        sudoku = sud;
        return true;
    }

    if (start > sud.getDimension() * sud.getDimension())
        return false;
    
    if (sud.get(start) > 0)
        return solve(sud, start + 1);

    for (int i = 1; i <= sud.getDimension(); i++)
    {
        if (sud.set(start, i))
        {
            if(solve(sud, start + 1))
            {
                return true;
            }
        }
    }

    return false;
}

void RecursiveSudokuSolver::print()
{
    cout << "Recursive Sudoku Solver" << endl;
    sudoku.print();
}
