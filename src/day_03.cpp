#include "../utils/pch.h"

i32
main()
{
	std::string input_path { "day_03_input.txt" };
	std::ifstream input_file(input_path);
	std::vector<std::string> bin_num_strs;

	std::string line;
	if (input_file.is_open()) {
		while (std::getline(input_file, line)) {
			bin_num_strs.push_back(line);
		}
	} else {
		std::cout << "Failed to open " << input_path << "!\n";
	}

	//========================================================
	// part 1
	//========================================================

	szt len	 = bin_num_strs[0].length();
	szt half = bin_num_strs.size() / 2;
	std::string gamma_bin_str, epsilon_bin_str;

	for (szt i {}; i < len; ++i) {
		i32 bit_cnt {};
		for (auto& bin_num_str : bin_num_strs) {
			if (bin_num_str[i] == '1') bit_cnt++;
		}

		if (bit_cnt > half) {
			gamma_bin_str.push_back('1');
			epsilon_bin_str.push_back('0');
		} else {
			gamma_bin_str.push_back('0');
			epsilon_bin_str.push_back('1');
		}
	}

	i32 gamma_s32	= std::stoi(gamma_bin_str, nullptr, 2);
	i32 epislon_s32 = std::stoi(epsilon_bin_str, nullptr, 2);

	i32 part_1_ans = gamma_s32 * epislon_s32;

	std::cout << "Answer to part 1: " << part_1_ans << std::endl;

	//========================================================
	// part 2
	//========================================================

	auto oxygen_list = bin_num_strs;
	auto c02_list	 = bin_num_strs;

	// NOTE: you could pull this out into a function or lamba buts barely any less code
	for (i32 i {}; i < len; ++i) {
		if (oxygen_list.size() == 1) break;
		i32 bit_cnt {};
		for (auto& bin_str : oxygen_list) {
			if (bin_str[i] == '1') ++bit_cnt;
		}

		if (bit_cnt >= oxygen_list.size() / 2) {
			std::erase_if(oxygen_list, [i](std::string str) { return str[i] == '0'; });
		} else {
			std::erase_if(oxygen_list, [i](std::string str) { return str[i] == '1'; });
		}
	}

	for (i32 i {}; i < len; ++i) {
		if (c02_list.size() == 1) break;
		i32 bit_cnt {};
		for (auto& bin_str : c02_list) {
			if (bin_str[i] == '0') ++bit_cnt;
		}

		if (bit_cnt <= c02_list.size() / 2) {
			std::erase_if(c02_list, [i](std::string str) { return str[i] == '1'; });
		} else {
			std::erase_if(c02_list, [i](std::string str) { return str[i] == '0'; });
		}
	}

	i32 part_2_ans = std::stoi(oxygen_list[0], nullptr, 2) * std::stoi(c02_list[0], nullptr, 2);

	std::cout << "Answer to part 2: " << part_2_ans << std::endl;
}
