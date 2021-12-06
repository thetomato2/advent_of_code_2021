#include "../utils/pch.h"

s32
main()
{
	util::Timer timer;
	timer.mark();

	std::string input_path { "day_06_input.txt" };
	std::ifstream input_file(input_path);

	std::vector<s32> fishies;

	if (input_file.is_open()) {
		std::string num;
		while (std::getline(input_file, num, ',')) {
			fishies.push_back(std::stoi(num));
		}
	}
	//

	//========================================================
	// part 1
	//========================================================

	// brute force method
	auto fishies_part_1			  = fishies;
	constexpr s32 num_days_part_1 = 80;
	for (s32 day {}; day < num_days_part_1; ++day) {
		// cache the size becasue if you add to the vector it invalidates
		// its iterators, so no ranged for etc
		szt cur_sz = fishies_part_1.size();
		for (szt i {}; i < cur_sz; ++i) {
			if (fishies_part_1[i] == 0) {
				fishies_part_1[i] = 6;
				fishies_part_1.push_back(8);
			} else {
				--fishies_part_1[i];
			}
		}
	}

	std::cout << "Number of fish after " << num_days_part_1 << " is " << fishies_part_1.size()
			  << ".\n";

	auto time_end = timer.mark();
	std::cout << "Time: " << time_end * 1000.f << "ms\n";

	//========================================================
	// part 2
	//========================================================
	constexpr s32 num_days_part_2 = 256;

	auto fishies_part_2 = fishies;
	timer.mark();

	// big brain method
	// could use a vector, but meh
	u64 fish_arr[9] {};
	for (const auto i : fishies) {
		++fish_arr[i];
	}

	for (int i = {}; i < num_days_part_2; ++i) {
		u64 tmp		= fish_arr[0];
		fish_arr[0] = fish_arr[1];
		fish_arr[1] = fish_arr[2];
		fish_arr[2] = fish_arr[3];
		fish_arr[3] = fish_arr[4];
		fish_arr[4] = fish_arr[5];
		fish_arr[5] = fish_arr[6];
		fish_arr[6] = fish_arr[7];
		fish_arr[7] = fish_arr[8];
		fish_arr[8] = tmp;
		fish_arr[6] += tmp;
	}

	u64 part_2_ans {};
	for (szt i {}; i < 9; ++i) {
		part_2_ans += fish_arr[i];
	}

	std::cout << "Number of fish after " << num_days_part_2 << " is " << part_2_ans << ".\n";

	time_end = timer.mark();
	std::cout << "Time: " << time_end * 1000.f << "ms\n";
}
