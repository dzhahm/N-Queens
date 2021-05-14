#include "pch.h"

#include <vector>

#include "CppUnitTest.h"
#include "../NQueensProject/PositionsBlockedByQueen.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace n_queens_project_unit_tests
{
	TEST_CLASS(FindingColumnPositionsBlockedByQueen)
	{
	public:
		TEST_METHOD(BlockedPositionsInTheColumn_BoardSize_5)
		{
			//Arrange
			const int board_size = 5;
			const int queen_row_position = 2;
			const int queen_column_position = 2;
			int blocked_positions[] = {2, 7, 17, 22};

			//Act
			PositionsBlockedByQueen positions =
				PositionsBlockedByQueen(board_size, queen_row_position, queen_column_position);
			std::vector<int> blocked_positions_in_the_column = positions.blocked_column_positions;

			//Assert
			if (blocked_positions_in_the_column.size() != 4)
			{
				Assert::Fail();
			}

			for (int blocked_position : blocked_positions)
			{
				bool contains = false;
				for (int blocked_position_in_the_column : blocked_positions_in_the_column)
				{
					if (blocked_position == blocked_position_in_the_column)
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

		TEST_METHOD(BlockedPositionsInTheColumn_BoardSize_6)
		{
			//Arrange
			const int board_size = 6;
			const int queen_row_position = 1;
			const int queen_column_position = 3;
			int blocked_positions[] = {3, 15, 21, 27, 33};

			//Act
			PositionsBlockedByQueen positions =
				PositionsBlockedByQueen(board_size, queen_row_position, queen_column_position);
			std::vector<int> blocked_positions_in_the_column = positions.blocked_column_positions;

			//Assert
			if (blocked_positions_in_the_column.size() != 5)
			{
				Assert::Fail();
			}

			for (int blocked_position : blocked_positions)
			{
				bool contains = false;
				for (int blocked_position_in_the_column : blocked_positions_in_the_column)
				{
					if (blocked_position == blocked_position_in_the_column)
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
