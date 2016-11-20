#!/bin/bash
# Runs the program on a puzzle twice:
# once normally and once with only recursion.
# The average and standard deviation of the number of guesses made is shown.

AWKCOMMAND='{sum += $NF; sumsq += $NF^2} END{print "Average Recursive Guesses: "sum/NR; print "Standard Deviation of Guesses: "sqrt(sumsq/NR-(sum/NR)^2)}'

echo "Collecting data using the normal algorithm:"
./CollectData.sh $1 | awk "$AWKCOMMAND"

echo

echo "Collecting data using only recursion:"
./CollectData.sh -r $1 | awk "$AWKCOMMAND"
