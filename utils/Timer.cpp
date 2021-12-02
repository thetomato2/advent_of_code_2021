#include "timer.h"

namespace util
{
Timer::Timer()
{
	start_ = std::chrono::steady_clock::now();
	last_  = start_;
}

float
Timer::mark()
{
	const auto old								 = last_;
	last_										 = std::chrono::steady_clock::now();
	const std::chrono::duration<float> frameTime = last_ - old;
	return frameTime.count();
}

float
Timer::peek() const
{
	return std::chrono::duration<float>(std::chrono::steady_clock::now() - last_).count();
}

float
Timer::total() const
{
	return std::chrono::duration<float>(std::chrono::steady_clock::now() - start_).count();
}

}  // namespace util
