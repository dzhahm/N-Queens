#include "PrintResult.h"

#include <iostream>

#include "ChessBoard.h"


PrintResult::PrintResult(int size, std::vector<Availability> result)
{
	size_ = size;
	result_ = result;
}

void PrintResult::print()
{
	print_string();
	std::cout << result_to_be_printed;
}

void PrintResult::print_string()
{
	for (int i = 1; i <= size_; i++)
	{
		print_row_separator();
		print_row(size_ - i);
	}
	print_row_separator();
}


void PrintResult::print_row(int row)
{
	char row_number = static_cast<char>(row + 48);
	result_to_be_printed.push_back(row_number);
	result_to_be_printed.push_back(' ');
	result_to_be_printed.push_back('|');
	for (int i = 0; i < size_; i++)
	{
		int index = (row) * size_ + i;
		char position;
		switch (result_[index])
		{
		case OccupiedByQueen:
			position = 'Q';
			break;
		default:
			position = '_';
			break;
		}
		result_to_be_printed.push_back(position);
		result_to_be_printed.push_back('|');
	}
	result_to_be_printed.push_back('\n');
}

void PrintResult::print_row_separator()
{
	result_to_be_printed.push_back(' ');
	result_to_be_printed.push_back(' ');
	for (int i = 0; i < size_; i++)
	{
		result_to_be_printed.push_back(' ');
		result_to_be_printed.push_back('_');
	}
	result_to_be_printed.push_back('\n');
}
