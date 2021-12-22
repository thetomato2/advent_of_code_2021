#ifndef DAY_08_H_
#define DAY_08_H_

#include "../utils/pch.h"

namespace day08
{

using Display = u8;

constexpr const Display SEGMENT_A = 1;
constexpr const Display SEGMENT_B = 1 << 1;
constexpr const Display SEGMENT_C = 1 << 2;
constexpr const Display SEGMENT_D = 1 << 3;
constexpr const Display SEGMENT_E = 1 << 4;
constexpr const Display SEGMENT_F = 1 << 5;
constexpr const Display SEGMENT_G = 1 << 6;

constexpr const std::array<Display, 10> NUMBERS = {
	SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_E | SEGMENT_F | SEGMENT_G,				// 0
	SEGMENT_C | SEGMENT_F,																// 1
	SEGMENT_A | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_G,							// 2
	SEGMENT_A | SEGMENT_C | SEGMENT_D | SEGMENT_F | SEGMENT_G,							// 3
	SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_F,										// 4
	SEGMENT_A | SEGMENT_B | SEGMENT_D | SEGMENT_F | SEGMENT_G,							// 5
	SEGMENT_A | SEGMENT_B | SEGMENT_D | SEGMENT_E | SEGMENT_F | SEGMENT_G,				// 6
	SEGMENT_A | SEGMENT_C | SEGMENT_F,													// 7
	SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_F | SEGMENT_G,	// 8
	SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_F | SEGMENT_G,				// 9
};

struct Puzzle
{
	std::vector<Display> patterns;
	std::vector<Display> numbers;
};

using Wiring = std::array<u8, 7>;

inline const std::unordered_map<Display, u8> DECIMALS = {
	{ NUMBERS[0], 0 }, { NUMBERS[1], 1 }, { NUMBERS[2], 2 }, { NUMBERS[3], 3 }, { NUMBERS[4], 4 },
	{ NUMBERS[5], 5 }, { NUMBERS[6], 6 }, { NUMBERS[7], 7 }, { NUMBERS[8], 8 }, { NUMBERS[9], 9 }
};

inline bool
segment_lit(Display disp, u8 segment)
{
	return disp & (1 << segment);
}

inline u8
cnt_segments(Display display)
{
	return std::popcount(display);
}

uint32_t
decode_number(const Puzzle& puzzle, const Wiring& solved_wiring);

Wiring
solve_wiring(const Puzzle& input);

Wiring
solve_wiring(const Puzzle&);
uint32_t
decode_number(const Puzzle&, const Wiring&);

Puzzle
parse_line(const std::string& in);

std::vector<Puzzle>
read_input_file(std::string input_path);

i32
do_part_01(std::vector<Puzzle>& input);

i32
do_part_02(std::vector<Puzzle>& input);

}  // namespace day08

#endif	// DAY_08_H_
