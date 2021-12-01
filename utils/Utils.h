#pragma once

namespace util
{

// custom std::format print
template<typename... Args>
std::string fmtL(std::string_view rt_fmt_str, Args&&... args)
{
	return std::vformat(rt_fmt_str, std::make_format_args(args...)) + '\n';
}

template<typename... Args>
std::string fmt(std::string_view rt_fmt_str, Args&&... args)
{
	return std::vformat(rt_fmt_str, std::make_format_args(args...));
}

}  // namespace utils