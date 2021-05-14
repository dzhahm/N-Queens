#include "pch.h"
#include "CppUnitTest.h"
#include "../NQueensProject/PositionsBlockedByQueen.h"
#include "../NQueensProject/PositionsBlockedByQueen.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace n_queens_project_unit_tests
{
	TEST_CLASS(FindingRowPositionsBlockedByQueen)
	{
	public:
		TEST_METHOD(BlockedPositionsInTheRow_BoardSize_5)
		{
			//Arrange
			const int board_size = 5;
			const int queen_row_position = 2;
			const int queen_column_position = 2;
			int blocked_positions[] = {10, 11, 13, 14};

			//Act
			PositionsBlockedByQueen positions =
				PositionsBlockedByQueen(board_size, queen_row_position, queen_column_position);
			std::vector<int> blocked_positions_in_the_row = positions.blocked_row_positions;

			//Assert
			if (blocked_positions_in_the_row.size() != 4)
			{
				Assert::Fail();
			}

			for (int blocked_position : blocked_positions)
			{
				bool contains = false;
				for (int blocked_position_in_the_row : blocked_positions_in_the_row)
				{
					if (blocked_position == blocked_position_in_the_row)
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


		TEST_METHOD(BlockedPositionsInTheRow_BoardSize_6)
		{
			//Arrange
			const int board_size = 6;
			const int queen_row_position = 4;
			const int queen_column_position = 1;
			int blocked_positions[] = {24, 26, 27, 28, 29};

			//Act
			PositionsBlockedByQueen positions =
				PositionsBlockedByQueen(board_size, queen_row_position, queen_column_position);
			std::vector<int> blocked_positions_in_the_row = positions.blocked_row_positions;

			//Assert
			if (blocked_positions_in_the_row.size() != 5)
			{
				Assert::Fail();
			}

			for (int blocked_position : blocked_positions)
			{
				bool contains = false;
				for (int blocked_position_in_the_row : blocked_positions_in_the_row)
				{
					if (blocked_position == blocked_position_in_the_row)
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
