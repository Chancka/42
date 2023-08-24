#include "Warlock.hpp"

Warlock::Warlock(const std::string &_name, const std::string &_title) {
	this->_name = _name;
	this->_title = _title;
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::cout << this->_name << ": My job here is done!" << std::endl;
}

Warlock::Warlock() {

}

Warlock::Warlock(Warlock &src) {
	*this = src;
}

const std::string &Warlock::getName() const {
	return(this->_name);
}

const std::string &Warlock::getTitle() const {
	return(this->_title);
}

void Warlock::setTitle(const std::string &title) {
	this->_title = title;
}

void Warlock::introduce() const {
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}

Warlock & Warlock::operator=(Warlock &rhs) {
	rhs._name = this->_name;
	rhs._title = this->_title;
	return (rhs);
}

void Warlock::learnSpell(ASpell *spell) {
	_spellBook.learnSpell(spell);
}

void Warlock::forgetSpell(std::string spell) {
	_spellBook.forgetSpell(spell);
}

void Warlock::launchSpell(std::string spell, const ATarget &target) {
	if (_spellBook.createSpell(spell)) {
		_spellBook.createSpell(spell)->launch(target);
	}
}
