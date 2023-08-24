#include "SpellBook.hpp"

SpellBook::SpellBook(){}

SpellBook::~SpellBook(){}

SpellBook::SpellBook(SpellBook &src){
	*this = src;
}

SpellBook &SpellBook::operator=(SpellBook &rhs) {
	_spellBook = rhs._spellBook;
	return(*this);
}

void SpellBook::learnSpell(ASpell *spell) {
	if (spell) {
		_spellBook[spell->getName()] = spell;
	}
}

void SpellBook::forgetSpell(const std::string &spellName) {
	if (_spellBook.find(spellName) != _spellBook.end())
		_spellBook.erase(_spellBook.find(spellName));
}

ASpell *SpellBook::createSpell(const std::string &spellName) {
	ASpell *tmp = NULL;
	if (_spellBook.find(spellName) != _spellBook.end())
		tmp = _spellBook[spellName];
	return tmp;
}
