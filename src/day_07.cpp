#include "../utils/pch.h"

s32
main()
{
	util::Timer timer;

	std::string input_path { "day_07_input.txt" };
	std::ifstream input_file(input_path);
	std::vector<s32> crabs;

	timer.mark();
	if (input_file.is_open()) {
		std::string num;
		while (std::getline(input_file, num, ',')) {
			std::cout << num << '\n';
			crabs.push_back(std::stoi(num));
		}
	}

	auto time_read_file = timer.mark();
	std::cout << "Time to read file: " << time_read_file * 1000.f << "ms\n";

	// timer.mark();
	// std::sort(crabs.begin(), crabs.end());
	// auto time_sort = timer.mark();
	// std::cout << "Time to sort: " << time_sort * 1000.f << "ms\n";

	for (const auto i : crabs) {
		std::cout << i << '\n';
	}

	auto time_total = timer.total();
	std::cout << "Time Total: " << time_total * 1000.f << "ms\n";
}
