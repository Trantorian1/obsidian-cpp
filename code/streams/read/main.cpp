#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int	main(void) {
	std::ifstream	file;
	std::string		line;

	file.open("./poem.txt");
	if (file.is_open() == false)
		return (EXIT_FAILURE);

	// priting as long as file still has lines
	while (file.eof() == false) {
		std::getline(file, line);
		std::cout << line << '\n';
	}

	file.close();

	return (EXIT_SUCCESS);
}
