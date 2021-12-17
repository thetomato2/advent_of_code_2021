
#include "../utils/pch.h"
#include "day_01.hpp"
#include "day_08.hpp"

void
do_day_08(i32 part = 0)
{
	auto v = day08::read_input_file("./day_08_input.txt");
	if (part == 0) {
		auto part_1 = day08::do_part_01(v);
		auto part_2 = day08::do_part_02(v);
		std::cout << "Part 1: " << part_1 << "\nPart 2: " << part_2 << '\n';
	} else if (part == 1) {
		auto part_1 = day08::do_part_01(v);
		std::cout << "Part 1: " << part_1 << '\n';
	} else if (part == 2) {
		auto part_2 = day08::do_part_02(v);
		std::cout << "\nPart 2: " << part_2 << '\n';
	}
}

void
do_day_01(i32 part = 0)
{
	auto nums = day01::read_input_file("./day_01_input.txt");
	if (part == 0) {
		auto part_1 = day01::do_part_01(nums);
		auto part_2 = day01::do_part_02(nums);
		std::cout << "Part 1: " << part_1 << "\nPart 2: " << part_2 << '\n';
	} else if (part == 1) {
		auto part_1 = day01::do_part_01(nums);
		std::cout << "Part 1: " << part_1 << '\n';
	} else if (part == 2) {
		auto part_2 = day01::do_part_02(nums);
		std::cout << "\nPart 2: " << part_2 << '\n';
	}
}

i32
main(i32 argc, char* argv[])
{
	std::vector<std::string> args;
	for (i32 i {}; i < argc; ++i) {
		args.emplace_back(argv[i]);
	}

	if (args.size() > 1 && args.size() < 4) {
		// day 01
		if (args[1] == "1") {
			if (args.size() == 2) {
				do_day_01(0);
			} else if (args.size() == 3) {
				if (args[2] == "1") {
					do_day_01(1);
				} else if (args[2] == "2") {
					do_day_01(2);
				}
			}
		}
		// day 08
		if (args[1] == "8") {
			if (args.size() == 2) {
				do_day_08(0);
			} else if (args.size() == 3) {
				if (args[2] == "1") {
					do_day_08(1);
				} else if (args[2] == "2") {
					do_day_08(2);
				}
			}
		}
	} else if (args.size() <= 1) {
		std::cout << "Need some args: int [day] , int [part] (optional)" << '\n';
	} else {
		std::cout << "Invalid args: int [day] , int [part] (optional)" << '\n';
	}

	return 0;
}
