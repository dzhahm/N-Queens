#include "pch.h"
#include "CppUnitTest.h"
#include "../NQueensProject/ChessBoard.h"
#include "../NQueensProject/ChessBoard.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace n_queens_project_unit_tests
{
	TEST_CLASS(FindingAllPositions)
	{
	public:
		TEST_METHOD(BlockedPositions_BoardSize_5)
		{
			//Arrange
			const int board_size = 5;
			const int queen_row_position = 1;
			const int queen_column_position = 3;
			int blocked_positions[] = {2, 3, 4, 5, 6, 7, 9, 12, 13, 14, 16, 18, 20, 23};

			//Act
			chess_board chess_board =
				chess_board(board_size);
			chess_board.add_queen(queen_row_position, queen_column_position);
			std::vector<int> blocked_positions_queen;
			for (int i = 0; i < chess_board.board.size(); i++)
			{
				if (chess_board.board[i] == Blocked)
				{
					blocked_positions_queen.push_back(i);
				}
			}

			//Assert

			if (blocked_positions_queen.size() != 14)
			{
				Assert::Fail();
			}

			for (int blocked_position : blocked_positions)
			{
				bool contains = false;
				for (int blocked_position_in_the_row : blocked_positions_queen)
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

		TEST_METHOD(BlockedPositions_BoardSize_8)
		{
			//Arrange
			const int board_size = 8;
			const int queen_row_position = 7;
			const int queen_column_position = 7;
			int blocked_positions[] = {0, 7, 9, 15, 18, 23, 27, 31, 36, 39, 45, 47, 54, 55, 56, 57, 58, 59, 60, 61, 62};

			//Act
			chess_board chess_board =
				chess_board(board_size);
			chess_board.add_queen(queen_row_position, queen_column_position);
			std::vector<int> blocked_positions_queen;
			for (int i = 0; i < chess_board.board.size(); i++)
			{
				if (chess_board.board[i] == Blocked)
				{
					blocked_positions_queen.push_back(i);
				}
			}

			//Assert
			if (blocked_positions_queen.size() != 21)
			{
				Assert::Fail();
			}


			for (int blocked_position : blocked_positions)
			{
				bool contains = false;
				for (int blocked_position_in_the_row : blocked_positions_queen)
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
