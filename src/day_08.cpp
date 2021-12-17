#include "day_08.hpp"

namespace day08
{

std::vector<Signal>
read_input_file(std::string input_path)
{
	std::vector<Signal> signals;
	std::string arg;

	std::ifstream input_file(input_path);
	if (input_file.is_open()) {
		std::string line;
		while (std::getline(input_file, line)) {
			Signal signal;
			std::istringstream iss(line);
			// std::cout << iss.str() << '\n';

			std::string cur_str;
			while (iss >> cur_str) {
				if (cur_str == "|") break;
				signal.signal_patterns.push_back(cur_str);
			}
			while (iss >> cur_str) {
				signal.output.push_back(cur_str);
			}
			signals.push_back(signal);
		}
	}
	return signals;
}

i32
do_part_01(std::vector<Signal>& input)
{
	i32 res {};
	for (auto signal : input) {
		for (auto output : signal.output) {
			if (output.length() == 2 || output.length() == 3 || output.length() == 4 ||
				output.length() == 7) {
				++res;
				std::cout << "res: " << res << '\n';
			}
		}
	}
	return res;
}

i32
do_part_02(std::vector<Signal>& input)
{
	std::cout << "Part 2 not implmented yet\n";
	return 0;
}

}  // namespace day08
