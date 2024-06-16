#pragma once
#include "IDamagable.h"
#include <functional>
#include <string>

class Entity : public IDamagable {

public:
  
  int takeDamage(int damage) override;
  int getHeal(int healValue) override;
  int takeDamageIf(const int damage, bool(*assertion)());
  std::string retstrIf(std::function<bool(void)> predicate);
};