#include "pch.h"

#include <vector>

#include "CppUnitTest.h"
#include "../NQueensProject/PositionsBlockedByQueen.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace n_queens_project_unit_tests
{
	TEST_CLASS(FindingDiagonalLPositionsBlockedByQueen)
	{
	public:
		TEST_METHOD(BlockedPositionsInTheDiagonalL_BoardSize_5)
		{
			//Arrange
			const int board_size = 5;
			const int queen_row_position = 2;
			const int queen_column_position = 1;
			int blocked_positions[] = {3, 7, 15};

			//Act
			PositionsBlockedByQueen positions =
				PositionsBlockedByQueen(board_size, queen_row_position, queen_column_position);
			std::vector<int> blocked_positions_in_the_diagonlL = positions.blocked_diagonal_l_positions;

			//Assert
			if (blocked_positions_in_the_diagonlL.size() != 3)
			{
				Assert::Fail();
			}

			for (int blocked_position : blocked_positions)
			{
				bool contains = false;
				for (int blocked_position_in_the_diagonalL : blocked_positions_in_the_diagonlL)
				{
					if (blocked_position == blocked_position_in_the_diagonalL)
					{
						contains = true;
						break;
					}
				}
				if (!contains)
				{
					Assert::Fail();
				}
			}
		}


		TEST_METHOD(BlockedPositionsInTheDiagonalR_BoardSize_8)
		{
			//Arrange
			const int board_size = 8;
			const int queen_row_position = 3;
			const int queen_column_position = 3;
			int blocked_positions[] = {6, 13, 20, 34, 41, 48};

			//Act
			PositionsBlockedByQueen positions =
				PositionsBlockedByQueen(board_size, queen_row_position, queen_column_position);
			std::vector<int> blocked_positions_in_the_diagonlL = positions.blocked_diagonal_l_positions;

			//Assert
			if (blocked_positions_in_the_diagonlL.size() != 6)
			{
				Assert::Fail();
			}

			for (int blocked_position : blocked_positions)
			{
				bool contains = false;
				for (int blocked_position_in_the_diagonalL : blocked_positions_in_the_diagonlL)
				{
					if (blocked_position == blocked_position_in_the_diagonalL)
					{
						contains = true;
						break;
					}
				}
				if (!contains)
				{
					Assert::Fail();
				}
			}
		}
	};
}
