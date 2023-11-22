#include <iostream>
#include <fstream>
#include <cstdlib>
#include <istream>
#include <string>

int	main(void) {
	std::ifstream	file;
	int				n;

	file.open("data.dat");
	if (file.is_open() == false)
		return (EXIT_FAILURE);

	while (true) {
		file.read(reinterpret_cast<char *>(&n), sizeof(n));

		// 'file.read' mutates 'file.eof()'
		// so the check needs to happen here
		if (file.eof() == true)
			break;

		std::cout << n << std::endl;
	}

	return (EXIT_SUCCESS);
}
