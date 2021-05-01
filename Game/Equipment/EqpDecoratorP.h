/*
 * EqpDecoratorP.h
 *
 *  Created on: Apr 24, 2021
 *      Author: patrick
 */

#ifndef EQUIPMENT_EQPDECORATORP_H_
#define EQUIPMENT_EQPDECORATORP_H_

#include "Equipment.h"

class EqpDecoratorP : public Equipment
{
public:
	EqpDecoratorP(Equipment *eqp) : Equipment(*eqp), wrapped_eqp(eqp) {}
	virtual ~EqpDecoratorP() {}

	Equipment *get_wrapped() const { return wrapped_eqp; }
private:
	Equipment *wrapped_eqp;
};


class Sharp: public EqpDecoratorP
{
public:
	Sharp(Equipment *eqp) : EqpDecoratorP(eqp){}
	virtual ~Sharp() {}
	std::string description()
	{
		return "sharp " + get_wrapped()->description();
	}
	virtual std::map<int, float> get_additional()
	{
		map<int, float> additionals = get_wrapped()->get_additional();;
		additionals[STR] += 2;
		additionals[DMG] += 40;
		return additionals;
	}
};

class Perfect: public EqpDecoratorP
{
public:
	Perfect(Equipment *eqp) : EqpDecoratorP(eqp) {}

	virtual ~Perfect() {}
	std::string description()
	{
		return "Perfect " + get_wrapped()->description();
	}
	virtual std::map<int, float> get_additional()
	{
		map<int, float> additionals = get_wrapped()->get_additional();
		additionals[STR] += 20;
		additionals[AGI] += 20;
		additionals[DEX] += 20;
		additionals[DMG] += 400;
		additionals[ARMOR] += 400;
		return additionals;
	}
};


#endif /* EQUIPMENT_EQPDECORATORP_H_ */
