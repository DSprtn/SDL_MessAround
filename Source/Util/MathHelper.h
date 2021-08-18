#pragma once
class MathHelper
{
public:
	template <typename T>
	static T Clamp(const T& n, const T& lower, const T& upper) {
		return std::max(lower, std::min(n, upper));
	}
};

