#include "Iteration.h"

Iteration::Iteration(int boardSize, Iteration* previousIteration, int queenRow, int queenColumn)
{
	board_size_ = boardSize;
	actualBoard_ = ChessBoard(board_size_);
	queenRow_ = queenRow;
	queenColumn_ = queenColumn;
	previousIteration_ = previousIteration;
	actualBoard_.copy_board(previousIteration_->actualBoard_);
	addQueenOnTheBoard();
}

Iteration::Iteration(int boardSize, int queenRow, int queenColumn)
{
	board_size_ = boardSize;
	actualBoard_ = ChessBoard(board_size_);
	queenRow_ = queenRow;
	queenColumn_ = queenColumn;
	addQueenOnTheBoard();
}


void Iteration::addQueenOnTheBoard()
{
	actualBoard_.add_queen(queenRow_, queenColumn_);
	if (queenRow_ < board_size_ - 1)
	{
		possible_queen_column_positions_in_the_next_iteration = find_possible_queen_column_positions();
		new_iteration();
	}
	if (queenRow_ == board_size_ - 1)
	{
		solution = actualBoard_;
		trace_back_solution();
	}
}

void Iteration::trace_back_solution()
{
	if (queenRow_ == 0)
	{
		return;
	}
	previousIteration_->solution = solution;
	previousIteration_->trace_back_solution();
}


std::vector<int> Iteration::find_possible_queen_column_positions()
{
	std::vector<int> temp;
	for (int i = 0; i < board_size_; i++)
	{
		if (actualBoard_.is_position_available(queenRow_ + 1, i))
		{
			temp.push_back(i);
		}
	}
	return temp;
}

void Iteration::new_iteration()
{
	for (int i : possible_queen_column_positions_in_the_next_iteration)
	{
		Iteration newIteration = Iteration(board_size_, this, queenRow_ + 1, i);
	}
}
