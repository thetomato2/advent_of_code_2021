#include "day_08.hpp"

namespace day08
{

Puzzle
parse_line(const std::string& in)
{
	Puzzle result;
	bool past_delim = false;
	auto it			= in.begin();
	while (it != in.end()) {
		// read one number
		Display d = 0;
		while (it != in.end() && std::islower(*it)) {
			if (*it - 'a' > 7)
				throw std::out_of_range("Unexpected value in input, only accepts values 'a-g'.");
			d |= 1 << (*it - 'a');
			it++;
		}
		if (past_delim) {
			result.numbers.push_back(d);
		} else {
			result.patterns.push_back(d);
		}
		// skip over spaces and delimiter '|'
		while (it != in.end() && (std::isspace(*it) || *it == '|')) {
			if (*it == '|') past_delim = true;
			it++;
		}
	}
	return result;
}

std::vector<Puzzle>
read_input_file(std::string in_path)
{
	std::vector<Puzzle> result;
	std::ifstream input_file(in_path);
	if (input_file.is_open()) {
		std::string line;
		while (std::getline(input_file, line)) {
			auto puzzle = parse_line(line);
			result.push_back(puzzle);
		}
	}
	return result;
}

i32
do_part_01(std::vector<Puzzle>& in)
{
	i32 result {};
	for (auto p : in) {
		result += std::ranges::count_if(p.numbers, [](auto n) {
			u8 cnt = std::popcount(n);
			return cnt == 2 || cnt == 3 || cnt == 4 || cnt == 7;
		});
	}

	return result;
}

Wiring
solve_wiring(const Puzzle& input)
{
	Wiring result = { NUMBERS[8], NUMBERS[8], NUMBERS[8], NUMBERS[8],
					  NUMBERS[8], NUMBERS[8], NUMBERS[8] };
	for (auto pattern : input.patterns) {
		switch (cnt_segments(pattern)) {
			case 2:
				for (u8 wire_in = 0; wire_in < 7; wire_in++) {
					if (segment_lit(pattern, wire_in)) {
						result[wire_in] &= (SEGMENT_C | SEGMENT_F);
					} else {
						result[wire_in] &= ~(SEGMENT_C | SEGMENT_F);
					}
				}
				break;
			case 3:
				for (u8 wire_in = 0; wire_in < 7; wire_in++) {
					if (segment_lit(pattern, wire_in)) {
						result[wire_in] &= (SEGMENT_A | SEGMENT_C | SEGMENT_F);
					} else {
						result[wire_in] &= ~(SEGMENT_A | SEGMENT_C | SEGMENT_F);
					}
				}
				break;
			case 4:
				for (u8 wire_in = 0; wire_in < 7; wire_in++) {
					if (segment_lit(pattern, wire_in)) {
						result[wire_in] &= (SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_F);
					} else {
						result[wire_in] &= ~(SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_F);
					}
				}
				break;
			case 5:
				for (u8 wire_in = 0; wire_in < 7; wire_in++) {
					if (!segment_lit(pattern, wire_in)) {
						result[wire_in] &= (SEGMENT_B | SEGMENT_C | SEGMENT_E | SEGMENT_F);
					}
				}
				break;
			case 6:
				for (u8 wire_in = 0; wire_in < 7; wire_in++) {
					if (!segment_lit(pattern, wire_in)) {
						result[wire_in] &= (SEGMENT_C | SEGMENT_D | SEGMENT_E);
					}
				}
				break;
		}
	}
	for (auto singular_wire : result) {
		if (std::popcount(singular_wire) != 1) continue;

		for (auto& undecided_wire : result) {
			if (std::popcount(undecided_wire) == 1) continue;
			undecided_wire &= ~singular_wire;
		}
	}
	return result;
}

u32
decode_number(const Puzzle& puzzle, const Wiring& solved_wiring)
{
	u32 result = 0;
	for (auto digit : puzzle.numbers) {
		u8 display = 0;
		for (u8 bit = 0; bit < 7; ++bit) {
			if (segment_lit(digit, bit)) display |= solved_wiring[bit];
		}

		result *= 10;
		result += DECIMALS.at(display);
	}
	return result;
}

i32
do_part_02(std::vector<Puzzle>& in)
{
	i32 result;
	for (auto p : in) {
		Wiring w = solve_wiring(p);
		result += decode_number(p, w);
	}
	return result;
}

}  // namespace day08
