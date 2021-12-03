#include "../utils/pch.h"

// NOTE: helper struct
struct Move
{
	enum class Direction
	{
		up,
		down,
		forward
	};

	Move(std::string& direction, s32 units)
	{
		units_ = units;

		// NOTE: C++ doesn't like using switches on string literals,
		// otherwise I would just pass a char pointer
		if (direction == "up") {
			direction_ = Direction::up;
		} else if (direction == "down") {
			direction_ = Direction::down;
		} else if (direction == "forward") {
			direction_ = Direction::forward;
		} else {
			std::cout << "ERROR->Failed to parse Direction!\n";
		}
	}

	Direction direction_;
	s32 units_;
};

s32
main()
{
	std::string input_path { "day_02_input.txt" };
	std::ifstream input_file(input_path);
	std::vector<Move> moves;

	std::string line;
	if (input_file.is_open()) {
		while (std::getline(input_file, line)) {
			auto direction = line.substr(0, line.find(' '));
			line.erase(0, line.find(' ') + 1);
			s32 unit = std::stoi(line);
			moves.emplace_back(direction, unit);
		}

	} else {
		std::cout << "Failed to open " << input_path << "!\n";
	}

	//========================================================
	// part 1
	//========================================================
	s32 pos_x {};  // horizontal
	s32 pos_y {};  // depth

	for (auto& move : moves) {
		switch (move.direction_) {
			case Move::Direction::up: {
				pos_y -= move.units_;
			} break;
			case Move::Direction::down: {
				pos_y += move.units_;
			} break;
			case Move::Direction::forward: {
				pos_x += move.units_;
			} break;
			default: break;
		}
	}

	std::cout << "Part 1\n";
	std::cout << "Horizontal: " << pos_x << ", Depth: " << pos_x << "\n product: " << pos_x * pos_y
			  << std::endl;

	//========================================================
	// part 2
	//========================================================
	pos_x = 0;
	pos_y = 0;
	s32 aim {};

	for (auto& move : moves) {
		switch (move.direction_) {
			case Move::Direction::up: {
				aim -= move.units_;
			} break;
			case Move::Direction::down: {
				aim += move.units_;
			} break;
			case Move::Direction::forward: {
				pos_x += move.units_;
				pos_y += move.units_ * aim;
			} break;
			default: break;
		}
	}

	f64 product = pos_x * pos_y;

	std::cout << "\nPart 1\n";
	std::cout << "Horizontal: " << pos_x << ", Depth: " << pos_y << "\n product: " << std::fixed
			  << product << std::endl;
}
