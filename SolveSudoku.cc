#include <iostream>
#include <fstream>
#include <string.h>
#include "CrooksSudokuSolver.h"
#include "RecursiveSudokuSolver.h"
using namespace std;

int main(int argc, char* argv[])
{
    if (!(argc == 2 || argc == 3))
    {
        cerr << "Usage: " << argv[0] << " (-r) [FILE]" << endl;
        return 1;
    }

    bool recursiveOnly = false;
    string fileName;

    if (strcmp(argv[1], "-r") == 0)
    {
        recursiveOnly = true; 
        fileName = argv[2];
    }
    else
    {
        fileName = argv[1];
    }

    ifstream myfile;
    myfile.open(fileName.c_str());

    if (myfile.is_open())
    {
        string line;
        SudokuSolver *solver;
        Sudoku sudok;

        int i = 1;
        while (getline(myfile, line))
        {
            // Check every line, ignoring comment lines
            if (line.length() > 0 && line.at(0) >= '0' && line.at(0) <= '9')
            {
                cout << "Sudoku #" << i << ":" << endl;
                sudok = Sudoku(line);

                if (recursiveOnly)
                {
                    RecursiveSudokuSolver recurs = 
                        RecursiveSudokuSolver (sudok);
                    solver = &recurs;
                }
                else
                {
                    CrooksSudokuSolver crook =
                        CrooksSudokuSolver (sudok);
                    solver = &crook;
                }

                cout << "Before solve:" << endl;
                
                solver->print();

                cout << endl << "After solve:" << endl;
                solver->solve();

                solver->print();

                cout << endl;

                i++;
            }
        }

        return 0;
    }

    cerr << "Error opening file \"" << fileName << endl;   
    return -1;
}
