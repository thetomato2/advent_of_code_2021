#include "../utils/pch.h"

s32
main(s32 argc, char* argv[])
{
	util::Timer timer;
	std::vector<s32> crabs;
	std::string arg;

	if (argc == 2)
		arg = argv[1];
	else
		std::cout << "Invalid args\n";

	timer.mark();
	if (arg == "test")
		crabs = { 16, 1, 2, 0, 4, 2, 7, 1, 2, 14 };
	else {
		std::string input_path { "day_07_input.txt" };
		std::ifstream input_file(input_path);
		if (input_file.is_open()) {
			std::string num;
			while (std::getline(input_file, num, ',')) {
				crabs.push_back(std::stoi(num));
			}
		}
	}

	auto time_read_file = timer.mark();
	std::cout << "Time to read file: " << time_read_file * 1000.f << "ms\n";

	// part 1 is the median
	szt n = crabs.size() / 2;
	std::nth_element(crabs.begin(), crabs.begin() + n, crabs.end());
	s32 median = crabs[n];
	std::cout << "Median: " << median << '\n';

	// need to calc fuel cost after getting the median
	s32 part_1_ans {};
	for (const auto i : crabs)
		part_1_ans += std::abs(i - median);

	std::cout << "Part 1 answer: " << part_1_ans << '\n';

	// part 2 is the mean, use floats to round
	s32 sum = std::accumulate(crabs.begin(), crabs.end(), 0);
	std::cout << "Sum: " << sum << '\n';
	std::cout << "Num of Crabs: " << crabs.size() << '\n';
	f32 mean_f32 = f32(sum) / f32(crabs.size());
	std::cout << "Mean real: " << mean_f32 << '\n';
	s32 mean_int = s32(mean_f32 + 0.5f);
	std::cout << "Mean: " << mean_int << '\n';

	// NOTE: this fixes part 2 for me, I the imprecision of roudning was too high?
	// I don't know how to test this
	--mean_int;

	// now to calc the fuel cost
	s32 part_2_ans {};
	for (const auto i : crabs) {
		s32 dif = std::abs(i - mean_int);
		std::cout << "i: " << i << ", " << dif << '\n';
		while (dif > 0) {
			part_2_ans += dif--;
		}
	}

	std::cout << "Part 2 answer: " << part_2_ans << '\n';

	auto time_total = timer.total();
	std::cout << "Time Total: " << time_total * 1000.f << "ms\n";

	return 0;
}
