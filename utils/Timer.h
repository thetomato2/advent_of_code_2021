#pragma once
#include <chrono>

namespace util
{
class Timer
{
public:
	Timer();
	float mark();
	float peek() const;
	float total() const;

private:
	std::chrono::steady_clock::time_point start_;
	std::chrono::steady_clock::time_point last_;
};
}  // namespace utils
