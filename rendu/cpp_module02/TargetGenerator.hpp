#pragma once
#include <iostream>
#include <map>
#include "ATarget.hpp"

class TargetGenerator{
public:
	TargetGenerator();
	virtual ~TargetGenerator();

	void learnTargetType(ATarget *target);
	void forgetTargetType(const std::string &targetType);
	ATarget *createTarget(const std::string &targetType);
private:
	TargetGenerator &operator=(TargetGenerator &rhs);
	TargetGenerator(TargetGenerator &src);
	std::map<std::string, ATarget*> _targetBook;
};
