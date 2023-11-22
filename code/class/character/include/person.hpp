#ifndef PERSON_H
# define PERSON_H

# include <iomanip>
# include <ostream>
# include <string>
# include <iostream>

class Person {
public:
	std::string		name;

	Person();
	Person(std::string name, unsigned short age, unsigned short height);
	Person(Person& person);
	~Person();
	Person&	operator=(Person& other);

	unsigned short	getAge(void) const;
	unsigned short	getHeight(void) const;
	void			setAge(unsigned short age);
	void			setHeight(unsigned short height);

	void			impersonate(Person& other);

private:
	unsigned short	_age;
	unsigned short	_height;
};

std::ostream&	operator<<(std::ostream& os, Person& person);

#endif
