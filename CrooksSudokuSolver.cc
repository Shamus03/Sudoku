#include <iostream>
#include "Sudoku.h"
#include "CrooksSudokuSolver.h"
#include "RecursiveSudokuSolver.h"
using namespace std;

CrooksSudokuSolver::CrooksSudokuSolver(Sudoku sudok)
{
    sudoku = sudok;
    exposedSinglesFound = 0;
    hiddenSinglesFound = 0;
    resortedToRecursion = false;
}

bool CrooksSudokuSolver::solve()
{
    bool madeProgress = true;
    
    while (madeProgress)
    {
        madeProgress = false;

        // Clever use of short-circuiting to repeat the more efficient
        // routune as much as possible.
        while (solveExposedSingles() || solveHiddenSingles())
        {
            madeProgress = true;
        }
    }

    // Solve the puzzle using the recursive method once progress has halted
    if (!sudoku.isSolved())
    {
        RecursiveSudokuSolver finishIt (sudoku);
        finishIt.solve();
        sudoku = finishIt.getSudoku();
        resortedToRecursion = true;
    }

    return sudoku.isSolved();
}

bool CrooksSudokuSolver::solveExposedSingles()
{
    bool madeProgress = false;
    int row, col, num;
    int singleNum;
    int numPossible;

    // Iterate through every cell
    for (row = 0; row < DIMENSION; row++)
    {
        for (col = 0; col < DIMENSION; col++)
        {
            // If a number is already present, move to the next cell
            if (sudoku.get(row, col) != 0)
                continue;

            singleNum = 0;
            numPossible = 0;
            for (num = 1; num <= DIMENSION; num++)
            {
                // Counting the number of possible moves in the cell
                if (sudoku.isValidMove(row, col, num))
                {
                    numPossible++;
                    singleNum = num;
                    if (numPossible > 1)
                    {
                        // A second possibility has been found, so quit
                        break;
                    }
                }
            }

            // If only one number is possible, assign that number
            if (numPossible == 1)
            {
                sudoku.set(row, col, singleNum);
                exposedSinglesFound++;
                madeProgress = true;
            }
        }
    }

    return madeProgress;
}

bool CrooksSudokuSolver::solveHiddenSingles()
{
    bool madeProgress = false;

    int i, j, num;
    int rowCount, colCount;
    int rowSingle, colSingle;

    // Iterate through rows and columns simultaneously
    for (i = 0; i < DIMENSION; i++)
    {
        rowCount = 0;
        colCount = 0;
        rowSingle = -1;
        colSingle = -1;

        // Iterate through every number
        for (num = 1; num <= DIMENSION; num++)
        {
            // Count locations where num is a possible move
            for (j = 0; j < DIMENSION; j++)
            {
                if (sudoku.isValidMove(i, j, num))
                {
                    rowSingle = j;
                    rowCount++;
                }

                if (sudoku.isValidMove(j, i, num))
                {
                    colSingle = j;
                    colCount++;
                }
            }

            // If num is only possible in 1 row/column, assign that number
            if (rowCount == 1)
            {
                sudoku.set(i, rowSingle, num);
                madeProgress = true;
            }

            if (colCount == 1)
            {
                sudoku.set(colSingle, i, num);
                madeProgress = true;
            }

            if (rowCount == 1 || colCount == 1)
            {
                hiddenSinglesFound++;
            }
        }
    }

    return madeProgress;
}

void CrooksSudokuSolver::print()
{
    /*
    cout << "Crook's Algorithm Sudoku Solver ";

    if (sudoku.isSolved())
    {
        cout << "(solved)" << endl;
        cout << "Exposed Singles Found: " << exposedSinglesFound << endl;
        cout << "Hidden  Singles Found: " << hiddenSinglesFound << endl;
        cout << "Resorted to Recursion: " <<
            (resortedToRecursion ? "True" : "False") << endl;
    }
    else
    {
        cout << "(unsolved)" << endl;
    }   
    sudoku.print();
    /*/
    if (sudoku.isSolved())
    {
        cout << exposedSinglesFound << ", " << hiddenSinglesFound << ", "
            << resortedToRecursion << endl;
    }
    //*/
}
