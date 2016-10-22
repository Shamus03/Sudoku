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
    if (val > 0 && isValidMove(row, col, val))
    {
        if (get(row, col) == 0)
            remaining--;

        grid[row * DIMENSION + col] = val;

        int i;
        int groupRow;
        int groupCol;
        int mi;
        int mj;
        int mk;

        for (i = 0; i < DIMENSION; i++)
        {
            markup[(row * DIMENSION + col) * DIMENSION + i] = false;

            markup[(row * DIMENSION + i) * DIMENSION + val - 1] = false;
            markup[(i * DIMENSION + col) * DIMENSION + val - 1] = false;

            groupRow = row - row % SUDOKU_SIZE;
            groupCol = col - col % SUDOKU_SIZE;

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
    for (i = 0; i < DIMENSION; i++)
    {
        for (j = 0; j < DIMENSION; j++)
        {
            cout << get(i, j) << " ";
            if (j % SUDOKU_SIZE == SUDOKU_SIZE - 1 && j < DIMENSION - 1)
            {
                cout << "| ";
            }
        }
        cout << endl;
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
