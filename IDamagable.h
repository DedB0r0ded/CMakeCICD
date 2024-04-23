#include "./HealthComponent.h"

class IDamagable
{
public:
	virtual int getDamage(int) = 0;
	virtual int getHeal(int) = 0;
	virtual ~IDamagable() = 0;

protected:
	HealthComponent* m_health;

};
