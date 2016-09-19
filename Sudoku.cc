#include <iostream>
#include <stdlib.h>
#include "Sudoku.h"
using namespace std;

Sudoku::Sudoku()
{
    dimension = SUDOKU_SIZE * SUDOKU_SIZE;
    remaining = dimension * dimension;

    for (int i = 0; i < dimension * dimension; i++)
    {
        grid[i] = 0;
    }
}

Sudoku::Sudoku(string numbers)
{
    dimension = SUDOKU_SIZE * SUDOKU_SIZE;
    remaining = dimension * dimension;
    int num, i;

    for (i = 0; i < dimension * dimension; i++)
    {
        num = numbers[i] - '0';
        grid[i] = num;

        if (num > 0)
            remaining--;
    }
}

bool Sudoku::set(int absolute, int val)
{
    return set(absolute / dimension, absolute % dimension, val);
}

bool Sudoku::set(int row, int col, int val)
{
    if (isValidMove(row, col, val))
    {
        if (get(row, col) == 0 && val > 0)
            remaining--;
        else if (get(row, col) > 0 && val == 0)
            remaining++;

        grid[row * dimension + col] = val;

        return true;
    }

    return false;
}

bool Sudoku::isValidMove(int row, int col, int val)
{
    if (val == 0)
        return true;

    if (val < 1 || val > dimension)
        return false;

    if (get(row, col) == val)
        return true;

    int i;
    int gRow, gCol;
    for (i = 0; i < dimension; i++)
    {
        gRow = row - row % SUDOKU_SIZE;
        gCol = col - col % SUDOKU_SIZE;

        if (get(i, col) == val || get(row, i) == val
            || get(gRow + i / SUDOKU_SIZE, gCol + i % SUDOKU_SIZE) == val)
        {
            return false;
        }
    }
    return true;
}

void Sudoku::print()
{
    cout << "Sudoku with " << remaining << " remaining:" << endl;
    int i, j, k;
    for (i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            cout << get(i, j) << " ";
            if (j % SUDOKU_SIZE == SUDOKU_SIZE - 1 && j < dimension - 1)
            {
                cout << "| ";
            }
        }
        cout << endl;
        if (i % SUDOKU_SIZE == SUDOKU_SIZE - 1 && i < dimension - 1)
        {
            for (k = 0; k < (dimension + SUDOKU_SIZE - 1) * 2 - 1; k++)
            {
                cout << "-";
            }
            cout << endl;
        }
    }
    cout << endl;
}
