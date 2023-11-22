#include "person.hpp"

#include <cstdlib>
#include <iostream>

int	main(void) {
	Person	trantorian("Trantorian", 42, 190);

	std::cout << trantorian << std::endl;

	return (EXIT_SUCCESS);
}
