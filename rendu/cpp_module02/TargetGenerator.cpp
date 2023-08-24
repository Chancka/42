#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}

TargetGenerator::~TargetGenerator(){}

TargetGenerator::TargetGenerator(TargetGenerator &src){
	*this = src;
}

TargetGenerator &TargetGenerator::operator=(TargetGenerator &rhs) {
	_targetBook = rhs._targetBook;
	return(*this);
}

void TargetGenerator::learnTargetType(ATarget *target) {
	if (target)
		_targetBook[target->getType()] = target;
}

void TargetGenerator::forgetTargetType(const std::string &targetType) {
	if (_targetBook.find(targetType) != _targetBook.end())
		_targetBook.erase(_targetBook.find(targetType));
}

ATarget *TargetGenerator::createTarget(const std::string &targetType) {
	ATarget *tmp = NULL;
	if (_targetBook.find(targetType) != _targetBook.end())
		tmp = _targetBook[targetType];
	return tmp;
}
