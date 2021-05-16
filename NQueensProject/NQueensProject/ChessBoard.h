#pragma once
#include <vector>

typedef enum
{
	None,
	OccupiedByQueen,
	Blocked,
	Free
} Availability;

class chess_board
{
public:
	int size_;
	std::vector<Availability> board;

	//Constructor
	/**
	 * \brief It is used to construct the chess board object
	 * \param size Size defines two dimensional size of the board. More specifically NxN sized board is defined as size x size
	 */
	chess_board(int size);

	bool is_position_available(int row, int column);

	bool add_queen(int row, int column);

	void copy_board(chess_board board_to_be_copied);

private:

	void init_board();

	void update_blocked_positions(int posX, int posY);
};
