#include "ASpell.hpp"

ASpell::ASpell(const std::string &name, const std::string &effects) {
	this->_name = name;
	this->_effects = effects;
}

ASpell::~ASpell() {

}

ASpell::ASpell() {

}

ASpell::ASpell(ASpell &src) {
	this->_name = src._name;
	this->_effects = src._effects;
}

ASpell &ASpell::operator=(ASpell &rhs) {
	rhs._name = this->_name;
	rhs._effects = this->_effects;
	return (rhs);
}

const std::string &ASpell::getName() const {
	return (this->_name);
}

const std::string &ASpell::getEffects() const {
	return (this->_effects);
}

void ASpell::launch(const ATarget &target) {
	target.getHitBySpell(*this);
}
