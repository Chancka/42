#pragma once
#include <iostream>
#include "ASpell.hpp"
#include <map>
#include "SpellBook.hpp"

class Warlock{
public:
	Warlock(const std::string &_name, const std::string &_title);
	~Warlock();

	const std::string &getName() const;
	const std::string &getTitle() const;

	void setTitle(const std::string &title);
	void introduce() const;
	void learnSpell(ASpell *spell);
	void forgetSpell(std::string spell);
	void launchSpell(std::string spell, const ATarget &target);

private:
	Warlock();
	Warlock(Warlock &src);
	Warlock &operator=(Warlock &rhs);

	std::string _name;
	std::string _title;
	SpellBook _spellBook;
};
