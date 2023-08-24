#ifndef WARLOCK_HPP
#include <iostream>

class Warlock{
public:
	Warlock(const std::string &_name, const std::string &_title);
	~Warlock();

	const std::string &getName() const;
	const std::string &getTitle() const;

	void setTitle(const std::string &title);
	void introduce() const;
private:
	Warlock();
	Warlock(Warlock &src);
	Warlock &operator=(Warlock &rhs);

	std::string _name;
	std::string _title;
};

#endif
