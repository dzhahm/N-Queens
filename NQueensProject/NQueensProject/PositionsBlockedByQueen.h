#pragma once
#include <vector>

class PositionsBlockedByQueen
{
public:

	//Constructor
	PositionsBlockedByQueen(int boardSize, int row, int column);
	std::vector<int> get_blocked_positions() const;

	std::vector<int> blocked_row_positions;
	std::vector<int> blocked_column_positions;
	std::vector<int> blocked_diagonal_r_positions;
	std::vector<int> blocked_diagonal_l_positions;

private:

	// e.g Board size is 5, posX  = 2 , posY = 2
	//	_ _ _ _ _
	// |X|_|X|_|X| 
	// |_|X|X|X|_|
	// |X|X|Q|X|X| 
	// |_|X|X|X|_|
	// |X|_|X|_|X| 
	void add_positions(int boardSize, int row, int column);


	// e.g Board size is 5, posX  = 1 , posY = 2
	//	_ _ _ _ _
	// |_|_|_|_|_| 
	// |_|_|_|_|_|
	// |X|Q|X|X|X| 
	// |_|_|_|_|_|
	// |_|_|_|_|_| 
	void add_blocked_row_positions(int boardSize, int row, int column);


	// 	e.g Board size is 5, posX  = 3 , posY = 1
	//	_ _ _ _ _
	// |_|_|_|X|_| 
	// |_|_|_|X|_|
	// |_|_|_|X|_| 
	// |_|_|_|Q|_|
	// |_|_|_|X|_| 
	void add_blocked_column_positions(int boardSize, int row, int column);


	// e.g Board size is 5, posX  = 1 , posY = 1
	//  _ _ _ _ _
	// |_|_|_|_|X| 
	// |_|_|_|X|_|
	// |_|_|X|_|_| 
	// |_|Q|_|_|_|
	// |X|_|_|_|_| 
	void add_blocked_diagonal_r_positions(int boardSize, int row, int column);


	// e.g Board size is 5, posX  = 1 , posY = 3
	//	_ _ _ _ _
	// |X|_|_|_|_| 
	// |_|Q|_|_|_|
	// |_|_|X|_|_| 
	// |_|_|_|X|_|
	// |_|_|_|_|X| 
	void add_blocked_diagonal_l_positions(int boardSize, int row, int column);
};
