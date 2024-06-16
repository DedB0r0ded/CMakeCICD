#pragma once
#include "./HealthComponent.h"

class IDamagable
{
public:
	virtual int takeDamage(int) = 0;
	virtual int getHeal(int) = 0;
	virtual int takeDamageIf(int, bool(*predicate)(void)) = 0;

protected:
	HealthComponent* m_health;

};
