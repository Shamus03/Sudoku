#include <iostream>
#include <fstream>
#include "RecursiveSudokuSolver.h"
using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << " [FILE]" << endl;
        return 1;
    }
    
    string fileName = argv[1];

    ifstream myfile;
    myfile.open(fileName.c_str());

    if (myfile.is_open())
    {
        string line;

        int i = 0;
        while (getline(myfile, line))
        {
            cout << "Sudoku #" << i++ << ":" << endl;

            RecursiveSudokuSolver solver = RecursiveSudokuSolver (Sudoku(line));

            cout << "Before solve:" << endl;
            solver.print();

            cout << endl << "After solve:" << endl;
            if (solver.solve())
            {
                solver.print();
            }
            else
            {
                cout << endl << "No solution." << endl;
            }

            cout << endl;
        }

        return 0;
    }

    cerr << "Error opening file \"" << fileName << endl;   
    return -1;
}
