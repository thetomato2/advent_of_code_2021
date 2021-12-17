#include "day_01.hpp"

namespace day01
{
std::vector<i32>
read_input_file(std::string input_path)
{
	std::vector<i32> res;

	std::ifstream input_01_file(input_path);
	std::string cur_line;

	if (input_01_file.is_open()) {
		while (std::getline(input_01_file, cur_line)) {
			res.push_back(std::stoi(cur_line));
		}
	} else {
		std::cout << "Failed to open " << input_path << "!\n";
	}

	return res;
}

i32
do_part_01(std::vector<i32>& input)
{
	i32 res {};
	i32 prev_n {};
	prev_n = input.front();

	for (szt i {}; i < input.size(); ++i) {
		auto n = input[i];
		if (n > prev_n) ++res;
		prev_n = n;
	}

	return res;
}

i32
do_part_02(std::vector<i32>& input)
{
	i32 res {};

	for (szt i { 3 }; i < input.size(); ++i) {
		i32 a = input[i - 3] + input[i - 2] + input[i - 1];
		i32 b = input[i - 2] + input[i - 1] + input[i];
		if (b > a) ++res;
	}

	return res;
}

}  // namespace day01
