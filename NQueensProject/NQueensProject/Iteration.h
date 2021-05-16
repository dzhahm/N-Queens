#pragma once
#include "ChessBoard.h"

class Iteration
{
public:
	//constructor
	/**
	 * \brief: Start problem solving with the first row of the chess board
	 * \param board_size:  Size of the NxN board. N = size
	 * \param queen_row:  Row position of the queen. It is a number [0, size]
	 * \param queen_column:  Row position of the queen. It is a number [0, size]
	 */
	Iteration(int board_size, int queen_row, int queen_column);

	//constructor
	/**
	 * \brief: Start problem solving with the first row of the chess board
	 * \param board_size: Size of the NxN board. N = size
	 * \param previous_iteration: Pointer to the previous iteration.  
	 * \param queen_row:  Row position of the queen. It is a number [0, size]
	 * \param queen_column:  Row position of the queen. It is a number [0, size]
	 */
	Iteration(int board_size, Iteration* previous_iteration, int queen_row, int queen_column);

	chess_board actualBoard_ = chess_board(0);

	std::vector<int> find_possible_queen_column_positions();

	void add_queen_on_the_board();

	//Start a new iteration for possible queen position in the upper row
	void new_iteration();

	//After finding a solution, return it back to the parent iteration
	void trace_back_solution() const;

	int numberOfQueen_{};
	int queenRow_;
	int queenColumn_;
	int board_size_;
	std::vector<int> possible_queen_column_positions_in_the_next_iteration;
	Iteration* previousIteration_{};

	chess_board solution = chess_board(0);
};
