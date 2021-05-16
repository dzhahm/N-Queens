#include "pch.h"
#include "CppUnitTest.h"
#include "../NQueensProject/Iteration.h"
#include "../NQueensProject/Iteration.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace n_queens_project_unit_tests
{
	TEST_CLASS(NQueensProjectUnitTests)
	{
	public:

		TEST_METHOD(Find_Queen_Positions_Board_Size_8)
		{
			//Arrange
			int boardSize = 8;

			int queenRow = 0;
			int queenColumn = 6;


			int queen_positions[] = {6, 12, 18, 24, 37, 47, 49, 59};

			//Act
			Iteration testIteration = Iteration(boardSize, queenRow, queenColumn);
			std::vector<int> calculated_queen_positions;
			for (int i = 0; i < testIteration.solution.board.size(); i++)
			{
				if (testIteration.solution.board[i] == OccupiedByQueen)
				{
					calculated_queen_positions.push_back(i);
				}
			}

			//Assert

			//If more than expected positions are available, fail the test
			if (calculated_queen_positions.size() != 8)
			{
				Assert::Fail();
			}
			for (int queen_position : queen_positions)
			{
				bool contains = false;
				for (int calculated_queen_position : calculated_queen_positions)
				{
					if (calculated_queen_position == queen_position)
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


		TEST_METHOD(Find_Queen_Positions_Board_Size_5)
		{
			//Arrange
			int boardSize = 5;

			int queenRow = 0;
			int queenColumn = 1;


			int queen_positions[] = {1, 9, 12, 15, 23};

			//Act
			Iteration testIteration = Iteration(boardSize, queenRow, queenColumn);
			std::vector<int> calculated_queen_positions;
			for (int i = 0; i < testIteration.solution.board.size(); i++)
			{
				if (testIteration.solution.board[i] == OccupiedByQueen)
				{
					calculated_queen_positions.push_back(i);
				}
			}

			//Assert

			//If more than expected positions are available, fail the test
			if (calculated_queen_positions.size() != 5)
			{
				Assert::Fail();
			}
			for (int queen_position : queen_positions)
			{
				bool contains = false;
				for (int calculated_queen_position : calculated_queen_positions)
				{
					if (calculated_queen_position == queen_position)
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
