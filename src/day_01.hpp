
#ifndef DAY_01_H_
#define DAY_01_H_
#include "../utils/pch.h"

namespace day01
{
std::vector<i32>
read_input_file(std::string input_path);

i32
do_part_01(std::vector<i32>& input);

i32
do_part_02(std::vector<i32>& input);

}  // namespace day01

#endif	// DAY_01_H_
