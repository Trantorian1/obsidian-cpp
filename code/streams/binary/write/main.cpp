#include <iostream>
#include <fstream>
#include <cstdlib>

int	main(void) {
	std::ofstream	file;
	int				data[] = { 100, 200, 300 };

	file.open("data.dat");
	if (file.is_open() == false)
		return (EXIT_FAILURE);

	// we need to cast data to 'char *' to get 
	// it's representation in memory
	file.write(reinterpret_cast<char *>(data), sizeof(data));
	file.close();

	return (EXIT_SUCCESS);
}
