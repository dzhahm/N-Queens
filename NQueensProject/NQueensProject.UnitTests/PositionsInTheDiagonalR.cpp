#include "pch.h"

#include <vector>

#include "CppUnitTest.h"
#include "../NQueensProject/PositionsBlockedByQueen.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace n_queens_project_unit_tests
{
	TEST_CLASS(FindingDiagonalRPositionsBlockedByQueen)
	{
	public:
		TEST_METHOD(BlockedPositionsInTheDiagonalR_BoardSize_5)
		{
			//Arrange
			const int board_size = 5;
			const int queen_row_position = 1;
			const int queen_column_position = 0;
			int blocked_positions[] = {11, 17, 23};

			//Act
			PositionsBlockedByQueen positions =
				PositionsBlockedByQueen(board_size, queen_row_position, queen_column_position);
			std::vector<int> blocked_positions_in_the_diagonlR = positions.blocked_diagonal_r_positions;

			//Assert
			if (blocked_positions_in_the_diagonlR.size() != 3)
			{
				Assert::Fail();
			}

			for (int blocked_position : blocked_positions)
			{
				bool contains = false;
				for (int blocked_position_in_the_diagonalR : blocked_positions_in_the_diagonlR)
				{
					if (blocked_position == blocked_position_in_the_diagonalR)
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


		TEST_METHOD(BlockedPositionsInTheDiagonalR_BoardSize_6)
		{
			//Arrange
			const int board_size = 8;
			const int queen_row_position = 5;
			const int queen_column_position = 6;
			int blocked_positions[] = {1, 10, 19, 28, 37, 55};

			//Act
			PositionsBlockedByQueen positions =
				PositionsBlockedByQueen(board_size, queen_row_position, queen_column_position);
			std::vector<int> blocked_positions_in_the_diagonlR = positions.blocked_diagonal_r_positions;

			//Assert
			if (blocked_positions_in_the_diagonlR.size() != 6)
			{
				Assert::Fail();
			}

			for (int blocked_position : blocked_positions)
			{
				bool contains = false;
				for (int blocked_position_in_the_diagonalR : blocked_positions_in_the_diagonlR)
				{
					if (blocked_position == blocked_position_in_the_diagonalR)
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
