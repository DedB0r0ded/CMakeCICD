#include "Component.h"

class HealthComponent : public Component{
  int m_maxHealth;
  int m_health;
  bool m_isDead;

  bool _updateIsDead();

public:
  HealthComponent(const int maxHealth = 0, const int health = 0);

  int takeDamage(const int damage);
  int heal(const int healValue);
  bool isDead() const;

  int getHealthPoints() const;
  int getMaxHealthPoints() const;
};