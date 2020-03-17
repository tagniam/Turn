#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity {
public:
	Entity();
	std::string GetName();
	virtual int Action() = 0;
	void TakeDamage(int);
	bool IsDead();

protected:
	virtual int GenericAttack() = 0;
	virtual int RiskAttack() = 0;
	void Heal();
	
	virtual int ReturnDamage() = 0;
	virtual int ReturnRiskAttackDamage() = 0;
	virtual int ReturnHealAmount() = 0;

	void DisplayHealthBar();

	std::string name;
	int health;
};

#endif // ENTITY_H

