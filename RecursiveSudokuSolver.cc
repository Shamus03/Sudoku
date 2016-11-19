#include <iostream>
#include "Sudoku.h"
#include "RecursiveSudokuSolver.h"
using namespace std;

RecursiveSudokuSolver::RecursiveSudokuSolver(Sudoku sudok)
{
    sudoku = sudok;
    movesMade = 0;
}

bool RecursiveSudokuSolver::solve()
{
    // Begin solving at the top left
    return solve(sudoku, 0, 0);
}

bool RecursiveSudokuSolver::solve(Sudoku sud, int row, int col)
{
    // First base case: If the puzzle is solved, return true
    if (sud.isSolved())
    {
        sudoku = sud;
        return true;
    }

    // Second base case: Do not run off the edge of the grid
    if (row >= DIMENSION || col >= DIMENSION)
        return false;

    // Find the next row and column without running off the edge of a row
    int nextRow;
    int nextCol;
    if (col == DIMENSION - 1)
    {
        nextRow = row + 1;
        nextCol = 0;
    }
    else
    {
        nextRow = row;
        nextCol = col + 1;
    }
    
    // If a number is already in this cell, move to the next cell
    if (sud.get(row, col) > 0)
        return solve(sud, nextRow, nextCol);

    // Iterate through every number
    for (int i = 1; i <= DIMENSION; i++)
    {
        // Make a copy of the puzzle to preserve markup if a guess is incorrect
        Sudoku sudCopy = sud;
        // Make any possible moves and attempt to continue solving
        if (sudCopy.set(row, col, i))
        {
            movesMade++;
            if(solve(sudCopy, nextRow, nextCol))
            {
                // If a solution is found, cascade return to solve(0, 0)
                return true;
            }
        }
    }

    // At this point all attempts have failed.
    // This will return to the previous call of this function,
    // and the old copy of the Sudoku will continue to be solved.

    return false;
}

int RecursiveSudokuSolver::getRecursiveGuessesMade()
{
    return movesMade;
}

void RecursiveSudokuSolver::print()
{
    cout << "Recursive Sudoku Solver ";
    if (sudoku.isSolved())
    {
        cout << "(solved)" << endl;
        cout << "Recursive Guesses Made: " << movesMade << endl;
    }
    else
    {
        cout << "(unsolved)" << endl;
    }
    sudoku.print();
}
