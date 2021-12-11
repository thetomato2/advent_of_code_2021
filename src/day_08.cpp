#include "../utils/pch.h"

struct Signal
{
	std::vector<std::string> signal_patterns;
	std::vector<std::string> output;
};

s32
main(s32 argc, char* argv[])
{
	util::Timer timer;
	std::vector<Signal> signals;
	std::string arg;
	bool using_test_case = false;

	if (argc == 2)
		arg = argv[1];
	else if (argc == 0 || argc == 1)
		std::cout << "no args";
	else
		std::cout << "Invalid args\n";

	timer.mark();

	if (arg == "test") using_test_case = true;

	if (using_test_case) {
		// NOTE: add test case here
		{
			Signal signal;
			signal.signal_patterns = { "be",	"cfbegad", "cbdgef", "fgaecd", "cgeb",
									   "fdcge", "agebfd",  "fecdb",	 "fabcd",  "edb" };
			signal.output		   = { "fdgacbe", "cefdb", "cefbgd", "gcbe" };
			signals.push_back(signal);
		}

		{
			Signal signal;
			signal.signal_patterns = { "edbfga", "begcd",  "cbg",	"gc",	  "gcadebf",
									   "fbgde",	 "acbgfd", "abcde", "gfcbed", "gfec" };
			signal.output		   = { "fcgedb", "cgb", "dgebacf", "gc" };
			signals.push_back(signal);
		}

		{
			Signal signal;
			signal.signal_patterns = { "fgaebd", "cg",	  "bdaec", "gdafb", "agbcfd",
									   "gdcbef", "bgcad", "gfac",  "gcb",	"cdgabef" };
			signal.output		   = { "cg", "cg", "fdcagb", "cbg" };
			signals.push_back(signal);
		}

		{
			Signal signal;
			signal.signal_patterns = { "fbegcd", "cbd",	  "adcefb", "dageb",  "afcb",
									   "bc",	 "aefdc", "ecdab",	"fgdeca", "fcdbega" };
			signal.output		   = { "efabcd", "cedba", "gadfec", "cb" };
			signals.push_back(signal);
		}

		{
			Signal signal;
			signal.signal_patterns = { "aecbfdg", "fbg",   "gf",	 "bafeg",  "dbefa",
									   "fcge",	  "gcbea", "fcaegb", "dgceab", "fcbdga" };
			signal.output		   = { "gecf", "egdcabf", "bgf", "bfgea" };
			signals.push_back(signal);
		}

		{
			Signal signal;
			signal.signal_patterns = { "fgeab", "ca",	"afcebg", "bdacfeg", "cfaedg",
									   "gcfdb", "baec", "bfadeg", "bafgc",	 "acf" };
			signal.output		   = { "gebdcfa", "ecba", "ca", "fadegcb" };
			signals.push_back(signal);
		}

		{
			Signal signal;
			signal.signal_patterns = { "dbcfg",	 "fgd",	  "bdegcaf", "fgec",   "aegbdf",
									   "ecdfab", "fbedc", "dacgb",	 "gdcebf", "gf" };
			signal.output		   = { "cefg", "dcbef", "fcge", "gbcadfe" };
			signals.push_back(signal);
		}

		{
			Signal signal;
			signal.signal_patterns = { "bdfegc", "cbegaf", "gecbf", "dfcage",  "bdacg",
									   "ed",	 "bedf",   "ced",	"adcbefg", "gebcd" };
			signal.output		   = { "ed", "bcgafe", "cdgba", "cbgef" };
			signals.push_back(signal);
		}
		{
			Signal signal;
			signal.signal_patterns = { "egadfb",  "cdbfeg", "cegd",	  "fecab", "cgb",
									   "gbdefca", "cg",		"fgcdab", "egfdb", "bfceg" };
			signal.output		   = { "gbdfcae", "bgc", "cg", "cgb" };
			signals.push_back(signal);
		}
		{
			Signal signal;
			signal.signal_patterns = { "gcafb",	 "gcf",	 "dcaebfg", "ecagb", "gf",
									   "abcdeg", "gaef", "cafbge",	"fdbac", "fegbdc" };
			signal.output		   = { "fgae", "cfgab", "fg", "bagce" };
			signals.push_back(signal);
		}

	} else {
		std::string input_path { "day_08_input.txt" };
		std::ifstream input_file(input_path);
		if (input_file.is_open()) {
			std::string line;
			while (std::getline(input_file, line)) {
				Signal signal;
				std::istringstream iss(line);
				// std::cout << iss.str() << '\n';

				std::string cur_str;
				while (iss >> cur_str) {
					if (cur_str == "|") break;
					signal.signal_patterns.push_back(cur_str);
				}
				while (iss >> cur_str) {
					signal.output.push_back(cur_str);
				}
				signals.push_back(signal);
			}
		}
	}

	auto time_read_file = timer.mark();
	std::cout << "Time to read file: " << time_read_file * 1000.f << "ms\n";

	// for (auto signal : signals) {
	// 	std::cout << i++ << ": ";
	// 	for (auto sig_pat : signal.signal_patterns) {
	// 		std::cout << sig_pat << ' ';
	// 	}
	// 	std::cout << "| ";
	// 	for (auto output : signal.output) {
	// 		std::cout << output << " ";
	// 	}
	// 	std::cout << '\n';
	// }

	// part 1 is simple, because 1, 4 ,7, and 8 are unique
	s32 part_1_answer {};

	//==========================================================================
	// PART 1
	//==========================================================================
	int i {};
	for (auto signal : signals) {
		std::cout << i++ << ": ";
		for (auto output : signal.output) {
			if (output.length() == 2 || output.length() == 3 || output.length() == 4 ||
				output.length() == 7) {
				++part_1_answer;
				std::cout << part_1_answer << " - " << output << "   ";
			}
		}
		std::cout << '\n';
	}

	std::cout << "Part 1 ans: " << part_1_answer << '\n';

	if (using_test_case) {
		if (part_1_answer == 26)
			std::cout << "Passed Test Case!\n";
		else
			std::cout << "Failed Test Case!\n";
	}

	//==========================================================================
	// PART 2
	//==========================================================================

	auto time_total = timer.total();
	std::cout << "Time Total: " << time_total * 1000.f << "ms\n";

	return 0;
}
