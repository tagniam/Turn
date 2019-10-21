#include "../../include/EnemyTypes/Gremlin.h"

Gremlin::Gremlin() {
	name = "Gremlin";
	ExperienceAmount = 25;
	CoinsDrop = rand() % 40;
}

EnemyType Gremlin::GetType() {
	return etGremlin;
}

std::string Gremlin::GetIntro()
{
	return "Hihihihihi, want some fun ?";	
}



int Gremlin::ReturnDamage() {
	return 5 + rand() % 5;
}

int Gremlin::ReturnHealAmount() {
	return 3 + rand() % 8;
}


// similar to rolling a d20  : 0 is equal to rolling a d20 in D&D 1, 19 is equal to rolling a 20 
int Gremlin::ReturnRiskAttackDamage() {
	int selector = rand() % 20;
	switch (selector){
	case 0: 
		return 0;
		break;
	case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: 
		return 2;
		break;
	case 10:
		return 5 + rand() % 5;
		break;
	case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: 
		return 8 + rand() % 5;
		break;
	case 19:
		return 20;
		break;
	default:
		return 0;
		break;
	}
}

