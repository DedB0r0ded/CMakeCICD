#include "Entity.h"

int Entity::takeDamage(int damage)
{
  return damage;
}

int Entity::getHeal(int healValue)
{
  return 0;
}

int Entity::takeDamageIf(const int damage, bool(*assertion)())
{
  if (assertion())
    return takeDamage(damage);
  else
    return 0;
}
