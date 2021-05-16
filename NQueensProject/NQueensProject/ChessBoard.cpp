#include "ChessBoard.h"

#include "PositionsBlockedByQueen.h"

chess_board::chess_board(int size)
{
	size_ = size;
	init_board();
}

bool chess_board::is_position_available(int row, int column)
{
	const int position = row * size_ + column;
	return board[position] == Free;
}

bool chess_board::add_queen(int row, int column)
{
	if (!is_position_available(row, column))
	{
		return false;
	}
	const int position = row * size_ + column;
	board[position] = OccupiedByQueen;
	update_blocked_positions(row, column);
	return true;
}

void chess_board::init_board()
{
	const int size = size_ * size_;
	for (int i = 0; i < size; i++)
	{
		board.push_back(Free);
	}
}

void chess_board::copy_board(chess_board board_to_be_copied)
{
	if (board_to_be_copied.size_ == size_)
	{
		board.clear();
		board.insert(board.end(), board_to_be_copied.board.begin(), board_to_be_copied.board.end());
	}
}

void chess_board::update_blocked_positions(int row, int column)
{
	const PositionsBlockedByQueen positionsBlockedByQueen = PositionsBlockedByQueen(size_, row, column);

	std::vector<int> positions = positionsBlockedByQueen.get_blocked_positions();

	for (int index : positions)
	{
		if (board[index] == OccupiedByQueen)
		{
			throw new std::exception();
		}
		board[index] = Blocked;
	}
}
