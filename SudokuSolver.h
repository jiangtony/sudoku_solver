// Created by: Tony Jiang

/* Sudoku Solver using Linked-Stack implementation */

#ifndef SUDOKU_SOLVER_H
#define SUDOKU_SOLVER_H

#include <array>
#include <vector>
#include "LinkedStack.h"


class SudokuSolver
{
private:
    // The array that stores the game board
    int board[9][9];

    // True if error opening input file
    bool fileError;

    // The stack holds the positions of the array that have been changed
    LinkedStack<int> stack;

    // Stores the number of steps used
    // Every attempt to insert a number or backtrack counts as a step
    int stepsUsed;

    // Inserts a number into the game board
    // @post A valid number has been inserted onto the board
    // @param number The number you are trying to enter
    // @param row The row you are trying to enter the number
    // @param col The column you are trying to enter the number
    // @return true if valid entry, false if invalid
    bool insert(int number, int row, int col);

    // Used when none of the numbers 1-9 fit into the position, meaning we need to backtrack
    // @post Sets the number at the position back to 0
    // @param int The row of the position
    // @param row The column of the position
    // @return Always returns true because its always valid to insert 0
    bool remove(int row, int col);

    // Pops the stack
    // @return True because only used when the stack is not empty
    bool goBack();

    // Finds the next position in the array that contains a zero
    // @post Returns the position as a single integer using (row*9 + column)
    // @return Returns the position of the zero in the array
    int nextEmpty() const;

    // Reads a sudoku puzzle from a text file and stores it into our private member array
    // @param filename The name of the text file
    // @return True if successful, false if error reading the file
    bool readInputFile(string filename);

public:
    // constructor
    SudokuSolver(string filename);

    // Solves the Sudoku puzzle
    // @param maxBackSteps The maximum number of steps the function can perform
    //        before the user can decide if they want to continue or not
    // @return Returns true if successfully solves the puzzle, false otherwise
    bool SolvePuzzle(int maxBackSteps);

    // Displays the current state of the puzzle
    void DisplayPuzzle();

    // Checks if there was an error opening the file
    bool getFileError();

};

#include "SudokuSolver.cpp"

#endif // SUDOKU_SOLVER_H
