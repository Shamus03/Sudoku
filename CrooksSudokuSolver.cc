#include <iostream>
#include "Sudoku.h"
#include "CrooksSudokuSolver.h"
using namespace std;

CrooksSudokuSolver::CrooksSudokuSolver(Sudoku sudok)
{
    sudoku = sudok;
}

bool CrooksSudokuSolver::solve()
{
    return solveExposedSingles();
}

bool CrooksSudokuSolver::solveExposedSingles()
{
    bool madeProgress = true;
    int row, col, num;
    int singleNum;
    int numPossible;

    while (!sudoku.isSolved() && madeProgress)
    {
        madeProgress = false;

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
    }

    return sudoku.isSolved();
}

void CrooksSudokuSolver::print()
{
    cout << "Crook's Algorithm Sudoku Solver "
        << (sudoku.isSolved() ? "(solved)" : "(unsolved)") << endl;
    sudoku.print();
}
