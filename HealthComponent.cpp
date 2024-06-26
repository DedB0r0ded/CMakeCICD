#include "HealthComponent.h"

bool HealthComponent::_updateIsDead()
{
  if (m_health > 0)
    m_isDead = false;
  else
    m_isDead = true;

  return m_isDead;
}

HealthComponent::HealthComponent(const int maxHealth, const int health) : m_maxHealth{ maxHealth }, m_health { health }, m_isDead{ false }
{
  if (maxHealth < 0)
    m_maxHealth = 0;
  if (health < 0)
    m_health = 0;

  if (m_health > m_maxHealth)
    m_health = m_maxHealth;

  _updateIsDead();
}

HealthComponent::HealthComponent(const int maxHealth)
  : HealthComponent(maxHealth, maxHealth)
{
}

HealthComponent::HealthComponent()
  : HealthComponent(0, 0)
{
}

int HealthComponent::takeDamage(const int damage)
{
  int appliedDamage;
  
  if (m_health - damage > 0)
    appliedDamage = damage;
  else
    appliedDamage = m_health;
  
  m_health -= appliedDamage;
  _updateIsDead();

  return appliedDamage;
}

int HealthComponent::getHeal(const int healValue)
{
  int appliedHeal;

  if (healValue <= 0)
    return 0;

  if (healValue <= m_maxHealth - m_health)
    appliedHeal = healValue;
  else
    appliedHeal = m_maxHealth - m_health;

  m_health += appliedHeal;
  _updateIsDead();

  return appliedHeal;
}

bool HealthComponent::isDead() const
{
  return m_isDead;
}

int HealthComponent::getHealthPoints() const
{
  return m_health;
}

int HealthComponent::getMaxHealthPoints() const
{
  return m_maxHealth;
}
