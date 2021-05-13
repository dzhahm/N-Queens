#pragma once
#include <vector>

typedef enum
{
	None,
	OccupiedByQueen,
	Blocked,
	Free
} Availability;

class ChessBoard
{
public:
	int size_;
	std::vector<Availability> board;

	//Constructor
	ChessBoard(int size);

	bool is_position_available(int row, int column);

	bool add_queen(int row, int column);

	void copy_board(ChessBoard board_to_be_copied);

private:

	void InitBoard();

	void update_blocked_positions(int posX, int posY);
};
