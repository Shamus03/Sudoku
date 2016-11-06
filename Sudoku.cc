#include <iostream>
#include <stdlib.h>
#include "Sudoku.h"
using namespace std;

Sudoku::Sudoku()
{
    remaining = DIMENSION * DIMENSION;
    int i;
    int j;
    int k;

    for (i = 0; i < DIMENSION; i++)
    {
        for (j = 0; j < DIMENSION; j++)
        {
            grid[i * DIMENSION + j] = 0;
            for (k = 0; k < DIMENSION; k++)
            {
                markup[(i * DIMENSION + j) * DIMENSION + k] = true;
            }
        }
    }
}

Sudoku::Sudoku(string numbers)
{
    remaining = DIMENSION * DIMENSION;
    int i;
    int j;
    int k;

    for (i = 0; i < DIMENSION; i++)
    {
        for (j = 0; j < DIMENSION; j++)
        {
            grid[i * DIMENSION + j] = 0;
            for (k = 0; k < DIMENSION; k++)
            {
                markup[(i * DIMENSION + j) * DIMENSION + k] = true;
            }
        }
    }

    int num;
    int count = 0;
    for (i = 0; i < DIMENSION; i++)
    {
        for (j = 0; j < DIMENSION; j++)
        {
            // Convert char digits to integer digits
            num = numbers[count] - '0';
            if (num > 0)
            {
                set(i, j, num);
            }

            count++;
        }
    }
}

bool Sudoku::set(int row, int col, int val)
{
    // If a move is valid, make that move and return true.  Else return false.
    if (val > 0 && isValidMove(row, col, val))
    {
        // Decrement the number of empty cells if a 0 is being overwritten
        if (get(row, col) == 0)
            remaining--;

        grid[row * DIMENSION + col] = val;

        int i;
        int groupRow;
        int groupCol;
        int mi;
        int mj;
        int mk;

        // Remove val from the markup of all cells in the critical group
        for (i = 0; i < DIMENSION; i++)
        {
            // Set val at (row, col) to be an invalid move
            markup[(row * DIMENSION + col) * DIMENSION + i] = false;

            // Set val at (row, i) and (i, col) to be an invalid move
            markup[(row * DIMENSION + i) * DIMENSION + val - 1] = false;
            markup[(i * DIMENSION + col) * DIMENSION + val - 1] = false;

            // Calculate the row/column of the upper left of the cell's group
            groupRow = row - row % SUDOKU_SIZE;
            groupCol = col - col % SUDOKU_SIZE;

            // Use some variables to clean up the following array indexing
            mi = groupRow + i / SUDOKU_SIZE;
            mj = groupCol + i % SUDOKU_SIZE;
            mk = val - 1;
            markup[(mi * DIMENSION + mj) * DIMENSION + mk] = false;
        }

        return true;
    }

    return false;
}

void Sudoku::print()
{
    cout << "Sudoku with " << remaining << " remaining:" << endl;
    int i, j, k;
    // Iterate through every cell
    for (i = 0; i < DIMENSION; i++)
    {
        for (j = 0; j < DIMENSION; j++)
        {
            cout << get(i, j) << " ";
            // If the cell is on a group boundary, print a vertical line
            if (j % SUDOKU_SIZE == SUDOKU_SIZE - 1 && j < DIMENSION - 1)
            {
                cout << "| ";
            }
        }
        cout << endl;
        // If the row is on a group boundary, print a horizontal line
        if (i % SUDOKU_SIZE == SUDOKU_SIZE - 1 && i < DIMENSION - 1)
        {
            for (k = 0; k < (DIMENSION + SUDOKU_SIZE - 1) * 2 - 1; k++)
            {
                cout << "-";
            }
            cout << endl;
        }
    }
    cout << endl;
}
