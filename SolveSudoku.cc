#include <iostream>
#include <fstream>
#include "CrooksSudokuSolver.h"
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

        int i = 1;
        while (getline(myfile, line))
        {
            if (line.length() > 0 && line.at(0) >= '0' && line.at(0) <= '9')
            {
                cout << "Sudoku #" << i << ":" << endl;

                CrooksSudokuSolver solver =
                    CrooksSudokuSolver (Sudoku(line));

                cout << "Before solve:" << endl;
                
                solver.print();

                cout << endl << "After solve:" << endl;
                solver.solve();

                solver.print();

                cout << endl;

                i++;
            }
        }

        return 0;
    }

    cerr << "Error opening file \"" << fileName << endl;   
    return -1;
}
