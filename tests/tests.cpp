#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../src/day_01.hpp"
#include "../src/day_08.hpp"

TEST_CASE("Day_01 part 01 test", "[day_01][part_01]")
{
	auto v	 = day01::read_input_file("./day_01_test_input.txt");
	auto res = day01::do_part_01(v);
	REQUIRE(res == 7);
}

TEST_CASE("Day_01 part 02 test", "[day_01][part_02]")
{
	auto v	 = day01::read_input_file("./day_01_test_input.txt");
	auto res = day01::do_part_02(v);
	REQUIRE(res == 5);
}

TEST_CASE("Day_08 part 01 test", "[day_08][part_01]")
{
	auto v	 = day08::read_input_file("./day_08_test_input.txt");
	auto res = day08::do_part_01(v);
	REQUIRE(res == 26);
}

TEST_CASE("Day_08 part 02 test", "[day_08][part_02]")
{
	auto v	 = day08::read_input_file("./day_08_test_input.txt");
	auto res = day08::do_part_02(v);
	REQUIRE(res == 61229);
}
