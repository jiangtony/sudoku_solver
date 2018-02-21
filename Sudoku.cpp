// Created by: Tony Jiang

#include <iostream>
#include "SudokuSolver.h"

using namespace std;

int main(int argc, char* argv[])
{
    if(argc != 2) {
        cout << "Usage: ./sudoku [input file]" ;
        return 0;
    }

	// Create an object of type SudokuSolver
    SudokuSolver game(argv[1]);
	
    if(!game.getFileError()) {
    	// Solve the puzzle
        while(!game.SolvePuzzle(10000)) {
            game.SolvePuzzle(10000);
        }
    	
    	//Display the puzzle
        game.DisplayPuzzle();
    }
}
