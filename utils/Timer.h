#pragma once
#include <chrono>

namespace util
{
class Timer
{
public:
	Timer();

	f32
	mark();

	f32
	peek() const;

	f32
	total() const;

private:
	std::chrono::steady_clock::time_point start_;
	std::chrono::steady_clock::time_point last_;
};
}  // namespace util
