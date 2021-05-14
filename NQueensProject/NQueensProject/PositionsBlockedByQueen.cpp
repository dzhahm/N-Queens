#include "PositionsBlockedByQueen.h"

PositionsBlockedByQueen::PositionsBlockedByQueen(int boardSize, int queenRow, int queenColumn)
{
	add_positions(boardSize, queenRow, queenColumn);
}


std::vector<int> PositionsBlockedByQueen::get_blocked_positions() const
{
	std::vector<int> positions;
	positions.insert(positions.end(), blocked_row_positions.begin(), blocked_row_positions.end());
	positions.insert(positions.end(), blocked_column_positions.begin(), blocked_column_positions.end());
	positions.insert(positions.end(), blocked_diagonal_r_positions.begin(), blocked_diagonal_r_positions.end());
	positions.insert(positions.end(), blocked_diagonal_l_positions.begin(), blocked_diagonal_l_positions.end());
	return positions;
}


// e.g Board size is 5, posX  = 2 , posY = 2
//	_ _ _ _ _
// |X|_|X|_|X| 
// |_|X|X|X|_|
// |X|X|Q|X|X| 
// |_|X|X|X|_|
// |X|_|X|_|X| 
void PositionsBlockedByQueen::add_positions(int boardSize, int queenRow, int queenColumn)
{
	add_blocked_row_positions(boardSize, queenRow, queenColumn);
	add_blocked_column_positions(boardSize, queenRow, queenColumn);
	add_blocked_diagonal_r_positions(boardSize, queenRow, queenColumn);
	add_blocked_diagonal_l_positions(boardSize, queenRow, queenColumn);
}


// e.g Board size is 5, posX  = 1 , posY = 2
//	_ _ _ _ _
// |_|_|_|_|_| 
// |_|_|_|_|_|
// |X|Q|X|X|X| 
// |_|_|_|_|_|
// |_|_|_|_|_| 
void PositionsBlockedByQueen::add_blocked_row_positions(int boardSize, int queenRow, int queenColumn)
{
	//Go through the row where the queen stands. From left to the right.
	for (int i = 0; i < boardSize; i++)
	{
		//if the position in the row is already occupied by the queen, ignore it. 
		if (i != queenColumn)
		{
			blocked_row_positions.push_back(boardSize * queenRow + i);
		}
	}
}

// 	e.g Board size is 5, posX  = 3 , posY = 1
//	_ _ _ _ _
// |_|_|_|X|_| 
// |_|_|_|X|_|
// |_|_|_|X|_| 
// |_|_|_|Q|_|
// |_|_|_|X|_| 
void PositionsBlockedByQueen::add_blocked_column_positions(int boardSize, int queenRow, int queenColumn)
{
	//Go through the column where the queen stands. From bottom to the up.
	for (int i = 0; i < boardSize; i++)
	{
		//if the position in the column is already occupied by the queen, ignore it. 
		if (i != queenRow)
		{
			blocked_column_positions.push_back(boardSize * i + queenColumn);
		}
	}
}

// e.g Board size is 5, posX  = 1 , posY = 1
//  _ _ _ _ _
// |_|_|_|_|X| 
// |_|_|_|X|_|
// |_|_|X|_|_| 
// |_|Q|_|_|_|
// |X|_|_|_|_| 
void PositionsBlockedByQueen::add_blocked_diagonal_r_positions(int boardSize, int queenRow, int queenColumn)
{
	int actualPos = boardSize * queenRow + queenColumn;

	//Go through the right diagonal where the queen stands. Start from the queens position and go to up and right.
	int i = 1;
	int j = 1;
	while (queenColumn + i < boardSize && queenRow + j < boardSize)
	{
		blocked_diagonal_r_positions.push_back(boardSize * (queenRow + j) + queenColumn + i);
		i++;
		j++;
	}

	i = 1;
	j = 1;
	//Go through the right diagonal where the queen stands. Start from the queens position and go to bottom and left.
	while (queenColumn - i >= 0 && queenRow - j >= 0)
	{
		blocked_diagonal_r_positions.push_back(boardSize * (queenRow - j) + queenColumn - i);
		i++;
		j++;
	}
}

// e.g Board size is 5, posX  = 1 , posY = 3
//	_ _ _ _ _
// |X|_|_|_|_| 
// |_|Q|_|_|_|
// |_|_|X|_|_| 
// |_|_|_|X|_|
// |_|_|_|_|X| 
void PositionsBlockedByQueen::add_blocked_diagonal_l_positions(int boardSize, int queenRow, int queenColumn)
{
	int actual_pos = boardSize * queenRow + queenColumn;

	//Go through the left diagonal where the queen stands. Start from the queens position and go to up and left.
	int i = 1;
	int j = 1;
	while (queenColumn - i >= 0 && queenRow + j < boardSize)
	{
		blocked_diagonal_l_positions.push_back(boardSize * (queenRow + j) + queenColumn - i);
		i++;
		j++;
	}

	i = 1;
	j = 1;
	//Go through the left diagonal where the queen stands. Start from the queens position and go to bottom and right.
	while (queenColumn + i < boardSize && queenRow - j >= 0)
	{
		blocked_diagonal_l_positions.push_back(boardSize * (queenRow - j) + queenColumn + i);
		i++;
		j++;
	}
}
