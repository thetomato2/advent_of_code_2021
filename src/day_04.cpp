#include "../utils/pch.h"
/*
 Basically storing a 2d array as a 1d array since its simpler and faster to just calculate the
 offsets into the desired square. Could also use a map of some sort to store if a space has been
 called or not, I just don't like std::std::map, it sucks.

 This is an very OOP design for simplicity, but its not ideal if you wanted to scale this up, a DOD
 approach would be needed. You would store the the arrays in contiguous data sets, not in each
 "board" object
 */

struct Board
{
	static constexpr szt size	  = 25;
	static constexpr szt row_size = 5;

	Board(std::vector<s32> board) : is_active(true)
	{
		m_board = board;
		m_drawn_numbers.assign(size, 0);
	}

	std::vector<s32> m_board;
	std::vector<s32> m_drawn_numbers;

	bool is_active;
};

void
check_board_has_numbers(Board& board, s32 n)
{
	for (szt i {}; i < Board::size; ++i) {
		if (board.m_board[i] == n) {
			board.m_drawn_numbers[i] = 1;
		}
	}
}

bool
check_board_for_win(std::vector<s32>& board)
{
	szt sz = Board::row_size;
	// check horizontal
	for (szt x {}; x < sz; ++x) {
		s32 xy = x * sz;
		if (std::accumulate(board.begin() + xy, board.begin() + xy + sz, 0) == 5) {
			return true;
		}
	}

	// check vertical
	for (szt y {}; y < sz; ++y) {
		if ((board[y] + board[y + 1 * sz] + board[y + 2 * sz] + board[y + 3 * sz] +
			 board[y + 4 * sz]) == 5) {
			return true;
		}
	}

	return false;
}

s32
main()
{
	std::string input_path { "day_04_input.txt" };
	std::ifstream input_file(input_path);

	// the drawn bingo numbers
	std::vector<s32> nums;
	std::vector<Board> boards;

	// NOTE: this was annoying to parse and is a reason I don't really like streams much.
	// you can check for with cin because it eats them. Like why? And if you use get line you can't
	// have it break on ',' and '\n'
	if (input_file.is_open()) {
		std::string line;
		std::getline(input_file, line);
		std::string n;
		for (auto c : line) {
			if (c == ',') {
				nums.push_back(std::stoi(n));
				n.clear();
			} else {
				n.push_back(c);
			}
		}
		n.clear();
		std::vector<s32> cur_board;

		while (std::getline(input_file, line)) {
			while (line.length() > 2) {
				n = line.substr(0, line.find(' '));
				line.erase(0, line.find(' ') + 1);
				if (!n.empty()) cur_board.push_back(std::stoi(n));
			}

			n = line;
			if (!n.empty()) cur_board.push_back(std::stoi(n));
			if (cur_board.size() == 25) {
				boards.emplace_back(cur_board);
				cur_board.clear();
			}
		}

	} else {
		std::cout << "Failed to open " << input_path << "!\n";
	}

	//========================================================
	// part 1 and part2
	//========================================================

	// the first 4 numbers cannot win so we skip checking them
	szt i {};
	for (; i < 4; ++i) {
		for (auto& board : boards) {
			check_board_has_numbers(board, nums[i]);
		}
	}

	// NOTE: Part 2 is very easy, we just store a pointer to the winning board and store if a board
	// has won. No reason to repeat code here, just make a lambda

	auto get_board_sum = [](Board& board) {
		s32 sum {};
		for (szt j {}; j < Board::size; ++j) {
			if (board.m_drawn_numbers[j] == 0) sum += board.m_board[j];
		}
		return sum;
	};

	Board* last_winner_ptr { nullptr };
	s32 last_winner_num;

	bool is_part1_over = false;
	for (; i < nums.size(); ++i) {
		for (auto& board : boards) {
			if (!board.is_active) continue;
			check_board_has_numbers(board, nums[i]);
			if (check_board_for_win(board.m_drawn_numbers)) {
				if (!is_part1_over) {
					s32 part_1_sum = get_board_sum(board);
					s32 part_1_ans = part_1_sum * nums[i];
					std::cout << "Part 1 answer: " << part_1_ans << std::endl;
					is_part1_over = true;
				}
				board.is_active = false;
				last_winner_num = nums[i];
				last_winner_ptr = &board;
			}
		}
	}

	s32 part_2_sum = get_board_sum(*last_winner_ptr);
	s32 part_2_ans = part_2_sum * last_winner_num;
	std::cout << "Part 2 answer: " << part_2_ans << std::endl;
}
