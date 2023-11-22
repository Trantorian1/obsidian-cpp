#include "person.hpp"
#include <ostream>

// ============================[ CONSTRUCTORS ]============================== //

Person::Person(): name(""), _age(0), _height(0) {}
Person::Person(std::string name, unsigned short age, unsigned short height):
	name(name), _age(age), _height(height) {}
Person::Person(Person& person): 
	name(person.name), _age(person._age), _height(person._height) {}

// =============================[ DESTRUCTOR ]=============================== //

Person::~Person() {}

// =============================[ OPERATORS ]================================ //

Person& Person::operator=(Person& other) {
	if (this != &other) {
		name = other.name;
		_age = other._age;
		_height = other._height;
	}
	return *this;
}

std::ostream&	operator<<(std::ostream& os, Person& person) {
	os << "[" << "name:" << person.name
	   << "," << "age:" << person.getAge()
	   << "," << "height:" << person.getHeight()
	   << "]";
	return (os);
}

// ==============================[ GETTERS ]================================= //

unsigned short	Person::getAge(void) const {
	return Person::_age;
}

unsigned short	Person::getHeight(void) const {
	return Person::_height;
}

// ==============================[ SETTERS ]================================= //

void	Person::setAge(unsigned short age) {
	if (age > 110)
		return;
	Person::_age = age;
}

void	Person::setHeight(unsigned short height) {
	if (height > 300)
		return;
	Person::_height = height;
}

// =============================[ FUNCTIONS ]================================ //

void	Person::impersonate(Person& other) {
	Person::name = other.name;
	Person::_age = other._age;
}
