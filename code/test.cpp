#include <iostream>

int main (int argc, char *argv[])
{
	std::string fullName = "Trantorian 1";
	std::string firstName = fullName.substr(0, 10);

	std::cout << '\'' << firstName << '\'' << std::endl;
}
