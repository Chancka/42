#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget{
public:
	ATarget(const std::string &type);
	ATarget();
	virtual ~ATarget();
	ATarget(ATarget &src);
	ATarget &operator=(ATarget &rhs);

	virtual ATarget* clone() const = 0;
	const std::string &getType() const;
	void getHitBySpell(ASpell const &spell) const;
protected:
	std::string _type;
};
