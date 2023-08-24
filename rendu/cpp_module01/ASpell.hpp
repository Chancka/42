#pragma once
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell{
public:
	ASpell(const std::string &name, const std::string &effects);
	ASpell();
	virtual ~ASpell();
	ASpell(ASpell &src);
	ASpell &operator=(ASpell &rhs);

	virtual ASpell* clone() const = 0;
	const std::string &getName() const;
	const std::string &getEffects() const;
	void launch(const ATarget &target);
protected:
	std::string _name;
	std::string _effects;
};
