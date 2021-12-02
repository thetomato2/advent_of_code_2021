#include "../utils/pch.h"

s32
main()
{
	std::string input_01_path { "day_01_input_01.txt" };
	std::ifstream input_01_file(input_01_path);
	std::vector<s32> nums;
	std::string cur_line;

	if (input_01_file.is_open()) {
		while (std::getline(input_01_file, cur_line)) {
			nums.push_back(std::stoi(cur_line));
		}
	} else {
		std::cout << "Failed to open " << input_01_path << "!\n";
	}

	// =========================================================
	// part 1
	// =========================================================

	s32 inc_cnt {};
	s32 prev_n {};
	prev_n = nums.front();

	for (szt i {}; i < nums.size(); ++i) {
		auto n = nums[i];
		if (n > prev_n) ++inc_cnt;
		prev_n = n;
	}

	std::cout << "Increase count: " << inc_cnt << std::endl;

	// =========================================================
	// part 2
	// =========================================================

	s32 sum_inc_cnt {};

	for (szt i { 3 }; i < nums.size(); ++i) {
		s32 a = nums[i - 3] + nums[i - 2] + nums[i - 1];
		s32 b = nums[i - 2] + nums[i - 1] + nums[i];
		if (b > a) ++sum_inc_cnt;
	}
	std::cout << "Sum ncrease count: " << sum_inc_cnt << std::endl;
}
