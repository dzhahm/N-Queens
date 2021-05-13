// NQueensProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ChessBoard.h"
#include "Iteration.h"
#include "PrintResult.h"

int main()
{
	int boardSize = 8;

	Iteration testIteration = Iteration(boardSize, 0, 0);

	PrintResult print_result = PrintResult(boardSize, testIteration.solution.board);

	print_result.print();
}
