#ifndef DAY_08_H_
#define DAY_08_H_

#include "../utils/pch.h"

namespace day08
{
struct Signal
{
	std::vector<std::string> signal_patterns;
	std::vector<std::string> output;
};

struct Digit
{
	Digit() { segments.resize(7); }

	/*
	 *  0000
	 * 1    2
	 * 1    2
	 *  3333
	 * 4    5
	 * 4    5
	 *  6666
	 */

	std::vector<std::string> segments;
};

std::vector<Signal>
read_input_file(std::string input_path);

i32
do_part_01(std::vector<Signal>& input);

i32
do_part_02(std::vector<Signal>& input);

}  // namespace day08

#endif	// DAY_08_H_
