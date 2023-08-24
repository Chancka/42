#include "ATarget.hpp"

ATarget::ATarget(const std::string &type) {
	this->_type = type;
}

ATarget::~ATarget() {

}

ATarget::ATarget() {	

}

ATarget::ATarget(ATarget &src) {
	this->_type = src._type;
}

ATarget &ATarget::operator=(ATarget &rhs) {
	rhs._type = this->_type;
	return (rhs);
}

const std::string &ATarget::getType() const {
	return (this->_type);
}

void ATarget::getHitBySpell(ASpell const &spell) const {
	std::cout << this->_type << " has been " << spell.getEffects() << "!" << std::endl;
}
