#pragma once
#include "ChessBoard.h"

class Iteration
{
public:
	//constructor
	Iteration(int boardSize, int queenRow, int queenColumn);
	Iteration(int boardSize, Iteration* previousIteration, int queenRow, int queenColumn);
	ChessBoard actualBoard_ = ChessBoard(0);
	std::vector<int> find_possible_queen_column_positions();

	void add_queen_on_the_board();

	void new_iteration();

	void trace_back_solution();

	int numberOfQueen_;
	int queenRow_;
	int queenColumn_;
	int board_size_;
	std::vector<int> possible_queen_column_positions_in_the_next_iteration;
	Iteration* previousIteration_;

	ChessBoard solution = ChessBoard(0);
};
