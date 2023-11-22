#include <cstdlib>
#include <iostream>
#include <fstream>

int	main(void) {
	std::ofstream	file;

	file.open("lorem_ipsum.txt");
	if (file.is_open() == false)
		return (EXIT_FAILURE);

	// Using `\n` to avoid unecessary buffer flushes
	file << "Lorem Ipsum dolor si amet\n"
		 << "consectetur adipiscing elit\n";

	file.close();

	return (EXIT_SUCCESS);
}
