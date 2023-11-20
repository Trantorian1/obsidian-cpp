#include <cstdlib>
#include <iterator>
#include <iostream>

void	put(int array[]) {}

int main (int argc, char *argv[])
{
	int	array[] = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
		std::cout << array[i] << std::endl;

	int	matrix[2][3] = {
		{ 1, 2, 3},
		{ 4, 5, 6}
	};

	return EXIT_SUCCESS;
}
