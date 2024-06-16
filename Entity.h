#pragma once
#include "IDamagable.h"

class Entity : public IDamagable {

public:
  
  int takeDamage(int damage) override;
  int getHeal(int healValue) override;
  int takeDamageIf(const int damage, bool(*assertion)());

};