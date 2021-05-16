#include "Iteration.h"

Iteration::Iteration(int board_size, Iteration* previous_iteration, int queen_row, int queen_column)
{
	board_size_ = board_size;
	actualBoard_ = chess_board(board_size_);
	queenRow_ = queen_row;
	queenColumn_ = queen_column;
	previousIteration_ = previous_iteration;
	actualBoard_.copy_board(previousIteration_->actualBoard_);
	add_queen_on_the_board();
}

Iteration::Iteration(int board_size, int queen_row, int queen_column)
{
	board_size_ = board_size;
	actualBoard_ = chess_board(board_size_);
	queenRow_ = queen_row;
	queenColumn_ = queen_column;
	add_queen_on_the_board();
}


void Iteration::add_queen_on_the_board()
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

void Iteration::trace_back_solution() const
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
