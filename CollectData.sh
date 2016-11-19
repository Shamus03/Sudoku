#!/bin/bash
# This script has the same syntax as the original program.
# Its purpose is to print the data given by the program
# in a tabular form to simplify analysis.

./SolveSudoku $@ | grep -E "(: |Sudoku #)" | awk '{print $NF}' | tr -s '\n:' ' ' | tr '#' '\n'
