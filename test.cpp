#include <cstdlib>
#include <iterator>
#include <iostream>

template<class T, std::size_t N>
constexpr std::size_t size(const T (&array)[N]) noexcept
{
    return N;
}

int main (int argc, char *argv[])
{
	int	array[] = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < std::size(array); i++)


	return EXIT_SUCCESS;
}
