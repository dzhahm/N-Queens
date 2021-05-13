#pragma once
#include <string>
#include <vector>

#include "ChessBoard.h"

class PrintResult
{
public:

	int size_;
	std::vector<Availability> result_;

	std::string result_to_be_printed;

	PrintResult(int size, std::vector<Availability> result);

	void print();

	void print_string();

	void print_row_separator();

	void print_row(int row);
};
