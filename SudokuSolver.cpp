// Created by: Tony Jiang

#include "SudokuSolver.h"
#include <fstream>
#include <iostream>
#include <cmath> //for pow function

// Reads the file into the array and pushes the position of the first zero found onto the stack
SudokuSolver::SudokuSolver(string filename)
{
    fileError = !readInputFile(filename);
    stack.Push(nextEmpty());
    stepsUsed = 0;
} // end constructor


bool SudokuSolver::insert(int number, int row, int col)
{
    // Cannot insert a number greater than 9
    if (number > 9)
        return false;

    board[row][col] = number;

    // Check row
    int rowCount = 0;
    for (int i = 0; i < 9 ; i++) {
        if (board[row][i] == number)
            rowCount++;
    } // end for

    if (rowCount > 1) // If number appears more than once in a row, invalid entry
        return false;

    // Check column
    int colCount = 0;
    for (int i = 0; i < 9 ; i++) {
        if (board[i][col] == number)
            colCount++;
    } // end for
    if (colCount > 1) // If number appears more than once in a column, invalid entry
        return false;

    // Check box
    int boxCount = 0;
    // Given any position on the board, find the first position in the corresponding 3x3 box
    int rowStart = row-(row%3);
    int colStart = col-(col%3);

    for (int i = 0; i < 3 ; i++)
        for(int j = 0 ; j < 3 ; j++)
            if (board[rowStart+i][colStart+j] == number)
                boxCount++;
    if (boxCount > 1) // If number appears more than once in the box, invalid entry
        return false;

    return true;
} // end insert


bool SudokuSolver::remove(int row, int col)
{
    //Changes the space back to 0
    board[row][col] = 0;
    return true; // Returns true because 0 is always valid
} // end remove


// Pops the stack
bool SudokuSolver::goBack()
{
    stack.Pop();
    return true;
}

// Searches for a zero in the array
int SudokuSolver::nextEmpty() const
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 ; j++) {
            if (board[i][j] == 0) {
                int position = i*9+j;
                return position; // Returns the position of the zero (from 0-80)
            }
        }
    } //end for

    return -1; // Returns -1 when there are no more zeroes in the array
} // end nextEmpty

bool SudokuSolver::readInputFile(string filename)
{
    ifstream input;
        input.open(filename);
    if(input.fail()) {
        cerr << "Input file open failed." << endl;
        return false;
    }
    int number, index = 0;

    while (input >> number) {
        board[0][index] = number;
        index++;
    } // end while
    input.close();

    return true;
} // end readInputFile


bool SudokuSolver::SolvePuzzle(int maxBackSteps)
{
    if (stepsUsed >= maxBackSteps)
    {
        string continueSolving;
        cout << "Max steps reached. Do you want to continue? Type yes or no: " ;
        cin.clear();
        cin >> continueSolving;
        cin.ignore();
        if (continueSolving == "no") // Stop solving
        {
            cout << "Stopped." << endl;
            return true;
        }
        else // Reset stepsUsed and continue solving
            stepsUsed = 0;
    }

    // Displaying the puzzles's progress towards the solution
    // DisplayPuzzle(); // Comment out if you only want to see the final result

    int position = stack.Peek();

    if (position == -1) // If no more zeroes on the board, game is complete
        return true;

    // Converting the position from nextEmpty() back to row and column format
    // Alternative: Equivalent to board[0][position]
    int row = position/9;
    int col = position%9;

    // If we backtrack into a 9, we reset it to zero and backtrack again
    if (board[row][col] == 9)
    {
        stepsUsed++;
        remove(row,col);
        goBack();
        return false;
    }

    // i starts at whatever number is currently in the position on the board
    // If i = 0, we haven't touched that space yet
    // If i > 0, we backtracked to this space and now need to try more numbers
    // Example: If we backtrack into a 4, we start testing at 5 and up
    for (int i = board[row][col] + 1; i < 9; i++) //Testing numbers up to 8
    {
        stepsUsed++;
        if (insert(i, row, col))
        {
            stack.Push(nextEmpty());
            return false;
        }
    } // end for

    // At this point, 1-8 are invalid, so we test 9
    // If 9 is also invalid, we set it to 0 and backtrack
    bool nine = insert(9, row, col);
    if (nine==true)
    {
        stack.Push(nextEmpty());
        return false;
    }
    else if (nine == false)
    {
        remove(row,col);
        goBack();
    }

    stepsUsed++;

    return false;

} // end SolvePuzzle

void SudokuSolver::DisplayPuzzle()
{
    if (!fileError) {
        for (int i = 0; i < 9 ; i++)
        {
            for (int j = 0; j < 9 ; j++)
            {
                cout << board[i][j]  << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
} // end DisplayPuzzle

bool SudokuSolver::getFileError()
{
    return fileError;
}

// End of implementation file