#include "../utils/pch.h"

struct Point
{
	Point() : x(0), y(0) {}
	Point(i32 p_x, i32 p_y) : x(p_x), y(p_y) {}

	i32 x;
	i32 y;
};

struct Line
{
	Point p1;
	Point p2;
};

i32
main()
{
	std::string input_path { "day_05_input.txt" };
	std::ifstream input_file(input_path);
	std::vector<Line> vents;

	util::Timer timer;

	timer.mark();
	if (input_file.is_open()) {
		std::string line;
		while (std::getline(input_file, line)) {
			Line cur_vent;
			i32 i {};
			std::string cur_point;
			while (line[i] != ',') {
				cur_point.push_back(line[i]);
				++i;
			}
			cur_vent.p1.x = std::stoi(cur_point);
			cur_point.clear();
			++i;
			while (line[i] != ' ') {
				cur_point.push_back(line[i]);
				++i;
			}
			cur_vent.p1.y = std::stoi(cur_point);
			cur_point.clear();
			i += 4;
			while (line[i] != ',') {
				cur_point.push_back(line[i]);
				++i;
			}
			cur_vent.p2.x = std::stoi(cur_point);
			cur_point.clear();
			++i;
			while (i < line.length()) {
				cur_point.push_back(line[i]);
				++i;
			}
			cur_vent.p2.y = std::stoi(cur_point);
			vents.push_back(cur_vent);
		}
	} else {
		std::cout << "Failed to open " << input_path << "!\n";
	}
	auto time_to_read_file = timer.mark();

	i32 vent_graph[1000][1000] {};

	timer.mark();
	for (const auto& vent : vents) {
		// std::cout << vent.p1.m_x << ", " << vent.p1.y< " -> " << vent.p2.m_x << ", "
		// 		  << vent.p2.m_y << '\n';

		//========================================================
		// part 1
		//========================================================
		// check only the straight vents
		if (vent.p1.x == vent.p2.x) {
			i32 x = vent.p1.x;
			if (vent.p1.y < vent.p2.y) {
				for (i32 y { vent.p1.y }; y <= vent.p2.y; ++y) {
					++vent_graph[x][y];
				}
			} else {
				for (i32 y { vent.p1.y }; y >= vent.p2.y; --y) {
					++vent_graph[x][y];
				}
			}

		} else if (vent.p1.y == vent.p2.y) {
			i32 y = vent.p1.y;
			if (vent.p1.x < vent.p2.x) {
				for (i32 x { vent.p1.x }; x <= vent.p2.x; ++x) {
					++vent_graph[x][y];
				}
			} else {
				for (i32 x { vent.p1.x }; x >= vent.p2.x; --x) {
					++vent_graph[x][y];
				}
			}
		} else {
			//========================================================
			// part 2
			//========================================================
			// check diagonal vents
			i32 x { vent.p1.x };
			i32 y { vent.p1.y };
			if (vent.p1.x < vent.p2.x) {
				if (vent.p1.y < vent.p2.y) {
					while (x <= vent.p2.x && y <= vent.p2.y) {
						++vent_graph[x++][y++];
					}
				} else {
					while (x <= vent.p2.x && y >= vent.p2.y) {
						++vent_graph[x++][y--];
					}
				}
			} else {
				if (vent.p1.y < vent.p2.y) {
					while (x >= vent.p2.x && y <= vent.p2.y) {
						++vent_graph[x--][y++];
					}
				} else {
					while (x >= vent.p2.x && y >= vent.p2.y) {
						++vent_graph[x--][y--];
					}
				}
			}
		}
	}

	i32 ans {};

	for (i32 x {}; x < 1000; ++x) {
		for (i32 y {}; y < 1000; ++y) {
			if (vent_graph[x][y] > 1) ++ans;
		}
	}

	auto time_calc_vents = timer.mark();

	std::cout << "Part 1 & 2 answer: " << ans << std::endl;
	std::cout << "Timer to read file: " << time_to_read_file * 1000.f << "ms"
			  << "\nTime to calc vents: " << time_calc_vents * 1000.f << "ms" << std::endl;
}
