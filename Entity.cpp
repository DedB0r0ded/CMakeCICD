#include "Entity.h"
#include <iostream>

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
  std::cout << retstrIf(assertion);
  if (assertion()) {
    return takeDamage(damage);
  }
  else
    return 0;
}

std::string Entity::retstrIf(std::function<bool(void)> predicate)
{
  if (predicate())
    return std::string("I am a string!");
  else
    return std::string("I am not a string!");
}
