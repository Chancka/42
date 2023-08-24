#pragma once
#include <iostream>
#include "ASpell.hpp"
#include <map>

class SpellBook{
public:
	SpellBook();
	virtual ~SpellBook();

	void learnSpell(ASpell *spell);
	void forgetSpell(const std::string &spellName);
	ASpell *createSpell(const std::string &spellName);
private:
	SpellBook &operator=(SpellBook &rhs);
	SpellBook(SpellBook &src);
	std::map <std::string, ASpell *> _spellBook;
};
