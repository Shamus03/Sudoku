#include <iostream>
#include "Sudoku.h"
#include "CrooksSudokuSolver.h"
#include "RecursiveSudokuSolver.h"
using namespace std;

CrooksSudokuSolver::CrooksSudokuSolver(Sudoku sudok)
{
    sudoku = sudok;
}

bool CrooksSudokuSolver::solve()
{
    bool madeProgress = true;
    
    while (madeProgress)
    {
        madeProgress = false;

        while (solveExposedSingles() || solveHiddenSingles())
        {
            madeProgress = true;
        }
    }

    if (!sudoku.isSolved())
    {
        RecursiveSudokuSolver finishIt (sudoku);
        finishIt.solve();
        sudoku = finishIt.getSudoku();
    }

    return sudoku.isSolved();
}

bool CrooksSudokuSolver::solveExposedSingles()
{
    bool madeProgress = false;
    int row, col, num;
    int singleNum;
    int numPossible;

    for (row = 0; row < DIMENSION; row++)
    {
        for (col = 0; col < DIMENSION; col++)
        {
            if (sudoku.get(row, col) != 0)
                continue;

            singleNum = 0;
            numPossible = 0;
            for (num = 1; num <= DIMENSION; num++)
            {
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

            if (numPossible == 1)
            {
                sudoku.set(row, col, singleNum);
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

    for (i = 0; i < DIMENSION; i++)
    {
        rowCount = 0;
        colCount = 0;
        rowSingle = -1;
        colSingle = -1;

        for (num = 1; num <= DIMENSION; num++)
        {
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
        }
    }

    return madeProgress;
}

void CrooksSudokuSolver::print()
{
    cout << "Crook's Algorithm Sudoku Solver "
        << (sudoku.isSolved() ? "(solved)" : "(unsolved)") << endl;
    sudoku.print();
}
